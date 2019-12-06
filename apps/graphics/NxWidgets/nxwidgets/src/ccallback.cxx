/****************************************************************************
 * apps/graphics/NxWidgets/nxwidgets/src/ccallback.cxx
 *
 *   Copyright (C) 2012-2013, 2019 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX, NxWidgets, nor the names of its contributors
 *    me be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#ifdef CONFIG_NXTERM_NXKBDIN
#  include <sys/boardctl.h>
#endif

#include <stdint.h>
#include <stdbool.h>
#include <semaphore.h>
#include <debug.h>

#include <cassert>
#include <cerrno>

#include <nuttx/semaphore.h>
#include <nuttx/nx/nx.h>
#include <nuttx/nx/nxtk.h>

#include "graphics/nxwidgets/cwidgetcontrol.hxx"
#include "graphics/nxwidgets/ccallback.hxx"

/****************************************************************************
 * Pre-Processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Method Implementations
 ****************************************************************************/

using namespace NXWidgets;

 /**
  * Constructor.
  *
  * @param widgetControl Control object associated with this window
  */

CCallback::CCallback(CWidgetControl *widgetControl)
{
  // Save the widgetControl

  m_widgetControl      = widgetControl;

  // Initialize the callback vtable

  m_callbacks.redraw   = redraw;
  m_callbacks.position = position;
#ifdef CONFIG_NX_XYINPUT
  m_callbacks.mousein  = newMouseEvent;
#endif
#ifdef CONFIG_NX_KBD
  m_callbacks.kbdin    = newKeyboardEvent;
#endif
  m_callbacks.event    = windowEvent;

  // Synchronization support

  m_synchronized       = false;

  sem_init(&m_semevent, 0, 0);
  sem_setprotocol(&m_semevent, SEM_PRIO_NONE);

#ifdef CONFIG_NXTERM_NXKBDIN
  // Keyboard input is initially directed to the widgets within the window

  m_nxterm             = (NXTERM)0;
#endif
}

/**
 * Synchronize the window with the NX server.  This function will delay
 * until the the NX server has caught up with all of the queued requests.
 * When this function returns, the state of the NX server will be the
 * same as the state of the application.
 *
 * REVISIT:  An instance of this function is not re-entrant.
 *
 * @param hwnd Handle to a specific NX window.
 */

void CCallback::synchronize(NXWINDOW hwnd, enum WindowType windowType)
{
  m_synchronized = false;

  // Request synchronization.  Window type matters here because the void*
  // window handle will be interpreted differently.

  if (windowType == NX_RAWWINDOW)
    {
      int ret = nx_synch(hwnd, (FAR void *)this);
      if (ret < 0)
        {
          gerr("ERROR: nx_synch() failed: %d\n", errno);
          return;
        }
    }
  else
    {
      DEBUGASSERT(windowType == NXTK_FRAMEDWINDOW);

      int ret = nxtk_synch(hwnd, (FAR void *)this);
      if (ret < 0)
        {
          gerr("ERROR: nxtk_synch() failed: %d\n", errno);
          return;
        }
    }

  while (!m_synchronized)
    {
      int ret = sem_wait(&m_semevent);
      DEBUGASSERT(ret >= 0 || errno == EINTR);
      UNUSED(ret);
    }

  m_synchronized = false;
}

 /**
  * ReDraw Callback.  The redraw action is handled by CWidgetControl:redrawEvent.
  *
  * @param hwnd Handle to a specific NX window.
  * @param rect The rectangle that needs to be re-drawn (in window
  * relative coordinates).
  * @param bMore true: More re-draw requests will follow.
  * @param arg User provided argument (see nx_openwindow, nx_requestbg,
  * nxtk_openwindow, or nxtk_opentoolbar).
  */

void CCallback::redraw(NXHANDLE hwnd,
                       FAR const struct nxgl_rect_s *rect,
                       bool bMore, FAR void *arg)
{
  ginfo("hwnd=%p rect={(%d,%d),(%d,%d)} bMore=%s\n",
         hwnd,
         rect->pt1.x, rect->pt1.y, rect->pt2.x, rect->pt2.y,
         bMore ? "true" : "false");

  // The argument must be the CCallback instance

  CCallback *This = (CCallback *)arg;

  // Just forward the callback to the CWidgetControl::redrawEvent method

  This->m_widgetControl->redrawEvent(rect, bMore);
}

 /**
  * Position Callback. The new positional data is handled by
  * CWidgetControl::geometryEvent.
  *
  * @param hwnd Handle to a specific NX window.
  * @param size The size of the window.
  * @param pos The position of the upper left hand corner of the window on
  * the overall display.
  * @param bounds The bounding rectangle that describes the entire display.
  * @param arg User provided argument (see nx_openwindow, nx_requestbg,
  * nxtk_openwindow, or nxtk_opentoolbar).
  */

void CCallback::position(NXHANDLE hwnd,
                         FAR const struct nxgl_size_s *size,
                         FAR const struct nxgl_point_s *pos,
                         FAR const struct nxgl_rect_s *bounds,
                         FAR void *arg)
{
  ginfo("hwnd=%p size=(%d,%d) pos=(%d,%d) bounds={(%d,%d),(%d,%d)} arg=%p\n",
        hwnd, size->w, size->h, pos->x, pos->y,
        bounds->pt1.x, bounds->pt1.y, bounds->pt2.x, bounds->pt2.y,
        arg);

  // The argument must be the CCallback instance

  CCallback *This = (CCallback *)arg;

  // Just forward the callback to the CWidgetControl::geometry method

  This->m_widgetControl->geometryEvent(hwnd, size, pos, bounds);
}

