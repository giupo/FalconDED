#include <Arduino.h>
#include <U8g2lib.h> // lib ext
#include <SPI.h>
#include <Wire.h>
#include "FalconDED_full.h" // fornito ad-hoc



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

char DED[5][25] = {{ 0 }};

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  u8g2.firstPage();
  do {
   // u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setFont(u8g2_font_t0_12_me );
    u8g2.drawStr( 0,   10, "Ares");
    u8g2.drawStr(12,   20, "Vorrei");
    u8g2.drawStr(12*3, 30, "Aiutarti");
    u8g2.drawStr(12*5, 40, "Ma");
    u8g2.drawStr(12*7, 50, "Non so come fare :)");
  } while ( u8g2.nextPage() );
  delay(1000);
}