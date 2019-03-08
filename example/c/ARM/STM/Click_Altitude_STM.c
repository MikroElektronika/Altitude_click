/*
Example for Altitude Click

    Date          : Oct 2018.
    Author        : Nenad Filipovic

Test configuration STM32 :
    
    MCU              : STM32F107VCT6
    Dev. Board       : EasyMx PRO v7 for STM32
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, 
     set INT pin as input and CS pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     set default Altitude configuration and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Altitude Click board.
     Measured and calculate altitude ( meters ) from sensor,
     results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 5 sec.

Additional Functions :

- UART
- Conversions

*/

#include "Click_Altitude_types.h"
#include "Click_Altitude_config.h"


float altitude;
char logText[50];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_ALTITUDE_I2C_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    altitude_i2cDriverInit( (T_ALTITUDE_P)&_MIKROBUS1_GPIO, (T_ALTITUDE_P)&_MIKROBUS1_I2C, _ALTITUDE_I2C_ADDRESS );

    altitude_defaultConfigAltitude();
    
    if ( altitude_readData( _ALTITUDE_WHO_AM_I ) == _ALTITUDE_DEVICA_ID )
        mikrobus_logWrite( "    Altitude Click", _LOG_LINE );
    else
        mikrobus_logWrite( "          ERROR", _LOG_LINE );

    mikrobus_logWrite( "-------------------------", _LOG_LINE );
    
    Delay_1sec();
    Delay_1sec();
    Delay_1sec();
}

void applicationTask()
{
    altitude = altitude_getAltitude();
    Delay_100ms();

    FloatToStr( altitude, logText );
    mikrobus_logWrite( " Altitude:    ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( " m", _LOG_LINE );
    mikrobus_logWrite( "-------------------------", _LOG_LINE );

    Delay_1sec();
    Delay_1sec();
    Delay_1sec();
    Delay_1sec();
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}