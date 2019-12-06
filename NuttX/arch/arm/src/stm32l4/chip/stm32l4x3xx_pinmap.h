/************************************************************************************
 * arch/arm/src/stm32l4/chip/stm32l4x3xx_pinmap.h
 *
 *   Copyright (C) 2015-2016 Sebastien Lorquet. All rights reserved.
 *   Authors: Sebastien Lorquet <sebastien@lorquet.fr>
 *            Juha Niskanen <juha.niskanen@haltian.com>
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
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
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
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_STM32L4_CHIP_STM32L4X3XX_PINMAP_H
#define __ARCH_ARM_SRC_STM32L4_CHIP_STM32L4X3XX_PINMAP_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Alternate Pin Functions.  All members of the STM32L4xxx family share the same
 * pin multiplexing (although they may differ in the pins physically available).
 *
 * Alternative pin selections are provided with a numeric suffix like _1, _2, etc.
 * Drivers, however, will use the pin selection without the numeric suffix.
 * Additional definitions are required in the board.h file.  For example, if
 * CAN1_RX connects vis PA11 on some board, then the following definitions should
 * appear inthe board.h header file for that board:
 *
 * #define GPIO_CAN1_RX GPIO_CAN1_RX_1
 *
 * The driver will then automatically configre PA11 as the CAN1 RX pin.
 */

/* WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!!
 * Additional effort is required to select specific GPIO options such as frequency,
 * open-drain/push-pull, and pull-up/down!  Just the basics are defined for most
 * pins in this file.
 */

/* ADC */

#define GPIO_ADC1_IN1         (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN0)
#define GPIO_ADC1_IN2         (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN1)
#define GPIO_ADC1_IN3         (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN2)
#define GPIO_ADC1_IN4         (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN3)
#define GPIO_ADC1_IN5         (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN0)
#define GPIO_ADC1_IN6         (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN1)
#define GPIO_ADC1_IN7         (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN2)
#define GPIO_ADC1_IN8         (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN3)
#define GPIO_ADC1_IN9         (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN4)
#define GPIO_ADC1_IN10        (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN5)
#define GPIO_ADC1_IN11        (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN6)
#define GPIO_ADC1_IN12        (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN7)
#define GPIO_ADC1_IN13        (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN4)
#define GPIO_ADC1_IN14        (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN5)
#define GPIO_ADC1_IN15        (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN0)
#define GPIO_ADC1_IN16        (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN1)

/* CAN */

#define GPIO_CAN1_RX_1         (GPIO_ALT|GPIO_AF9 |GPIO_PORTA|GPIO_PIN11)
#define GPIO_CAN1_RX_2         (GPIO_ALT|GPIO_AF3 |GPIO_PORTB|GPIO_PIN5)
#define GPIO_CAN1_RX_3         (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN8)
#define GPIO_CAN1_RX_4         (GPIO_ALT|GPIO_AF10 |GPIO_PORTB|GPIO_PIN12)
#define GPIO_CAN1_RX_5         (GPIO_ALT|GPIO_AF9 |GPIO_PORTD|GPIO_PIN0)
#define GPIO_CAN1_TX_1         (GPIO_ALT|GPIO_AF9 |GPIO_PORTA|GPIO_PIN12)
#define GPIO_CAN1_TX_2         (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN6)
#define GPIO_CAN1_TX_3         (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN9)
#define GPIO_CAN1_TX_4         (GPIO_ALT|GPIO_AF10 |GPIO_PORTB|GPIO_PIN13)
#define GPIO_CAN1_TX_5         (GPIO_ALT|GPIO_AF9 |GPIO_PORTD|GPIO_PIN1)

/* Clocks outputs */

#define GPIO_MCO               (GPIO_ALT|GPIO_AF0 |GPIO_PORTA|GPIO_PIN8)

/* Comparators */

#define GPIO_COMP1_INM_1       (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN1)
#define GPIO_COMP1_INM_2       (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN4)
#define GPIO_COMP1_INM_3       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN0)
#define GPIO_COMP1_INM_4       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN4)
#define GPIO_COMP1_INM_5       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN5)
#define GPIO_COMP1_INP_1       (GPIO_ANALOG|GPIO_PORTC|GPIO_PIN5)
#define GPIO_COMP1_INP_2       (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN2)
#define GPIO_COMP1_INP_3       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN1)
#define GPIO_COMP1_OUT_1       (GPIO_ALT|GPIO_AF6|GPIO_PORTA|GPIO_PIN6)
#define GPIO_COMP1_OUT_2       (GPIO_ALT|GPIO_AF6|GPIO_PORTA|GPIO_PIN11)
#define GPIO_COMP1_OUT_3       (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN0)
#define GPIO_COMP1_OUT_4       (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN0)
#define GPIO_COMP1_OUT_5       (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN10)

#define GPIO_COMP2_INM_1       (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN3)
#define GPIO_COMP2_INM_2       (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN7)
#define GPIO_COMP2_INM_3       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN2)
#define GPIO_COMP2_INM_4       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN4)
#define GPIO_COMP2_INM_5       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN5)
#define GPIO_COMP2_INP_1       (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN4)
#define GPIO_COMP2_INP_2       (GPIO_ANALOG|GPIO_PORTB|GPIO_PIN6)
#define GPIO_COMP2_INP_3       (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN3)
#define GPIO_COMP2_OUT_1       (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN2)
#define GPIO_COMP2_OUT_2       (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN7)
#define GPIO_COMP2_OUT_3       (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN5)
#define GPIO_COMP2_OUT_4       (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN11)

/* DAC */

