![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Altitude Click

---

- **CIC Prefix**  : ALTITUDE
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Oct 2018.

---

### Software Support

We provide a library for the Altitude Click on our [LibStock](https://libstock.mikroe.com/projects/view/800/altitude-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control Altitude Click board. 
Library performs the communication with the device via I2C driver by writting to registers and by reading from registers.
If library set as default Altitude configuration, get Altitude data and calculate  to meters unit [ m ].
In default Barometer configuration mode, library get Pressure data, calculating and converts to Pascal unit [ Pa ],
and get Temperature data, calculating and convert to Celsius degree  [ °C ].

Key functions :

- ``` void altitude_writeData( uint8_t address, uint8_t writeCommand ) ``` - Generic write 8-bit data function
- ``` void altitude_defaultConfigAltitude() ``` - Default Altitude mode sensor configuration
- ``` float altitude_getAltitude() ``` - Read altitude value function

**Examples Description**

The application is composed of three sections :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, 
     set INT pin as input and CS pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     set default Altitude configuration and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Altitude Click board.
     Measured and calculate altitude ( meters ) from sensor,
     results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 5 sec.


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/800/altitude-click-example) page.

Other mikroE Libraries used in the example:

- I2C
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
