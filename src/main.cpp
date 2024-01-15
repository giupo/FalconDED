#include "constants.hpp"

#include <Arduino.h>
#include <U8g2lib.h> // lib ext

#include <SPI.h>


#include "fonts/FalconDED.h"
#include "fonts/DEDFont.h"

// change here the define to pick which simulator to build for...
#ifdef DCS_
#include "sim/dcs.hpp"
#endif

#ifdef BMS_
#include "sim/bms.hpp"
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

// U8G2_SSD1322_NHD_256X64_1_4W_SW_SPI(rotation, clock, data, cs, dc [, reset])
// U8G2_SSD1322_NHD_256X64_1_4W_SW_SPI u8g2(U8G2_R0, clock, data, cs, dc, reset);

//U8G2_SSD1322_NHD_256X64_2_4W_SW_SPI u8g2(U8G2_R0, CLOCK, DATA, CS, DC, RESET);

DED ded;

void setup(void) {
  ded.init(FalconDED);
  #ifdef DCS_
  DCS::setup();
  #endif

  #ifdef BMS_
  BMS::setup();
  #endif

}

void loop(void) {  
  #ifdef DCS_
  DCS::loop();
  #endif

  #ifdef BMS_
  BMS::loop();
  #endif

  ded.render();
}