#define GPIO_DAC1_OUT_1        (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN4)
#define GPIO_DAC1_OUT_2        (GPIO_ANALOG|GPIO_PORTA|GPIO_PIN5)

/* Digital Filter for Sigma-Delta Modulators (DFSDM) */

#define GPIO_DFSDM_DATIN0_1    (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN1)
#define GPIO_DFSDM_DATIN0_2    (GPIO_ALT|GPIO_AF6 |GPIO_PORTD|GPIO_PIN3)
#define GPIO_DFSDM_DATIN0_3    (GPIO_ALT|GPIO_AF6 |GPIO_PORTA|GPIO_PIN7)
#define GPIO_DFSDM_DATIN1_1    (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN12)
#define GPIO_DFSDM_DATIN1_2    (GPIO_ALT|GPIO_AF6 |GPIO_PORTD|GPIO_PIN6)
#define GPIO_DFSDM_DATIN1_3    (GPIO_ALT|GPIO_AF6 |GPIO_PORTA|GPIO_PIN9)
#define GPIO_DFSDM_DATIN2_1    (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN14)
#define GPIO_DFSDM_DATIN2_2    (GPIO_ALT|GPIO_AF6 |GPIO_PORTE|GPIO_PIN7)
#define GPIO_DFSDM_DATIN3_1    (GPIO_ALT|GPIO_AF6 |GPIO_PORTC|GPIO_PIN7)
#define GPIO_DFSDM_DATIN3_2    (GPIO_ALT|GPIO_AF6 |GPIO_PORTE|GPIO_PIN4)

#define GPIO_DFSDM_CKIN0_1     (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN2)
#define GPIO_DFSDM_CKIN0_2     (GPIO_ALT|GPIO_AF6 |GPIO_PORTD|GPIO_PIN4)
#define GPIO_DFSDM_CKIN0_3     (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN0)
#define GPIO_DFSDM_CKIN1_1     (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN13)
#define GPIO_DFSDM_CKIN1_2     (GPIO_ALT|GPIO_AF6 |GPIO_PORTD|GPIO_PIN7)
#define GPIO_DFSDM_CKIN1_3     (GPIO_ALT|GPIO_AF6 |GPIO_PORTA|GPIO_PIN8)
#define GPIO_DFSDM_CKIN2_1     (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN15)
#define GPIO_DFSDM_CKIN2_2     (GPIO_ALT|GPIO_AF6 |GPIO_PORTE|GPIO_PIN8)
#define GPIO_DFSDM_CKIN3_1     (GPIO_ALT|GPIO_AF6 |GPIO_PORTC|GPIO_PIN6)
#define GPIO_DFSDM_CKIN3_2     (GPIO_ALT|GPIO_AF6 |GPIO_PORTE|GPIO_PIN5)

#define GPIO_DFSDM_CKOUT_1     (GPIO_ALT|GPIO_AF6 |GPIO_PORTA|GPIO_PIN5)
#define GPIO_DFSDM_CKOUT_2     (GPIO_ALT|GPIO_AF6 |GPIO_PORTC|GPIO_PIN2)
#define GPIO_DFSDM_CKOUT_3     (GPIO_ALT|GPIO_AF6 |GPIO_PORTE|GPIO_PIN9)

/* I2C */

#define GPIO_I2C1_SDA_1        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN7)
#define GPIO_I2C1_SDA_2        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN9)
#define GPIO_I2C1_SDA_3        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTA|GPIO_PIN10)
#define GPIO_I2C1_SCL_1        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN6)
#define GPIO_I2C1_SCL_2        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN8)
#define GPIO_I2C1_SCL_3        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTA|GPIO_PIN9)
#define GPIO_I2C1_SMBA_1       (GPIO_ALT|GPIO_AF4 |GPIO_PORTA|GPIO_PIN1)
#define GPIO_I2C1_SMBA_2       (GPIO_ALT|GPIO_AF4 |GPIO_PORTA|GPIO_PIN14)
#define GPIO_I2C1_SMBA_3       (GPIO_ALT|GPIO_AF4 |GPIO_PORTB|GPIO_PIN5)

#define GPIO_I2C2_SDA_1        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN11)
#define GPIO_I2C2_SDA_2        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN14)
#define GPIO_I2C2_SCL_1        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN10)
#define GPIO_I2C2_SCL_2        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN13)
#define GPIO_I2C2_SMBA_1       (GPIO_ALT|GPIO_AF4 |GPIO_PORTB|GPIO_PIN12)

#define GPIO_I2C3_SDA_1        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN4)
#define GPIO_I2C3_SDA_2        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTC|GPIO_PIN1)
#define GPIO_I2C3_SCL_1        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTA|GPIO_PIN7)
#define GPIO_I2C3_SCL_2        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTC|GPIO_PIN0)
#define GPIO_I2C3_SMBA_1       (GPIO_ALT|GPIO_AF4 |GPIO_PORTB|GPIO_PIN2)

