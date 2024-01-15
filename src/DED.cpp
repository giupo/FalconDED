#include "ded/DED.hpp"

#include <Arduino.h> // for strncpy

#include "constants.hpp"

U8G2_SSD1322_NHD_256X64_2_4W_SW_SPI oled(U8G2_R0, CLOCK, DATA, CS, DC, RESET);

void DED::init(const uint8_t* font) {
  oled.begin();  
  oled.setFont(font); 
}

void DED::update(const int line_number, const char* value) {
  if (line_number > DED_LINES) return;
  strncpy(lines[line_number], value, LINE_LENGTH);
}

void DED::render() const {
  oled.firstPage();

  do {
    
    for(uint8_t line_number = 0; line_number < DED_LINES; line_number++) {
      oled.drawStr(START_POINT, DED_LINE_HEIGHT * (line_number + 1), lines[line_number]); 
    }

  } while ( oled.nextPage() );
}