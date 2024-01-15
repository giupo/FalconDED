#pragma once

#ifdef BMS_

#include "constants.hpp"
#include "ded/DED.hpp"

extern DED ded;

namespace BMS {
  void setup() {
	  // setup USB/COM communications
	  Serial.begin(BAUDRATE * 3);
	  Serial.setTimeout(SERIAL_TIMEOUT);
	  ded.update(4, "WAITING FOR BMS ...");
  }

  void loop() {
    // read from COM data pumped from the Win32 Application
	  // copy it into extern char DED
  }
}

#endif // BMS_