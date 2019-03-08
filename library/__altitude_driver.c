/*
    __altitude_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__altitude_driver.h"
#include "__altitude_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __ALTITUDE_DRV_I2C__
static uint8_t _slaveAddress;
#endif

// I2C SLAVE ADDRESS
const uint8_t _ALTITUDE_I2C_ADDRESS                                      = 0x60;

// REGISTER MAP
const uint8_t _ALTITUDE_STATUS                                           = 0x00;
// Pressure/Altitude data (MSB)
const uint8_t _ALTITUDE_OUT_P_MSB                                        = 0x01;
// Pressure/Altitude data (middle)
const uint8_t _ALTITUDE_OUT_P_CSB                                        = 0x02;
// Pressure/Altitude data (LSB)
const uint8_t _ALTITUDE_OUT_P_LSB                                        = 0x03;
// Temperature data (MSB)
const uint8_t _ALTITUDE_OUT_T_MSB                                        = 0x04;
// Temperature data (LSB)
const uint8_t _ALTITUDE_OUT_T_LSB                                        = 0x05;
const uint8_t _ALTITUDE_DR_STATUS                                        = 0x06;
const uint8_t _ALTITUDE_OUT_P_DELTA_MSB                                  = 0x07;
const uint8_t _ALTITUDE_OUT_P_DELTA_CSB                                  = 0x08;
const uint8_t _ALTITUDE_OUT_P_DELTA_LSB                                  = 0x09;
const uint8_t _ALTITUDE_OUT_T_DELTA_MSB                                  = 0x0A;
const uint8_t _ALTITUDE_OUT_T_DELTA_LSB                                  = 0x0B;
const uint8_t _ALTITUDE_WHO_AM_I                                         = 0x0C;
const uint8_t _ALTITUDE_DEVICA_ID                                        = 0xC4;
const uint8_t _ALTITUDE_F_STATUS                                         = 0x0D;
const uint8_t _ALTITUDE_F_DATA                                           = 0x0E;
const uint8_t _ALTITUDE_F_SETUP                                          = 0x0F;
const uint8_t _ALTITUDE_TIME_DLY                                         = 0x10;
const uint8_t _ALTITUDE_SYSMOD                                           = 0x11;
const uint8_t _ALTITUDE_INT_SOURCE                                       = 0x12;
const uint8_t _ALTITUDE_PT_DATA_CFG                                      = 0x13;
const uint8_t _ALTITUDE_BAR_IN_MSB                                       = 0x14;
const uint8_t _ALTITUDE_BAR_IN_LSB                                       = 0x15;
const uint8_t _ALTITUDE_P_TGT_MSB                                        = 0x16;
const uint8_t _ALTITUDE_P_TGT_LSB                                        = 0x17;
const uint8_t _ALTITUDE_T_TGT                                            = 0x18;
const uint8_t _ALTITUDE_P_WND_MSB                                        = 0x19;
const uint8_t _ALTITUDE_P_WND_LSB                                        = 0x1A;
const uint8_t _ALTITUDE_T_WND                                            = 0x1B;
const uint8_t _ALTITUDE_P_MIN_MSB                                        = 0x1C;
const uint8_t _ALTITUDE_P_MIN_CSB                                        = 0x1D;
const uint8_t _ALTITUDE_P_MIN_LSB                                        = 0x1E;
const uint8_t _ALTITUDE_T_MIN_MSB                                        = 0x1F;
const uint8_t _ALTITUDE_T_MIN_LSB                                        = 0x20;
const uint8_t _ALTITUDE_P_MAX_MSB                                        = 0x21;
const uint8_t _ALTITUDE_P_MAX_CSB                                        = 0x22;
const uint8_t _ALTITUDE_P_MAX_LSB                                        = 0x23;
const uint8_t _ALTITUDE_T_MAX_MSB                                        = 0x24;
const uint8_t _ALTITUDE_T_MAX_LSB                                        = 0x25;
const uint8_t _ALTITUDE_CTRL_REG1                                        = 0x26;
const uint8_t _ALTITUDE_CTRL_REG2                                        = 0x27;
const uint8_t _ALTITUDE_CTRL_REG3                                        = 0x28;
const uint8_t _ALTITUDE_CTRL_REG4                                        = 0x29;
const uint8_t _ALTITUDE_CTRL_REG5                                        = 0x2A;
const uint8_t _ALTITUDE_OFF_P                                            = 0x2B;
const uint8_t _ALTITUDE_OFF_T                                            = 0x2C;
const uint8_t _ALTITUDE_OFF_H                                            = 0x2D;

// COMMAND BITS
/* Status register bits */
const uint8_t _ALTITUDE_REGISTER_STATUS_TDR                              = 0x02;
const uint8_t _ALTITUDE_REGISTER_STATUS_PDR                              = 0x04;
const uint8_t _ALTITUDE_REGISTER_STATUS_PTDR                             = 0x08;
/* PT DATA register bits */
const uint8_t _ALTITUDE_PT_DATA_CFG_NN                                   = 0x13;
const uint8_t _ALTITUDE_PT_DATA_CFG_TDEFE                                = 0x01;
const uint8_t _ALTITUDE_PT_DATA_CFG_PDEFE                                = 0x02;
const uint8_t _ALTITUDE_PT_DATA_CFG_DREM                                 = 0x04;
/* Control register bits */
const uint8_t _ALTITUDE_CTRL_REG1_SBYB                                   = 0x01;
const uint8_t _ALTITUDE_CTRL_REG1_OST                                    = 0x02;
const uint8_t _ALTITUDE_CTRL_REG1_CLR                                    = 0x03;
const uint8_t _ALTITUDE_CTRL_REG1_RST                                    = 0x04;
const uint8_t _ALTITUDE_CTRL_REG1_RAW                                    = 0x40;
const uint8_t _ALTITUDE_CTRL_REG1_ALT                                    = 0x80;
const uint8_t _ALTITUDE_CTRL_REG1_BAR                                    = 0x00;
/* Oversample values */
const uint8_t _ALTITUDE_CTRL_REG1_OS1                                    = 0x00;
const uint8_t _ALTITUDE_CTRL_REG1_OS2                                    = 0x08;
const uint8_t _ALTITUDE_CTRL_REG1_OS4                                    = 0x10;
const uint8_t _ALTITUDE_CTRL_REG1_OS8                                    = 0x18;
const uint8_t _ALTITUDE_CTRL_REG1_OS16                                   = 0x20;
const uint8_t _ALTITUDE_CTRL_REG1_OS32                                   = 0x28;
const uint8_t _ALTITUDE_CTRL_REG1_OS64                                   = 0x30;
const uint8_t _ALTITUDE_CTRL_REG1_OS128                                  = 0x38;
const int8_t _ALTITUDE_TEMP_CONST                                        = 0xF4;

