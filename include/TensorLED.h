#include <Adafruit_NeoPixel.h>

#define PORT_A 32
#define PORT_B 26
#define PORT_C 13

#define NUM_LEDS 3

class TensorLED {
 public:
  TensorLED();

 private:
  Adafruit_NeoPixel m_pixels;
};