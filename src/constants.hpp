#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// Falcon BaudRate

#ifdef BMS
constexpr int BAUDRATE        = 9600;
constexpr int SERIAL_TIMEOUT  =  100;
#endif

// screen dimensions 

constexpr int LINE_LENGTH     =   24;
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

#endif
