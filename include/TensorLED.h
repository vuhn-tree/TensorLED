#include <Adafruit_NeoPixel.h>

#define PORT_A 32
#define PORT_B 26
#define PORT_C 13

#define NUM_LEDS 3

// const uint32_t RGB_RED = m_pixels.Color(100, 0, 0);
// const uint32_t RGB_GREEN = m_pixels.Color(0, 100, 0);
// const uint32_t RGB_BLUE = m_pixels.Color(0, 0, 100);

class TensorLED {
 public:
  TensorLED();
  
 private:
  Adafruit_NeoPixel m_pixels;
};