#define GPIO_I2C4_SDA_1        (GPIO_ALT|GPIO_AF5 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN7)
#define GPIO_I2C4_SDA_2        (GPIO_ALT|GPIO_AF3 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN11)
#define GPIO_I2C4_SDA_3        (GPIO_ALT|GPIO_AF2 |GPIO_OPENDRAIN|GPIO_PORTC|GPIO_PIN1)
#define GPIO_I2C4_SDA_4        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTD|GPIO_PIN13)
#define GPIO_I2C4_SCL_1        (GPIO_ALT|GPIO_AF5 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN6)
#define GPIO_I2C4_SCL_2        (GPIO_ALT|GPIO_AF3 |GPIO_OPENDRAIN|GPIO_PORTB|GPIO_PIN10)
#define GPIO_I2C4_SCL_3        (GPIO_ALT|GPIO_AF2 |GPIO_OPENDRAIN|GPIO_PORTC|GPIO_PIN0)
#define GPIO_I2C4_SCL_4        (GPIO_ALT|GPIO_AF4 |GPIO_OPENDRAIN|GPIO_PORTD|GPIO_PIN12)
#define GPIO_I2C4_SMBA_1       (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN14)
#define GPIO_I2C4_SMBA_2       (GPIO_ALT|GPIO_AF4 |GPIO_PORTD|GPIO_PIN11)

/* JTAG */

#define GPIO_JTCK_SWCLK        (GPIO_ALT|GPIO_AF0|GPIO_PORTA|GPIO_PIN14)
#define GPIO_JTDI              (GPIO_ALT|GPIO_AF0|GPIO_PORTA|GPIO_PIN15)
#define GPIO_JTDO              (GPIO_ALT|GPIO_AF0|GPIO_PORTB|GPIO_PIN3)
#define GPIO_JTMS_SWDAT        (GPIO_ALT|GPIO_AF0|GPIO_PORTA|GPIO_PIN13)
#define GPIO_JTRST             (GPIO_ALT|GPIO_AF0|GPIO_PORTB|GPIO_PIN4)

/* QUADSPI */

#define GPIO_QSPI_NCS_1        (GPIO_ALT|GPIO_AF10|GPIO_PORTB|GPIO_PIN11)
#define GPIO_QSPI_NCS_2        (GPIO_ALT|GPIO_AF10|GPIO_PORTE|GPIO_PIN11)
#define GPIO_QSPI_NCS_3        (GPIO_ALT|GPIO_AF10|GPIO_PORTA|GPIO_PIN2)
#define GPIO_QSPI_CLK_1        (GPIO_ALT|GPIO_AF10|GPIO_PORTB|GPIO_PIN10)
#define GPIO_QSPI_CLK_2        (GPIO_ALT|GPIO_AF10|GPIO_PORTE|GPIO_PIN10)
#define GPIO_QSPI_CLK_3        (GPIO_ALT|GPIO_AF10|GPIO_PORTA|GPIO_PIN3)
#define GPIO_QSPI_BK1_IO0_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTB|GPIO_PIN1)
#define GPIO_QSPI_BK1_IO0_2    (GPIO_ALT|GPIO_AF10|GPIO_PORTE|GPIO_PIN12)
#define GPIO_QSPI_BK1_IO1_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTB|GPIO_PIN0)
#define GPIO_QSPI_BK1_IO1_2    (GPIO_ALT|GPIO_AF10|GPIO_PORTE|GPIO_PIN13)
#define GPIO_QSPI_BK1_IO2_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTA|GPIO_PIN7)
#define GPIO_QSPI_BK1_IO2_2    (GPIO_ALT|GPIO_AF10|GPIO_PORTE|GPIO_PIN14)
#define GPIO_QSPI_BK1_IO3_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTA|GPIO_PIN6)
#define GPIO_QSPI_BK1_IO3_2    (GPIO_ALT|GPIO_AF10|GPIO_PORTE|GPIO_PIN15)

#define GPIO_QSPI_BK2_NCS_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTD|GPIO_PIN3)
#define GPIO_QSPI_BK2_IO0_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTD|GPIO_PIN4)
#define GPIO_QSPI_BK2_IO1_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTD|GPIO_PIN5)
#define GPIO_QSPI_BK2_IO2_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTD|GPIO_PIN6)
#define GPIO_QSPI_BK2_IO3_1    (GPIO_ALT|GPIO_AF10|GPIO_PORTD|GPIO_PIN7)

/* RTC */

#define GPIO_RTC_OUT           (GPIO_ALT|GPIO_AF0 |GPIO_PORTB|GPIO_PIN2)
#define GPIO_RTC_REFIN         (GPIO_ALT|GPIO_AF0 |GPIO_PORTB|GPIO_PIN15)

/* SAI */

#define GPIO_SAI1_EXTCLK_1     (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN0)
#define GPIO_SAI1_EXTCLK_2     (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN0)

#define GPIO_SAI1_FS_A_1       (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN9)
#define GPIO_SAI1_FS_A_2       (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN4)
#define GPIO_SAI1_FS_A_3       (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN9)
#define GPIO_SAI1_FS_A_4       (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN12)
#define GPIO_SAI1_SCK_A_1      (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN10)
#define GPIO_SAI1_SCK_A_2      (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN5)
#define GPIO_SAI1_SCK_A_3      (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN8)
#define GPIO_SAI1_SCK_A_4      (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN13)
#define GPIO_SAI1_SD_A_1       (GPIO_ALT|GPIO_AF13|GPIO_PORTC|GPIO_PIN3)
#define GPIO_SAI1_SD_A_2       (GPIO_ALT|GPIO_AF13|GPIO_PORTD|GPIO_PIN6)
#define GPIO_SAI1_SD_A_3       (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN6)
#define GPIO_SAI1_SD_A_4       (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN10)
#define GPIO_SAI1_SD_A_5       (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN15)
#define GPIO_SAI1_MCLK_A_1     (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN8)
#define GPIO_SAI1_MCLK_A_2     (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN2)
#define GPIO_SAI1_MCLK_A_3     (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN3)
#define GPIO_SAI1_MCLK_A_4     (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN14)

