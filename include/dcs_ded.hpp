#pragma once

#define DCSBIOS_IRQ_SERIAL
#include "DcsBios.h"
#include "constants.hpp"

extern char DED[DED_LINES][LINE_LENGTH];

void onDedLine1Change(char* newValue) {
  strncpy(DED[0], newValue, LINE_LENGTH);
}
DcsBios::StringBuffer<25> dedLine1Buffer(0x4500, onDedLine1Change);

void onDedLine2Change(char* newValue) {  
  strncpy(DED[1], newValue, LINE_LENGTH);
}
DcsBios::StringBuffer<25> dedLine2Buffer(0x451a, onDedLine2Change);

void onDedLine3Change(char* newValue) {  
  strncpy(DED[2], newValue, LINE_LENGTH);
}
DcsBios::StringBuffer<25> dedLine3Buffer(0x4534, onDedLine3Change);

void onDedLine4Change(char* newValue) {    
  strncpy(DED[3], newValue, LINE_LENGTH);
}
DcsBios::StringBuffer<25> dedLine4Buffer(0x454e, onDedLine4Change);

void onDedLine5Change(char* newValue) {  
  strncpy(DED[4], newValue, LINE_LENGTH);
}
DcsBios::StringBuffer<25> dedLine5Buffer(0x4568, onDedLine5Change);


void dcs_setup() {
	strncpy(DED[4], "     Waiting DCS...", 19);
}

void dcs_loop() {
  DcsBios::loop();  
}

