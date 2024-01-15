# Falcon DED
This is the software for Ardiuno (and hopefully ESP8266) to drive an OLED SPI display 

# The Wiring.
I have bought one of those: https://www.buydisplay.com/yellow-2-8-inch-arduino-raspberry-pi-oled-display-module-256x64-spi

having the following pinout behind (this is where most of my precious time has been spent):

| OLED PIN | Arduino UNO            | C++ constant   |
|:--------:|:----------------------:|----------------|
|1         | VSS/Ground (GND)       |                |
|2         | VDD/VCC +3.3v to 5.0v  |                |
|3         | NC                     |                |
|4         | SCLK       (pin 13)    | CLOCK          |
|5         | SDIN/MOSI  (pin 11)    | DATA           |
|6         | NC                     |                |
|7         | GND                    |                |
|8         | GND                    |                |
|9         | GND                    |                |
|10        | GND                    |                |
|11        | GND                    |                |
|12        | GND                    |                |
|13        | GND                    |                |
|14        | PIN_DC     (pin  9)    | DC             |
|15        | PIN_RESET  (pin  8)    | RESET          |
|16        | PIN_CS     (pin 10)    | CS             | 