#define GPIO_SAI1_FS_B_1       (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN4)
#define GPIO_SAI1_FS_B_2       (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN6)
#define GPIO_SAI1_FS_B_3       (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN9)
#define GPIO_SAI1_FS_B_4       (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN14)
#define GPIO_SAI1_SCK_B_1      (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN3)
#define GPIO_SAI1_SCK_B_2      (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN8)
#define GPIO_SAI1_SD_B_1       (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN5)
#define GPIO_SAI1_SD_B_2       (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN3)
#define GPIO_SAI1_SD_B_3       (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN7)
#define GPIO_SAI1_SD_B_4       (GPIO_ALT|GPIO_AF13|GPIO_PORTA|GPIO_PIN13)
#define GPIO_SAI1_MCLK_B_1     (GPIO_ALT|GPIO_AF13|GPIO_PORTB|GPIO_PIN4)
#define GPIO_SAI1_MCLK_B_2     (GPIO_ALT|GPIO_AF13|GPIO_PORTE|GPIO_PIN10)

/* SDIO */

#define GPIO_SDMMC1_CK         (GPIO_ALT|GPIO_AF12|GPIO_PORTC|GPIO_PIN12)
#define GPIO_SDMMC1_CMD        (GPIO_ALT|GPIO_AF12|GPIO_PORTD|GPIO_PIN2)
#define GPIO_SDMMC1_D0         (GPIO_ALT|GPIO_AF12|GPIO_PORTC|GPIO_PIN8)
#define GPIO_SDMMC1_D1         (GPIO_ALT|GPIO_AF12|GPIO_PORTC|GPIO_PIN9)
#define GPIO_SDMMC1_D2         (GPIO_ALT|GPIO_AF12|GPIO_PORTC|GPIO_PIN10)
#define GPIO_SDMMC1_D3         (GPIO_ALT|GPIO_AF12|GPIO_PORTC|GPIO_PIN11)
#define GPIO_SDMMC1_D4         (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN8)
#define GPIO_SDMMC1_D5         (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN9)
#define GPIO_SDMMC1_D6         (GPIO_ALT|GPIO_AF12|GPIO_PORTC|GPIO_PIN6)
#define GPIO_SDMMC1_D7         (GPIO_ALT|GPIO_AF12|GPIO_PORTC|GPIO_PIN7)

/* Single Wire Protocol Interface */

#define GPIO_SWPMI1_IO_1       (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN8)
#define GPIO_SWPMI1_IO_2       (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN12)
#define GPIO_SWPMI1_TX_1       (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN13)
#define GPIO_SWPMI1_TX_2       (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN13)
#define GPIO_SWPMI1_RX_1       (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN14)
#define GPIO_SWPMI1_RX_2       (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN14)
#define GPIO_SWPMI1_SUSPEND_1  (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN15)
#define GPIO_SWPMI1_SUSPEND_2  (GPIO_ALT|GPIO_AF12|GPIO_PORTB|GPIO_PIN15)

/* SPI */

#define GPIO_SPI1_NSS_1        (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN4)
#define GPIO_SPI1_NSS_2        (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN15)
#define GPIO_SPI1_NSS_3        (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN0)
#define GPIO_SPI1_NSS_4        (GPIO_ALT|GPIO_AF5 |GPIO_PORTE|GPIO_PIN12)
#define GPIO_SPI1_SCK_1        (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN1)
#define GPIO_SPI1_SCK_2        (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN5)
#define GPIO_SPI1_SCK_3        (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN3)
#define GPIO_SPI1_SCK_4        (GPIO_ALT|GPIO_AF5 |GPIO_PORTE|GPIO_PIN13)
#define GPIO_SPI1_MOSI_1       (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN7)
#define GPIO_SPI1_MOSI_2       (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN12)
#define GPIO_SPI1_MOSI_3       (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN5)
#define GPIO_SPI1_MOSI_4       (GPIO_ALT|GPIO_AF5 |GPIO_PORTE|GPIO_PIN15)
#define GPIO_SPI1_MISO_1       (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN6)
#define GPIO_SPI1_MISO_2       (GPIO_ALT|GPIO_AF5 |GPIO_PORTA|GPIO_PIN11)
#define GPIO_SPI1_MISO_3       (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN4)
#define GPIO_SPI1_MISO_4       (GPIO_ALT|GPIO_AF5 |GPIO_PORTE|GPIO_PIN14)

#define GPIO_SPI2_NSS_1        (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN9)
#define GPIO_SPI2_NSS_2        (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN12)
#define GPIO_SPI2_NSS_3        (GPIO_ALT|GPIO_AF5 |GPIO_PORTD|GPIO_PIN0)
#define GPIO_SPI2_SCK_1        (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN10)
#define GPIO_SPI2_SCK_2        (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN13)
#define GPIO_SPI2_SCK_3        (GPIO_ALT|GPIO_AF5 |GPIO_PORTD|GPIO_PIN1)
#define GPIO_SPI2_MOSI_1       (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN15)
#define GPIO_SPI2_MOSI_2       (GPIO_ALT|GPIO_AF5 |GPIO_PORTC|GPIO_PIN3)
#define GPIO_SPI2_MOSI_3       (GPIO_ALT|GPIO_AF5 |GPIO_PORTD|GPIO_PIN4)
#define GPIO_SPI2_MISO_1       (GPIO_ALT|GPIO_AF5 |GPIO_PORTB|GPIO_PIN14)
#define GPIO_SPI2_MISO_2       (GPIO_ALT|GPIO_AF5 |GPIO_PORTC|GPIO_PIN2)
#define GPIO_SPI2_MISO_3       (GPIO_ALT|GPIO_AF5 |GPIO_PORTD|GPIO_PIN3)

