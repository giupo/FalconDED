#include "constants.hpp"

#include <Arduino.h>
#include <U8g2lib.h> // lib ext

#include <SPI.h>
#include <Wire.h>

#include "FalconDED.h" // fornito ad-hoc

#include <HardwareSerial.h>
// change here the define to pick which simulator to build for...

#ifdef DCS
#include "dcs_ded.hpp"
#endif

#ifdef BMS
#include "bms_ded.hpp"
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


// U8G2_SSD1322_NHD_256X64_1_4W_SW_SPI(rotation, clock, data, cs, dc [, reset])
// U8G2_SSD1322_NHD_256X64_1_4W_SW_SPI u8g2(U8G2_R0, clock, data, cs, dc, reset);

U8G2_SSD1322_NHD_256X64_2_4W_SW_SPI u8g2(U8G2_R0, CLOCK, DATA, CS, DC, RESET);


// data model, main prog state.
char DED[DED_LINES][LINE_LENGTH] = {
  "                       ",
  "   FalconDED v1.0      ",
  "                       ",
  " Waiting for data...   ",
  "                       "
};


void setup(void) {
  #ifdef DCS
  dcs_setup();
  #endif

  #ifdef BMS
  bms_setup();
  #endif

  u8g2.begin();  
  u8g2.setFont(FalconDED);  
}

void writeDED() {
  u8g2.firstPage();
  do {
    for(uint8_t i = 0; i < DED_LINES; i++) {
      u8g2.drawStr(START_POINT, DED_LINE_HEIGHT * (i + 1), DED[i]); 
    }
  } while ( u8g2.nextPage() );
}



void loop(void) {  
  #ifdef DCS
  dcs_loop();
  #endif

  #ifdef BMS
  bms_loop();
  #endif

  writeDED();
}
