/*
    __altitude_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __altitude_driver.h
@brief    Altitude Driver
@mainpage Altitude Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   ALTITUDE
@brief      Altitude Click Driver
@{

| Global Library Prefix | **ALTITUDE** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Oct 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _ALTITUDE_H_
#define _ALTITUDE_H_

/** 
 * @macro T_ALTITUDE_P
 * @brief Driver Abstract type 
 */
#define T_ALTITUDE_P    const uint8_t*

/** @defgroup ALTITUDE_COMPILE Compilation Config */              /** @{ */

//  #define   __ALTITUDE_DRV_SPI__                            /**<     @macro __ALTITUDE_DRV_SPI__  @brief SPI driver selector */
   #define   __ALTITUDE_DRV_I2C__                            /**<     @macro __ALTITUDE_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __ALTITUDE_DRV_UART__                           /**<     @macro __ALTITUDE_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup ALTITUDE_VAR Variables */                           /** @{ */

extern const uint8_t _ALTITUDE_I2C_ADDRESS;

extern const uint8_t _ALTITUDE_STATUS;
extern const uint8_t _ALTITUDE_OUT_P_MSB;
extern const uint8_t _ALTITUDE_OUT_P_CSB;
extern const uint8_t _ALTITUDE_OUT_P_LSB;
extern const uint8_t _ALTITUDE_OUT_T_MSB;
extern const uint8_t _ALTITUDE_OUT_T_LSB;
extern const uint8_t _ALTITUDE_DR_STATUS;
extern const uint8_t _ALTITUDE_OUT_P_DELTA_MSB;
extern const uint8_t _ALTITUDE_OUT_P_DELTA_CSB;
extern const uint8_t _ALTITUDE_OUT_P_DELTA_LSB;
extern const uint8_t _ALTITUDE_OUT_T_DELTA_MSB;
extern const uint8_t _ALTITUDE_OUT_T_DELTA_LSB;
extern const uint8_t _ALTITUDE_WHO_AM_I;
extern const uint8_t _ALTITUDE_DEVICA_ID;
extern const uint8_t _ALTITUDE_F_STATUS;
extern const uint8_t _ALTITUDE_F_DATA;
extern const uint8_t _ALTITUDE_F_SETUP;
extern const uint8_t _ALTITUDE_TIME_DLY;
extern const uint8_t _ALTITUDE_SYSMOD;
extern const uint8_t _ALTITUDE_INT_SOURCE;
extern const uint8_t _ALTITUDE_PT_DATA_CFG;
extern const uint8_t _ALTITUDE_BAR_IN_MSB;
extern const uint8_t _ALTITUDE_BAR_IN_LSB;
extern const uint8_t _ALTITUDE_P_TGT_MSB;
extern const uint8_t _ALTITUDE_P_TGT_LSB;
extern const uint8_t _ALTITUDE_T_TGT;
extern const uint8_t _ALTITUDE_P_WND_MSB;
extern const uint8_t _ALTITUDE_P_WND_LSB;
extern const uint8_t _ALTITUDE_T_WND;
extern const uint8_t _ALTITUDE_P_MIN_MSB;
extern const uint8_t _ALTITUDE_P_MIN_CSB;
extern const uint8_t _ALTITUDE_P_MIN_LSB;
extern const uint8_t _ALTITUDE_T_MIN_MSB;
extern const uint8_t _ALTITUDE_T_MIN_LSB;
extern const uint8_t _ALTITUDE_P_MAX_MSB;
extern const uint8_t _ALTITUDE_P_MAX_CSB;
extern const uint8_t _ALTITUDE_P_MAX_LSB;
extern const uint8_t _ALTITUDE_T_MAX_MSB;
extern const uint8_t _ALTITUDE_T_MAX_LSB;
extern const uint8_t _ALTITUDE_CTRL_REG1;
extern const uint8_t _ALTITUDE_CTRL_REG2;
extern const uint8_t _ALTITUDE_CTRL_REG3;
extern const uint8_t _ALTITUDE_CTRL_REG4;
extern const uint8_t _ALTITUDE_CTRL_REG5;
extern const uint8_t _ALTITUDE_OFF_P;
extern const uint8_t _ALTITUDE_OFF_T;
extern const uint8_t _ALTITUDE_OFF_H;