#define GPIO_SPI3_NSS_1        (GPIO_ALT|GPIO_AF6 |GPIO_PORTA|GPIO_PIN4)
#define GPIO_SPI3_NSS_2        (GPIO_ALT|GPIO_AF6 |GPIO_PORTA|GPIO_PIN15)
#define GPIO_SPI3_SCK_1        (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN3)
#define GPIO_SPI3_SCK_2        (GPIO_ALT|GPIO_AF6 |GPIO_PORTC|GPIO_PIN10)
#define GPIO_SPI3_MOSI_1       (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN5)
#define GPIO_SPI3_MOSI_2       (GPIO_ALT|GPIO_AF6 |GPIO_PORTC|GPIO_PIN12)
#define GPIO_SPI3_MISO_1       (GPIO_ALT|GPIO_AF6 |GPIO_PORTB|GPIO_PIN4)
#define GPIO_SPI3_MISO_2       (GPIO_ALT|GPIO_AF6 |GPIO_PORTC|GPIO_PIN11)

/* Timers */

#define GPIO_TIM1_CH1IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN8)
#define GPIO_TIM1_CH1IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN9)
#define GPIO_TIM1_CH1OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN8)
#define GPIO_TIM1_CH1OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN9)
#define GPIO_TIM1_CH2IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN9)
#define GPIO_TIM1_CH2IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN11)
#define GPIO_TIM1_CH2OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN9)
#define GPIO_TIM1_CH2OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN11)
#define GPIO_TIM1_CH3IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN10)
#define GPIO_TIM1_CH3IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN13)
#define GPIO_TIM1_CH3OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN10)
#define GPIO_TIM1_CH3OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN13)
#define GPIO_TIM1_CH4IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN11)
#define GPIO_TIM1_CH4IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN14)
#define GPIO_TIM1_CH4OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN11)
#define GPIO_TIM1_CH4OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN14)
#define GPIO_TIM1_CH1N_1       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN7)
#define GPIO_TIM1_CH1N_2       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN13)
#define GPIO_TIM1_CH1N_3       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN8)
#define GPIO_TIM1_CH2N_1       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN0)
#define GPIO_TIM1_CH2N_2       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN14)
#define GPIO_TIM1_CH2N_3       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN10)
#define GPIO_TIM1_CH3N_1       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN1)
#define GPIO_TIM1_CH3N_2       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN15)
#define GPIO_TIM1_CH3N_3       (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN12)
#define GPIO_TIM1_BKIN_1       (GPIO_ALT|GPIO_AF1 |GPIO_PORTA|GPIO_PIN6)
#define GPIO_TIM1_BKIN_2       (GPIO_ALT|GPIO_AF1 |GPIO_PORTB|GPIO_PIN12)
#define GPIO_TIM1_BKIN_3       (GPIO_ALT|GPIO_AF1 |GPIO_PORTE|GPIO_PIN15)
#define GPIO_TIM1_BKIN_COMP1   (GPIO_ALT|GPIO_AF3 |GPIO_PORTE|GPIO_PIN15)
#define GPIO_TIM1_BKIN_COMP2_1 (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN6)
#define GPIO_TIM1_BKIN_COMP2_2 (GPIO_ALT|GPIO_AF3 |GPIO_PORTB|GPIO_PIN12)
#define GPIO_TIM1_BKIN2_1      (GPIO_ALT|GPIO_AF2 |GPIO_PORTA|GPIO_PIN11)
#define GPIO_TIM1_BKIN2_2      (GPIO_ALT|GPIO_AF2 |GPIO_PORTE|GPIO_PIN14)
#define GPIO_TIM1_BKIN2_COMP1  (GPIO_ALT|GPIO_AF12|GPIO_PORTA|GPIO_PIN11)
#define GPIO_TIM1_BKIN2_COMP2  (GPIO_ALT|GPIO_AF3 |GPIO_PORTE|GPIO_PIN14)
#define GPIO_TIM1_ETR_1        (GPIO_ALT|GPIO_AF1 |GPIO_PORTA|GPIO_PIN12)
#define GPIO_TIM1_ETR_2        (GPIO_ALT|GPIO_AF1 |GPIO_PORTE|GPIO_PIN7)

#define GPIO_TIM2_CH1IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN0)
#define GPIO_TIM2_CH1IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN5)
#define GPIO_TIM2_CH1IN_3      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN15)
#define GPIO_TIM2_CH1OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN0)
#define GPIO_TIM2_CH1OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN5)
#define GPIO_TIM2_CH1OUT_3     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN15)
#define GPIO_TIM2_CH2IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN1)
#define GPIO_TIM2_CH2IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN3)
#define GPIO_TIM2_CH2OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN1)
#define GPIO_TIM2_CH2OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN3)
#define GPIO_TIM2_CH3IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN2)
#define GPIO_TIM2_CH3IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN10)
#define GPIO_TIM2_CH3OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN2)
#define GPIO_TIM2_CH3OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN10)
#define GPIO_TIM2_CH4IN_1      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN3)
#define GPIO_TIM2_CH4IN_2      (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN11)
#define GPIO_TIM2_CH4OUT_1     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN3)
#define GPIO_TIM2_CH4OUT_2     (GPIO_ALT|GPIO_AF1 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN11)
#define GPIO_TIM2_ETR_1        (GPIO_ALT|GPIO_AF14|GPIO_PORTA|GPIO_PIN0)
#define GPIO_TIM2_ETR_2        (GPIO_ALT|GPIO_AF2 |GPIO_PORTA|GPIO_PIN5)
#define GPIO_TIM2_ETR_3        (GPIO_ALT|GPIO_AF2 |GPIO_PORTA|GPIO_PIN15)

