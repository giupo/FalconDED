#ifndef DED_H 
#define DED_H

#include "constants.hpp"
#include <U8g2lib.h> // lib ext


/*
* this is the "model" of the application.
* here we store the lines coming from the simulation software and 
* render it on the OLED display
*/

class DED {
  public:

    /* nothing to do really here...*/
    DED() = default;
    ~DED() = default;
  
    /* @brief initializes the DED with the font*/
    void init(const uint8_t* font);

    /* @brief updates a line of the DED*/
    void update(const int line_number, const char* value);

    /* @brief to be called every loop to render on the OLED*/
    void render() const;
  private:
    char lines[DED_LINES][LINE_LENGTH] = {
      "FALCON DED 1.0             \0",
      "                           \0",
      "WAITING FOR DATA ...       \0",
      "                           \0", 
      "                           \0",
    };
};

#endif