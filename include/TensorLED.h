#include <Adafruit_NeoPixel.h>
#include <PinDefines.h>

#define NUM_LEDS 3

class TensorLED {
 public:
  TensorLED();
  void setColor(char& colorInput);
  void setBrightness(const int brightness);

 private:
  Adafruit_NeoPixel m_pixels {Adafruit_NeoPixel(
      NUM_LEDS, PORT_B,
      NEO_GRB + NEO_KHZ800)};  // set number of LEDs, pin number, LED type.
};