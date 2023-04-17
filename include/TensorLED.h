#include <Adafruit_NeoPixel.h>

#define PORT_A 32
#define PORT_B 26
#define PORT_C 13

#define NUM_LEDS 3

class TensorLED {
 public:
  TensorLED();
  void setColor(char& colorInput);
  void setLEDBrightness(const int brightness);

 private:
  Adafruit_NeoPixel m_pixels {Adafruit_NeoPixel(
      NUM_LEDS, PORT_B,
      NEO_GRB + NEO_KHZ800)};  // set number of LEDs, pin number, LED type.
};