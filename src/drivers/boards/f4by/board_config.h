/****************************************************************************
 *
 *   Copyright (C) 2012 PX4 Development Team. All rights reserved.
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
 * 3. Neither the name PX4 nor the names of its contributors may be
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
 ****************************************************************************/

/**
 * @file board_config.h
 *
 * PX4FMU internal definitions
 */

#pragma once

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>
#include <stdint.h>

__BEGIN_DECLS

/* these headers are not C++ safe */
#include <stm32.h>
#include <arch/board/board.h>
 
/****************************************************************************************************
 * Definitions
 ****************************************************************************************************/
/* Configuration ************************************************************************************/

/* PX4IO connection configuration */
#define PX4IO_SERIAL_DEVICE	"/dev/ttyS3" // F4by надо избавится от io проца
#define UDID_START		0x1FFF7A10

//#ifdef CONFIG_STM32_SPI2
//#  error "SPI2 is not supported on this board"
//#endif

//#if defined(CONFIG_STM32_CAN1)
//#  warning "CAN1 is not supported on this board"
//#endif

/* PX4FMU GPIOs ***********************************************************************************/
/* LEDs */

#define GPIO_LED1		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN3)// F4by
#define GPIO_LED2		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN2)// F4by
#define GPIO_LED3		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN1)// F4by
#define GPIO_LED4		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN0)// F4by

/* External interrupts */
#define GPIO_EXTI_COMPASS	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTB|GPIO_PIN1)

/* SPI chip selects */
#define GPIO_SPI_CS_GYRO	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN4)// F4by
#define GPIO_SPI_CS_ACCEL	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN5)// F4by надо избавится от лишних датчиков
#define GPIO_SPI_CS_MPU		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTA|GPIO_PIN4)// F4by
#define GPIO_SPI_CS_SDCARD	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN15)// F4by
#define GPIO_SPI_CS_FLASH	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTB|GPIO_PIN12)// F4by

#define PX4_SPI_BUS_SENSORS 1

/*
 * Use these in place of the spi_dev_e enumeration to
 * select a specific SPI device on SPI1
 */
#define PX4_SPIDEV_GYRO		1
#define PX4_SPIDEV_ACCEL	2
#define PX4_SPIDEV_MPU		3

/*
 * Optional devices on IO's external port
 */
#define PX4_SPIDEV_ACCEL_MAG 2

/*
 * I2C busses
 */
#define PX4_I2C_BUS_ESC		1
#define PX4_I2C_BUS_ONBOARD	2
#define PX4_I2C_BUS_EXPANSION	1
#define PX4_I2C_BUS_LED		1

/*
 * Devices on the onboard bus.
 *
 * Note that these are unshifted addresses.
 */
#define PX4_I2C_OBDEV_HMC5883	0x1e
#define PX4_I2C_OBDEV_MS5611	0x77 // F4by
#define PX4_I2C_OBDEV_EEPROM	NOTDEFINED
#define PX4_I2C_OBDEV_LED	0x55

#define PX4_I2C_OBDEV_PX4IO_BL	0x18
#define PX4_I2C_OBDEV_PX4IO	0x1a

/* User GPIOs
 *
 * GPIO0-1 are the buffered high-power GPIOs.
 * GPIO2-5 are the USART2 pins.
 * GPIO6-7 are the CAN1 pins.
 */
#define GPIO_GPIO0_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN7)
#define GPIO_GPIO1_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN8)
#define GPIO_GPIO2_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN3)
#define GPIO_GPIO3_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN4)
#define GPIO_GPIO4_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN5)
#define GPIO_GPIO5_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN6)
#define GPIO_GPIO6_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN1)
#define GPIO_GPIO7_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTB|GPIO_PIN2)

#define GPIO_GPIO8_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTA|GPIO_PIN0)
#define GPIO_GPIO9_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTA|GPIO_PIN1)
#define GPIO_GPIO10_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTA|GPIO_PIN2)
#define GPIO_GPIO11_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTA|GPIO_PIN3)
#define GPIO_GPIO12_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN9)
#define GPIO_GPIO13_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN11)
#define GPIO_GPIO14_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN13)
#define GPIO_GPIO15_INPUT (GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN14)