#ifdef CONFIG_NX_XYINPUT
 /**
  * New mouse data is available for the window.  The new mouse data is
  * handled by CWidgetControl::newMouseEvent.
  *
  * @param hwnd Handle to a specific NX window.
  * @param pos The (x,y) position of the mouse.
  * @param buttons See NX_MOUSE_* definitions.
  * @param arg User provided argument (see nx_openwindow, nx_requestbg,
  * nxtk_openwindow, or nxtk_opentoolbar).
  */

void CCallback::newMouseEvent(NXHANDLE hwnd,
                              FAR const struct nxgl_point_s *pos,
                              uint8_t buttons, FAR void *arg)
{
  ginfo("hwnd=%p pos=(%d,%d) buttons=%02x arg=%p\n",
        hwnd, pos->x, pos->y, buttons, arg);

  // The argument must be the CCallback instance

  CCallback *This = (CCallback *)arg;

  // Just forward the callback to the CWidgetControl::newMouseEvent method

  This->m_widgetControl->newMouseEvent(pos, buttons);
}
#endif /* CONFIG_NX_XYINPUT */

#ifdef CONFIG_NX_KBD
/**
 * New keyboard/keypad data is available for the window.  The new keyboard
 * data is handled by CWidgetControl::newKeyboardEvent.
 *
 * @param hwnd Handle to a specific NX window.
 * @param nCh The number of characters that are available in str[].
 * @param str The array of characters.
 * @param arg User provided argument (see nx_openwindow, nx_requestbg,
 * nxtk_openwindow, or nxtk_opentoolbar).
 */

void CCallback::newKeyboardEvent(NXHANDLE hwnd, uint8_t nCh,
                                 FAR const uint8_t *str,
                                 FAR void *arg)
{
  ginfo("hwnd=%p nCh=%d arg=%p\n", hwnd, nCh, arg);

  // The argument must be the CCallback instance

  CCallback *This = (CCallback *)arg;

#ifdef CONFIG_NXTERM_NXKBDIN
  // Is NX keyboard input being directed to the widgets within the window
  // (default) OR is NX keyboard input being re-directed to an NxTerm
  // driver?

  if (This->m_nxterm)
    {
      struct boardioc_nxterm_kbdin_s kbdin;

      // Keyboard input is going to an NxTerm

      kbdin.handle = This->m_nxterm;
      kbdin.buffer = str;
      kbdin.buflen = nCh;

      (void)boardctl(BOARDIOC_NXTERM_KBDIN, (uintptr_t)&kbdin);
    }
  else
#endif
    {
      // Just forward the callback to the CWidgetControl::newKeyboardEvent method

      This->m_widgetControl->newKeyboardEvent(nCh, str);
    }
}

#endif // CONFIG_NX_KBD

/**
 *   This callback is used to communicate server events to the window
 *   listener.
 *
 *   NXEVENT_BLOCKED - Window messages are blocked.
 *
 *     This callback is the response from nx_block (or nxtk_block). Those
 *     blocking interfaces are used to assure that no further messages are
 *     directed to the window. Receipt of the blocked callback signifies
 *     that (1) there are no further pending callbacks and (2) that the
 *     window is now 'defunct' and will receive no further callbacks.
 *
 *     This callback supports coordinated destruction of a window.  In
 *     the multi-user mode, the client window logic must stay intact until
 *     all of the queued callbacks are processed.  Then the window may be
 *     safely closed.  Closing the window prior with pending callbacks can
 *     lead to bad behavior when the callback is executed.
 *
 *   NXEVENT_SYCNCHED - Synchronization handshake
 *
 *     This completes the handshake started by nx_synch().  nx_synch()
 *     sends a syncrhonization messages to the NX server which responds
 *     with this event.  The sleeping client is awakened and continues
 *     graphics processing, completing the handshake.
 *
 *     Due to the highly asynchronous nature of client-server
 *     communications, nx_synch() is sometimes necessary to assure that
 *     the client and server are fully synchronized.
 *
 * @param hwnd. Window handle of the blocked window
 * @param event. The server event
 * @param arg1. User provided argument (see nx_openwindow, nx_requestbkgd,
 *   nxtk_openwindow, or nxtk_opentoolbar)
 * @param arg2 - User provided argument (see nx[tk]_block or nx[tk]_synch)
 */

void CCallback::windowEvent(NXWINDOW hwnd, enum nx_event_e event,
                            FAR void *arg1, FAR void *arg2)
{
  ginfo("hwnd=%p devent=%d arg1=%p arg2=%p\n", hwnd, event, arg1, arg2);

  switch (event)
    {
      case NXEVENT_SYNCHED:  // Server is syncrhonized
        {
          // The second argument must be the CCallback instance

          CCallback *This = (CCallback *)arg2;
          DEBUGASSERT(This != NULL);

          // We are now syncrhonized

          This->m_synchronized = true;
          sem_post(&This->m_semevent);
        }
        break;

      case NXEVENT_BLOCKED:  // Window block, ready to be closed.
        {
          // The first argument must be the CCallback instance

          CCallback *This = (CCallback *)arg1;
          DEBUGASSERT(This != NULL);

          // Let the CWidgetControl::windowBlocked method handle the event.

          This->m_widgetControl->windowBlocked(arg2);
        }
        break;

      default:
        break;
    }
}
