

#include <Arduino.h>
#include <U8g2lib.h> // lib ext
#include <SPI.h>
#include <Wire.h>
#include "FalconDED.h" // fornito ad-hoc
#include "constants.hpp"

// change here the define to pick which simulator to build for...

//#define DCS
#define FALCON_BMS

#ifdef DCS
#include "dcs_ded.hpp"
#endif
#ifdef FALCON_BMS
#include "bms_ded.hpp"
#endif


//Function | Nano Pin | OLED Pin
//---------+----------+----------
//DC       | 3        | 14    
//Reset    | 4        | 15
//CS       | 5        | 16
//Clock    | 13       | 4
//Data     | 11       | 5


//for SPI
//1 = VSS/ground
//2 = VDD/VCC +3.3v to +5.0v
//3 = NC
//4 = SCLK
//5 = SDIN (MOSI)
//6 = NC
//7-13 = GND
//14 = PIN_DC
//15 = PIN_RESET
//16 = PIN_CS

int clock = 13;
int data = 11;
int cs = 5;
int dc = 3;
int reset = 4;

// U8G2_SSD1322_NHD_256X64_1_4W_SW_SPI(rotation, clock, data, cs, dc [, reset])
//U8G2_SSD1322_NHD_256X64_1_4W_SW_SPI u8g2(U8G2_R0, clock, data, cs, dc, reset);

U8G2_SSD1322_NHD_256X64_2_4W_SW_SPI u8g2(U8G2_R0, clock, data, cs, dc, reset);


// data model, main prog state.
char DED[DED_LINES][LINE_LENGTH] = {
  "                       ",
  "    FalconDED v1.0     ",
  "                       ",
  "  Waiting for data...  ",
  "                       "
};


void setup(void) {
  #ifdef DCS
  dcs_setup();
  #endif
  #ifdef FALCON_BMS
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

  #ifdef FALCON_BMS
  bms_loop();
  #endif

  writeDED();
}