#define GPIO_TIM3_CH1IN_1      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN6)
#define GPIO_TIM3_CH1IN_2      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN4)
#define GPIO_TIM3_CH1IN_3      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTC|GPIO_PIN6)
#define GPIO_TIM3_CH1IN_4      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN3)
#define GPIO_TIM3_CH1OUT_1     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN6)
#define GPIO_TIM3_CH1OUT_2     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN4)
#define GPIO_TIM3_CH1OUT_3     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTC|GPIO_PIN6)
#define GPIO_TIM3_CH1OUT_4     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN3)
#define GPIO_TIM3_CH2IN_1      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN7)
#define GPIO_TIM3_CH2IN_2      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN5)
#define GPIO_TIM3_CH2IN_3      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTC|GPIO_PIN7)
#define GPIO_TIM3_CH2IN_4      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN4)
#define GPIO_TIM3_CH2OUT_1     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN7)
#define GPIO_TIM3_CH2OUT_2     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN5)
#define GPIO_TIM3_CH2OUT_3     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTC|GPIO_PIN7)
#define GPIO_TIM3_CH2OUT_4     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN4)
#define GPIO_TIM3_CH3IN_1      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN0)
#define GPIO_TIM3_CH3IN_2      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTC|GPIO_PIN8)
#define GPIO_TIM3_CH3IN_3      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN5)
#define GPIO_TIM3_CH3OUT_1     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN0)
#define GPIO_TIM3_CH3OUT_2     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTC|GPIO_PIN8)
#define GPIO_TIM3_CH3OUT_3     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN5)
#define GPIO_TIM3_CH4IN_1      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN1)
#define GPIO_TIM3_CH4IN_2      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTC|GPIO_PIN9)
#define GPIO_TIM3_CH4IN_3      (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN6)
#define GPIO_TIM3_CH4OUT_1     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN1)
#define GPIO_TIM3_CH4OUT_2     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTC|GPIO_PIN9)
#define GPIO_TIM3_CH4OUT_3     (GPIO_ALT|GPIO_AF2 |GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN6)
#define GPIO_TIM3_ETR_1        (GPIO_ALT|GPIO_AF2 |GPIO_PORTD|GPIO_PIN2)
#define GPIO_TIM3_ETR_2        (GPIO_ALT|GPIO_AF2 |GPIO_PORTE|GPIO_PIN2)

#define GPIO_TIM15_CH1IN_1     (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN2)
#define GPIO_TIM15_CH1IN_2     (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN14)
#define GPIO_TIM15_CH1OUT_1    (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN2)
#define GPIO_TIM15_CH1OUT_2    (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN14)
#define GPIO_TIM15_CH2IN_1     (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN3)
#define GPIO_TIM15_CH2IN_2     (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN15)
#define GPIO_TIM15_CH2OUT_1    (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN3)
#define GPIO_TIM15_CH2OUT_2    (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN15)
#define GPIO_TIM15_CH1N_1      (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN1)
#define GPIO_TIM15_CH1N_2      (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN13)
#define GPIO_TIM15_BKIN_1      (GPIO_ALT|GPIO_AF14|GPIO_PORTA|GPIO_PIN9)
#define GPIO_TIM15_BKIN_2      (GPIO_ALT|GPIO_AF14|GPIO_PORTB|GPIO_PIN12)

#define GPIO_TIM16_CH1IN_1     (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTA|GPIO_PIN6)
#define GPIO_TIM16_CH1IN_2     (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTB|GPIO_PIN8)
#define GPIO_TIM16_CH1IN_3     (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_FLOAT|GPIO_PORTE|GPIO_PIN0)
#define GPIO_TIM16_CH1OUT_1    (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTA|GPIO_PIN6)
#define GPIO_TIM16_CH1OUT_2    (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN8)
#define GPIO_TIM16_CH1OUT_3    (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN0)
#define GPIO_TIM16_CH1N        (GPIO_ALT|GPIO_AF14|GPIO_SPEED_50MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN6)
#define GPIO_TIM16_BKIN        (GPIO_ALT|GPIO_AF14|GPIO_PORTB|GPIO_PIN5)

#define GPIO_LPTIM1_IN1_1      (GPIO_ALT|GPIO_AF1 |GPIO_PORTB|GPIO_PIN5)
#define GPIO_LPTIM1_IN1_2      (GPIO_ALT|GPIO_AF1 |GPIO_PORTC|GPIO_PIN0)
#define GPIO_LPTIM1_IN2_1      (GPIO_ALT|GPIO_AF1 |GPIO_PORTB|GPIO_PIN7)
#define GPIO_LPTIM1_IN2_2      (GPIO_ALT|GPIO_AF1 |GPIO_PORTC|GPIO_PIN2)
#define GPIO_LPTIM1_OUT_1      (GPIO_ALT|GPIO_AF1 |GPIO_PORTB|GPIO_PIN2)
#define GPIO_LPTIM1_OUT_2      (GPIO_ALT|GPIO_AF1 |GPIO_PORTC|GPIO_PIN1)
#define GPIO_LPTIM1_OUT_3      (GPIO_ALT|GPIO_AF1 |GPIO_PORTA|GPIO_PIN14)
#define GPIO_LPTIM1_ETR_1      (GPIO_ALT|GPIO_AF1 |GPIO_PORTB|GPIO_PIN6)
#define GPIO_LPTIM1_ETR_2      (GPIO_ALT|GPIO_AF1 |GPIO_PORTC|GPIO_PIN3)