#define GPIO_GPIO0_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN7)
#define GPIO_GPIO1_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN8)
#define GPIO_GPIO2_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN3)
#define GPIO_GPIO3_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN4)
#define GPIO_GPIO4_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN5)
#define GPIO_GPIO5_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN6)
#define GPIO_GPIO6_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN1)
#define GPIO_GPIO7_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN0)

#define GPIO_GPIO8_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTA|GPIO_PIN0)
#define GPIO_GPIO9_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTA|GPIO_PIN1)
#define GPIO_GPIO10_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTA|GPIO_PIN2)
#define GPIO_GPIO11_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTA|GPIO_PIN3)
#define GPIO_GPIO12_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN9)
#define GPIO_GPIO13_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN11)
#define GPIO_GPIO14_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN13)
#define GPIO_GPIO15_OUTPUT (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN14)



#define GPIO_GPIO_DIR (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN11)

/*
 * Tone alarm output
 */
#define TONE_ALARM_TIMER	9	/* timer 9 */
#define TONE_ALARM_CHANNEL	1	/* channel 1 */
#define GPIO_TONE_ALARM_IDLE	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN5)
#define GPIO_TONE_ALARM		(GPIO_ALT|GPIO_AF3|GPIO_SPEED_2MHz|GPIO_FLOAT|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN5)

/*
 * PWM
 *
 * Four PWM outputs can be configured on pins otherwise shared with
 * USART2; two can take the flow control pins if they are not being used.
 *
 * Pins:
 *
 * CTS - PA0 - TIM2CH1
 * RTS - PA1 - TIM2CH2
 * TX  - PA2 - TIM2CH3
 * RX  - PA3 - TIM2CH4
 *
 */
#define GPIO_TIM1_CH1OUT	GPIO_TIM1_CH1OUT_2 //F4BY
#define GPIO_TIM1_CH2OUT	GPIO_TIM1_CH2OUT_2 //F4BY
#define GPIO_TIM1_CH3OUT	GPIO_TIM1_CH3OUT_2 //F4BY
#define GPIO_TIM1_CH4OUT	GPIO_TIM1_CH4OUT_2 //F4BY
#define GPIO_TIM2_CH1OUT	GPIO_TIM2_CH1OUT_1
#define GPIO_TIM2_CH2OUT	GPIO_TIM2_CH2OUT_1
#define GPIO_TIM2_CH3OUT	GPIO_TIM2_CH3OUT_1
#define GPIO_TIM2_CH4OUT	GPIO_TIM2_CH4OUT_1

/* USB OTG FS
 *
 * PA9  OTG_FS_VBUS VBUS sensing (also connected to the green LED)
 */
#define GPIO_OTGFS_VBUS (GPIO_INPUT|GPIO_FLOAT|GPIO_SPEED_100MHz|GPIO_OPENDRAIN|GPIO_PORTA|GPIO_PIN9)

/* High-resolution timer
 */
#define HRT_TIMER		8	/* use timer3 for the HRT *///F4BY
#define HRT_TIMER_CHANNEL	1	/* use capture/compare channel 1 */
//#define HRT_PPM_CHANNEL		2	/* use capture/compare channel 2 *///F4BY
//#define GPIO_PPM_IN		(GPIO_ALT|GPIO_AF2|GPIO_SPEED_50MHz|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN7)//F4BY

/****************************************************************************************************
 * Public Types
 ****************************************************************************************************/

/****************************************************************************************************
 * Public data
 ****************************************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************************************
 * Public Functions
 ****************************************************************************************************/

/****************************************************************************************************
 * Name: stm32_spiinitialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the PX4FMU board.
 *
 ****************************************************************************************************/

extern void stm32_spiinitialize(void);

#endif /* __ASSEMBLY__ */

__END_DECLS