/* Starting altitude to calculate mean sea level pressure in meters */
const float _ALTITUDE_START_ALTITUDE                                     = 89.0;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __ALTITUDE_DRV_SPI__

void altitude_spiDriverInit(T_ALTITUDE_P gpioObj, T_ALTITUDE_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __ALTITUDE_DRV_I2C__

void altitude_i2cDriverInit(T_ALTITUDE_P gpioObj, T_ALTITUDE_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __ALTITUDE_DRV_UART__

void altitude_uartDriverInit(T_ALTITUDE_P gpioObj, T_ALTITUDE_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */

/* Generic write 8-bit data function */
void altitude_writeData( uint8_t address, uint8_t writeCommand )
{
    uint8_t buffer[2];
    buffer[0]= address;
    buffer[1]= writeCommand;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 2, END_MODE_STOP );
}

/* Generic read data function */
uint8_t altitude_readData( uint8_t address )
{
    uint8_t writeReg[1];
    uint8_t readReg[1];

    writeReg[0] = address;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, readReg, 1, END_MODE_STOP );

    return readReg[0];
}

/* Default Barometer mode sensor configuration */
void altitude_defaultConfigBarometer()
{
    // Part is in Barometer mode                         _ALTITUDE_CTRL_REG1_BAR
    // Oversample ratio                                  _ALTITUDE_CTRL_REG1_OS128
    // Active mode clear                                 _ALTITUDE_CTRL_REG1_CLR
    altitude_writeData( _ALTITUDE_CTRL_REG1, _ALTITUDE_CTRL_REG1_BAR | _ALTITUDE_CTRL_REG1_OS128 | _ALTITUDE_CTRL_REG1_CLR );

    // Part is in Barometer mode                         _ALTITUDE_CTRL_REG1_BAR
    // Oversample ratio                                  _ALTITUDE_CTRL_REG1_OS128
    // Active mode                                       _ALTITUDE_CTRL_REG1_SBYB
    altitude_writeData( _ALTITUDE_CTRL_REG1, _ALTITUDE_CTRL_REG1_BAR | _ALTITUDE_CTRL_REG1_OS128 | _ALTITUDE_CTRL_REG1_SBYB );
}

/* Default Altitude mode sensor configuration */
void altitude_defaultConfigAltitude()
{
    // Part is in altimeter mode                         _ALTITUDE_CTRL_REG1_ALT
    // Oversample ratio                                  _ALTITUDE_CTRL_REG1_OS128
    // Active mode clear                                 _ALTITUDE_CTRL_REG1_CLR
    altitude_writeData( _ALTITUDE_CTRL_REG1, _ALTITUDE_CTRL_REG1_ALT | _ALTITUDE_CTRL_REG1_OS128 | _ALTITUDE_CTRL_REG1_CLR );

    // Part is in altimeter mode                         _ALTITUDE_CTRL_REG1_ALT
    // Oversample ratio                                  _ALTITUDE_CTRL_REG1_OS128
    // Active mode                                       _ALTITUDE_CTRL_REG1_SBYB
    altitude_writeData( _ALTITUDE_CTRL_REG1, _ALTITUDE_CTRL_REG1_ALT | _ALTITUDE_CTRL_REG1_OS128 | _ALTITUDE_CTRL_REG1_SBYB );
}



/* Read barometric pressure value function */
float altitude_getPressure()
{
    uint8_t buffer[3];
    uint32_t result;
    float pressure;
    float pressureFracValue;

    buffer[0] = altitude_readData( _ALTITUDE_OUT_P_MSB );
    buffer[1] = altitude_readData( _ALTITUDE_OUT_P_CSB );
    buffer[2] = altitude_readData( _ALTITUDE_OUT_P_LSB );

    result = buffer[0];
    result <<= 8;
    result |= buffer[1];
    result <<= 8;
    result |= buffer[2];

    result >>= 6;
    
    pressureFracValue = 0;

    if (buffer[2].B5 == 1)
        pressureFracValue += 0.5;
    if (buffer[2].B4 == 1)
        pressureFracValue += 0.25;

    pressure = ( float ) result + pressureFracValue;

    return pressure;
}

/* Read temperature in degrees of Celsius function */
float altitude_getTemperature()
{
    uint8_t buffer[2];
    float temperature;
    float temperatureFracValue;
    temperature = 0.0;
    temperatureFracValue = 0.0;

    buffer[0] = altitude_readData( _ALTITUDE_OUT_T_MSB );
    buffer[1] = altitude_readData( _ALTITUDE_OUT_T_LSB );

    temperature = ( float ) buffer[0];

    if (buffer[1].B7 == 1)
        temperatureFracValue += 0.5;
    if (buffer[1].B6 == 1)
        temperatureFracValue += 0.25;
    if (buffer[1].B5 == 1)
        temperatureFracValue += 0.125;
    if (buffer[1].B4 == 1)
        temperatureFracValue += 0.0625;

    temperature += temperatureFracValue;

    return temperature;
}

/* Read temperature in degrees of Fahrenheit function */
float altitude_getTemperatureFahrenheit()
{
    float temperature;

    temperature = altitude_getTemperature();
    temperature = ( ( temperature * 9.0 ) /  5.0 + 32.0 );
    
    return temperature;
}

/* Read altitude value function */
float altitude_getAltitude()
{
    uint8_t buffer[3];
    uint32_t result;
    uint8_t checkStatus;
    float altitude;
    float altitudeFracValue;
    altitude = 0.0;
    altitudeFracValue = 0.0;

    buffer[0] = altitude_readData( _ALTITUDE_OUT_P_MSB );
    buffer[0] = altitude_readData( _ALTITUDE_OUT_P_CSB );
    buffer[1] = altitude_readData( _ALTITUDE_OUT_P_LSB );

    result = buffer[0];
    result <<= 8;
    result |= buffer[1];
    result <<= 8;
    result |= buffer[2];

    altitude = ( float ) result ;

    if (buffer[2].B7 == 1)
        altitudeFracValue += 0.5;
    if (buffer[2].B6 == 1)
        altitudeFracValue += 0.25;
    if (buffer[2].B5 == 1)
        altitudeFracValue += 0.125;
    if (buffer[2].B4 == 1)
        altitudeFracValue += 0.0625;

    altitude /= 65535.00;
    altitude += _ALTITUDE_START_ALTITUDE;
    altitude += altitudeFracValue;

    return altitude;
}





/* -------------------------------------------------------------------------- */
/*
  __altitude_driver.c

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