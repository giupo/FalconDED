#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// Falcon BaudRate

#ifdef BMS_
constexpr int BAUDRATE        = 9600;
constexpr int SERIAL_TIMEOUT  =  100;
#endif

// screen dimensions 

constexpr int LINE_LENGTH     =   29;
constexpr int DED_LINES       =    5;
constexpr int DED_LINE_HEIGHT =   12;
constexpr int START_POINT     =   30;

#ifdef TARGET_ESP
#define DCSBIOS_ESP8266
#define DCSBIOS_DEFAULT_SERIAL
#endif

#ifdef TARGET_UNO
#define DCSBIOS_IRQ_SERIAL
#endif




/*

Pin Connections:

OLED PIN  | Arduino UNO            | C++ var
1         | VSS/Ground (GND)       |
2         | VDD/VCC +3.3v to 5.0v  | 
3         | NC                     |
4         | SCLK (pin 13)          | CLOCK
5         | SDIN/MOSI (pin 11)     | DATA
6         | NC                     |
7         | GND                    |
8         | GND                    |
9         | GND                    |
10        | GND                    |
11        | GND                    |
12        | GND                    |
13        | GND                    |
14        | PIN_DC (pin 9)         | DC
15        | PIN_RESET (pin 8)      | RESET
16        | PIN_CS                 | CS


*Keep in mind* that pin 7/13 are noted as GND but they can be NC (not connected)
*/

constexpr int CLOCK = 13;
constexpr int DATA = 11;
constexpr int CS  = 10;
constexpr int DC = 9;
constexpr int RESET = 8;


#endif
