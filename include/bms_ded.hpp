#pragma once

#include "constants.hpp"

#include <Arduino.h>

#define BAUDRATE       9600
#define SERIAL_TIMEOUT  100

extern char DED[DED_LINES][LINE_LENGTH];

void bms_setup() {
	// setup USB/COM communications
	Serial.begin(BAUDRATE * 3);
  Serial.setTimeout(SERIAL_TIMEOUT);
	strncpy(DED[4], " Waiting Falcon BMS...", 22);
}

void bms_loop() {
  // read from COM data pumped from the Win32 Application
	// copy it into extern char DED
}