#define GPIO_LPTIM2_IN1_1      (GPIO_ALT|GPIO_AF14|GPIO_PORTB|GPIO_PIN1)
#define GPIO_LPTIM2_IN1_2      (GPIO_ALT|GPIO_AF14|GPIO_PORTC|GPIO_PIN0)
#define GPIO_LPTIM2_IN1_3      (GPIO_ALT|GPIO_AF14|GPIO_PORTD|GPIO_PIN12)
#define GPIO_LPTIM2_OUT_1      (GPIO_ALT|GPIO_AF14|GPIO_PORTA|GPIO_PIN4)
#define GPIO_LPTIM2_OUT_2      (GPIO_ALT|GPIO_AF14|GPIO_PORTA|GPIO_PIN8)
#define GPIO_LPTIM2_OUT_3      (GPIO_ALT|GPIO_AF14|GPIO_PORTD|GPIO_PIN13)
#define GPIO_LPTIM2_ETR_1      (GPIO_ALT|GPIO_AF14|GPIO_PORTA|GPIO_PIN5)
#define GPIO_LPTIM2_ETR_2      (GPIO_ALT|GPIO_AF14|GPIO_PORTC|GPIO_PIN3)
#define GPIO_LPTIM2_ETR_3      (GPIO_ALT|GPIO_AF14|GPIO_PORTD|GPIO_PIN11)

/* Touch Screen Controller */

#define GPIO_TSC_SYNC_1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN10)
#define GPIO_TSC_SYNC_2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTD|GPIO_PIN2)

#define GPIO_TSC_G1_IO1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN12)
#define GPIO_TSC_G1_IO2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN13)
#define GPIO_TSC_G1_IO3        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN14)
#define GPIO_TSC_G1_IO4        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN15)

#define GPIO_TSC_G2_IO1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN4)
#define GPIO_TSC_G2_IO2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN5)
#define GPIO_TSC_G2_IO3        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN6)
#define GPIO_TSC_G2_IO4        (GPIO_ALT|GPIO_AF9 |GPIO_PORTB|GPIO_PIN7)

#define GPIO_TSC_G3_IO1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTA|GPIO_PIN15)
#define GPIO_TSC_G3_IO2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTC|GPIO_PIN10)
#define GPIO_TSC_G3_IO3        (GPIO_ALT|GPIO_AF9 |GPIO_PORTC|GPIO_PIN11)
#define GPIO_TSC_G3_IO4        (GPIO_ALT|GPIO_AF9 |GPIO_PORTC|GPIO_PIN12)

#define GPIO_TSC_G4_IO1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTC|GPIO_PIN6)
#define GPIO_TSC_G4_IO2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTC|GPIO_PIN7)
#define GPIO_TSC_G4_IO3        (GPIO_ALT|GPIO_AF9 |GPIO_PORTC|GPIO_PIN8)
#define GPIO_TSC_G4_IO4        (GPIO_ALT|GPIO_AF9 |GPIO_PORTC|GPIO_PIN9)

#define GPIO_TSC_G5_IO1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN10)
#define GPIO_TSC_G5_IO2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN11)
#define GPIO_TSC_G5_IO3        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN12)
#define GPIO_TSC_G5_IO4        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN13)

#define GPIO_TSC_G6_IO1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTD|GPIO_PIN10)
#define GPIO_TSC_G6_IO2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTD|GPIO_PIN11)
#define GPIO_TSC_G6_IO3        (GPIO_ALT|GPIO_AF9 |GPIO_PORTD|GPIO_PIN12)
#define GPIO_TSC_G6_IO4        (GPIO_ALT|GPIO_AF9 |GPIO_PORTD|GPIO_PIN13)

#define GPIO_TSC_G7_IO1        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN2)
#define GPIO_TSC_G7_IO2        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN3)
#define GPIO_TSC_G7_IO3        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN4)
#define GPIO_TSC_G7_IO4        (GPIO_ALT|GPIO_AF9 |GPIO_PORTE|GPIO_PIN5)

/* IR interface (with timers 16 and 17) */

#define GPIO_IR_OUT_1          (GPIO_ALT|GPIO_AF1 |GPIO_PORTA|GPIO_PIN13)
#define GPIO_IR_OUT_2          (GPIO_ALT|GPIO_AF1 |GPIO_PORTB|GPIO_PIN9)

/* Trace */

#define GPIO_TRACECK           (GPIO_ALT|GPIO_AF0 |GPIO_PORTE|GPIO_PIN2)
#define GPIO_TRACED0_1         (GPIO_ALT|GPIO_AF0 |GPIO_PORTE|GPIO_PIN3)
#define GPIO_TRACED1_1         (GPIO_ALT|GPIO_AF0 |GPIO_PORTE|GPIO_PIN4)
#define GPIO_TRACED2_1         (GPIO_ALT|GPIO_AF0 |GPIO_PORTE|GPIO_PIN5)
#define GPIO_TRACED3_1         (GPIO_ALT|GPIO_AF0 |GPIO_PORTE|GPIO_PIN6)
#define GPIO_TRACED0_2         (GPIO_ALT|GPIO_AF0 |GPIO_PORTC|GPIO_PIN1)
#define GPIO_TRACED1_2         (GPIO_ALT|GPIO_AF0 |GPIO_PORTC|GPIO_PIN10)
#define GPIO_TRACED2_2         (GPIO_ALT|GPIO_AF0 |GPIO_PORTD|GPIO_PIN2)
#define GPIO_TRACED3_2         (GPIO_ALT|GPIO_AF0 |GPIO_PORTC|GPIO_PIN12)

