#pragma once

#ifdef DCS_

#include "constants.hpp"
#include "DcsBios.h"

#include "ded/DED.hpp"

#define LINE1_ADDR 0x4500
#define LINE2_ADDR 0x451e
#define LINE3_ADDR 0x453c
#define LINE4_ADDR 0x455c
#define LINE5_ADDR 0x4578

extern DED ded;


// Line 1 handler
void onDedLine1Change(char* newValue) {
  ded.update(0, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine1Buffer(LINE1_ADDR, onDedLine1Change);

// Line 2 handler
void onDedLine2Change(char* newValue) {  
  ded.update(1, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine2Buffer(LINE2_ADDR, onDedLine2Change);

// Line 3 handler
void onDedLine3Change(char* newValue) {  
  ded.update(2, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine3Buffer(LINE3_ADDR, onDedLine3Change);

// Line 4 handler
void onDedLine4Change(char* newValue) {    
  ded.update(3, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine4Buffer(LINE4_ADDR, onDedLine4Change);

// Line 5 handler
void onDedLine5Change(char* newValue) {  
  ded.update(4, newValue);
}
DcsBios::StringBuffer<LINE_LENGTH> dedLine5Buffer(LINE5_ADDR, onDedLine5Change);

namespace DCS {
  void setup() {
	  ded.update(4, "WAITING DCS ...");
  }

  void loop() {
    DcsBios::loop();
    DcsBios::loop();
    DcsBios::loop();  
  }
}

#endif // DCS_