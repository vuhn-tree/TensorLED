#include <TensorLED.h>

  TensorLED::TensorLED() {
    m_pixels = Adafruit_NeoPixel(
    NUM_LEDS, PORT_B,
    NEO_GRB + NEO_KHZ800);  // set number of LEDs, pin number, LED type.
    m_pixels.begin();
    m_pixels.setBrightness(10);
  }