/* UARTs/USARTs */

#define GPIO_USART1_TX_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN9)
#define GPIO_USART1_TX_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN6)
#define GPIO_USART1_RX_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN10)
#define GPIO_USART1_RX_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN7)
#define GPIO_USART1_CK_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN8)
#define GPIO_USART1_CK_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN5)
#define GPIO_USART1_CTS_1      (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN11)
#define GPIO_USART1_CTS_2      (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN4)
#define GPIO_USART1_RTS_DE_1   (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN12)
#define GPIO_USART1_RTS_DE_2   (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN3)

#define GPIO_USART2_TX_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN2)
#define GPIO_USART2_TX_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN5)
#define GPIO_USART2_RX_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN3)
#define GPIO_USART2_RX_2       (GPIO_ALT|GPIO_AF3 |GPIO_PORTA|GPIO_PIN15)
#define GPIO_USART2_RX_3       (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN6)
#define GPIO_USART2_CK_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN4)
#define GPIO_USART2_CK_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN7)
#define GPIO_USART2_CTS_1      (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN0)
#define GPIO_USART2_CTS_2      (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN3)
#define GPIO_USART2_RTS_DE_1   (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN1)
#define GPIO_USART2_RTS_DE_2   (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN4)

#define GPIO_USART3_TX_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN10)
#define GPIO_USART3_TX_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTC|GPIO_PIN4)
#define GPIO_USART3_TX_3       (GPIO_ALT|GPIO_AF7 |GPIO_PORTC|GPIO_PIN10)
#define GPIO_USART3_TX_4       (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN8)
#define GPIO_USART3_RX_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN11)
#define GPIO_USART3_RX_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTC|GPIO_PIN5)
#define GPIO_USART3_RX_3       (GPIO_ALT|GPIO_AF7 |GPIO_PORTC|GPIO_PIN11)
#define GPIO_USART3_RX_4       (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN9)
#define GPIO_USART3_CK_1       (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN0)
#define GPIO_USART3_CK_2       (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN12)
#define GPIO_USART3_CK_3       (GPIO_ALT|GPIO_AF7 |GPIO_PORTC|GPIO_PIN12)
#define GPIO_USART3_CK_4       (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN10)
#define GPIO_USART3_CTS_1      (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN6)
#define GPIO_USART3_CTS_2      (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN13)
#define GPIO_USART3_CTS_3      (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN11)
#define GPIO_USART3_RTS_DE_1   (GPIO_ALT|GPIO_AF7 |GPIO_PORTA|GPIO_PIN15)
#define GPIO_USART3_RTS_DE_2   (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN1)
#define GPIO_USART3_RTS_DE_3   (GPIO_ALT|GPIO_AF7 |GPIO_PORTB|GPIO_PIN14)
#define GPIO_USART3_RTS_DE_4   (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN2)
#define GPIO_USART3_RTS_DE_5   (GPIO_ALT|GPIO_AF7 |GPIO_PORTD|GPIO_PIN12)

#define GPIO_UART4_TX_1        (GPIO_ALT|GPIO_AF8 |GPIO_PORTA|GPIO_PIN0)
#define GPIO_UART4_TX_2        (GPIO_ALT|GPIO_AF8 |GPIO_PORTC|GPIO_PIN10)
#define GPIO_UART4_RX_1        (GPIO_ALT|GPIO_AF8 |GPIO_PORTA|GPIO_PIN1)
#define GPIO_UART4_RX_2        (GPIO_ALT|GPIO_AF8 |GPIO_PORTC|GPIO_PIN11)
#define GPIO_UART4_CTS         (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN7)
#define GPIO_UART4_RTS_DE      (GPIO_ALT|GPIO_AF8 |GPIO_PORTA|GPIO_PIN15)

#define GPIO_UART5_TX          (GPIO_ALT|GPIO_AF8 |GPIO_PORTC|GPIO_PIN12)
#define GPIO_UART5_RX          (GPIO_ALT|GPIO_AF8 |GPIO_PORTD|GPIO_PIN2)
#define GPIO_UART5_CTS         (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN5)
#define GPIO_UART5_RTS_DE      (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN4)

#define GPIO_LPUART1_TX_1      (GPIO_ALT|GPIO_AF8 |GPIO_PORTA|GPIO_PIN2)
#define GPIO_LPUART1_TX_2      (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN11)
#define GPIO_LPUART1_TX_3      (GPIO_ALT|GPIO_AF8 |GPIO_PORTC|GPIO_PIN1)
#define GPIO_LPUART1_RX_1      (GPIO_ALT|GPIO_AF8 |GPIO_PORTA|GPIO_PIN3)
#define GPIO_LPUART1_RX_2      (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN10)
#define GPIO_LPUART1_RX_3      (GPIO_ALT|GPIO_AF8 |GPIO_PORTC|GPIO_PIN0)
#define GPIO_LPUART1_CTS_1     (GPIO_ALT|GPIO_AF8 |GPIO_PORTA|GPIO_PIN6)
#define GPIO_LPUART1_CTS_2     (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN13)
#define GPIO_LPUART1_RTS_DE_1  (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN1)
#define GPIO_LPUART1_RTS_DE_2  (GPIO_ALT|GPIO_AF8 |GPIO_PORTB|GPIO_PIN12)

#endif /* __ARCH_ARM_SRC_STM32L4_CHIP_STM32L4X3XX_PINMAP_H */