extern const uint8_t _ALTITUDE_REGISTER_STATUS_TDR;
extern const uint8_t _ALTITUDE_REGISTER_STATUS_PDR;
extern const uint8_t _ALTITUDE_REGISTER_STATUS_PTDR;
extern const uint8_t _ALTITUDE_PT_DATA_CFG_NN;
extern const uint8_t _ALTITUDE_PT_DATA_CFG_TDEFE;
extern const uint8_t _ALTITUDE_PT_DATA_CFG_PDEFE;
extern const uint8_t _ALTITUDE_PT_DATA_CFG_DREM;
extern const uint8_t _ALTITUDE_CTRL_REG1_SBYB;
extern const uint8_t _ALTITUDE_CTRL_REG1_OST;
extern const uint8_t _ALTITUDE_CTRL_REG1_RST;
extern const uint8_t _ALTITUDE_CTRL_REG1_RAW;
extern const uint8_t _ALTITUDE_CTRL_REG1_ALT;
extern const uint8_t _ALTITUDE_CTRL_REG1_BAR;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS1;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS2;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS4;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS8;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS16;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS32;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS64;
extern const uint8_t _ALTITUDE_CTRL_REG1_OS128;

                                                                       /** @} */
/** @defgroup ALTITUDE_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup ALTITUDE_INIT Driver Initialization */              /** @{ */

#ifdef   __ALTITUDE_DRV_SPI__
void altitude_spiDriverInit(T_ALTITUDE_P gpioObj, T_ALTITUDE_P spiObj);
#endif
#ifdef   __ALTITUDE_DRV_I2C__
void altitude_i2cDriverInit(T_ALTITUDE_P gpioObj, T_ALTITUDE_P i2cObj, uint8_t slave);
#endif
#ifdef   __ALTITUDE_DRV_UART__
void altitude_uartDriverInit(T_ALTITUDE_P gpioObj, T_ALTITUDE_P uartObj);
#endif


/** @defgroup ALTITUDE_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write 8-bit data function
 *
 * @param[in] address         Register address
 *
 * @param[in] writeCommand    Command to write
 *
 * Function write 8-bit data to MPL3115A2 sensor.
 */
void altitude_writeData( uint8_t address, uint8_t writeCommand );

/**
 * @brief Generic read 8-bit data function
 *
 * @param[in] address         Register address
 *
 * @return
 * 8-bit data from addressed register from the MPL3115A2
 *
 * Function read 8-bit data from register address
 * of the MPL3115A2 sensor.
 */
uint8_t altitude_readData( uint8_t address );

/**
 * @brief Default Barometer mode sensor configuration
 *
 * Function set Barometer mode default configuration
 * by writing configuration register from the MPL3115A2 sensor.
 */
void altitude_defaultConfigBarometer();

/**
 * @brief Default Altitude mode sensor configuration
 *
 * Function set Altitude mode default configuration
 * by writing configuration register from the MPL3115A2 sensor.
 */
void altitude_defaultConfigAltitude();

/**
 * @brief Read pressure in Pascal function
 *
 * @return
 * float pressure data in Pascal [ Pa ]
 *
 * Function read and calculate pressure
 * in Pascal from the MPL3115A2 sensor.
 */
float altitude_getPressure();

/**
 * @brief Read temperature in degrees Celsius function
 *
 * @return
 * float temperature data degrees Celsius [ ºC ]
 *
 * Function read and calculate temperature
 * in degrees Celsius from the MPL3115A2 sensor.
 */
float altitude_getTemperature();

/**
 * @brief Read temperature in degrees of Fahrenheit function
 *
 * @return
 * float temperature data degrees Fahrenheit [ ºF ]
 *
 * Function read and calculate temperature
 * in degrees Fahrenheit from the MPL3115A2 sensor.
 */
float altitude_getTemperatureFahrenheit();

/**
 * @brief Read altitude value in meters function
 *
 * @return
 * float pressure data in meters [ m ]
 *
 * Function read and calculate pressure
 * in meters from the MPL3115A2 sensor.
 */
float altitude_getAltitude();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Altitude_STM.c
    @example Click_Altitude_TIVA.c
    @example Click_Altitude_CEC.c
    @example Click_Altitude_KINETIS.c
    @example Click_Altitude_MSP.c
    @example Click_Altitude_PIC.c
    @example Click_Altitude_PIC32.c
    @example Click_Altitude_DSPIC.c
    @example Click_Altitude_AVR.c
    @example Click_Altitude_FT90x.c
    @example Click_Altitude_STM.mbas
    @example Click_Altitude_TIVA.mbas
    @example Click_Altitude_CEC.mbas
    @example Click_Altitude_KINETIS.mbas
    @example Click_Altitude_MSP.mbas
    @example Click_Altitude_PIC.mbas
    @example Click_Altitude_PIC32.mbas
    @example Click_Altitude_DSPIC.mbas
    @example Click_Altitude_AVR.mbas
    @example Click_Altitude_FT90x.mbas
    @example Click_Altitude_STM.mpas
    @example Click_Altitude_TIVA.mpas
    @example Click_Altitude_CEC.mpas
    @example Click_Altitude_KINETIS.mpas
    @example Click_Altitude_MSP.mpas
    @example Click_Altitude_PIC.mpas
    @example Click_Altitude_PIC32.mpas
    @example Click_Altitude_DSPIC.mpas
    @example Click_Altitude_AVR.mpas
    @example Click_Altitude_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __altitude_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */