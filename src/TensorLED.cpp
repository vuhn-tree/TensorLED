#include <TensorLED.h>

uint32_t RGB_RED;
// const uint32_t RGB_GREEN = m_pixels.Color(0, 100, 0);
// const uint32_t RGB_BLUE = m_pixels.Color(0, 0, 100);


  TensorLED::TensorLED() {
    m_pixels = Adafruit_NeoPixel(
    NUM_LEDS, PORT_B,
    NEO_GRB + NEO_KHZ800);  // set number of LEDs, pin number, LED type.
    m_pixels.begin();
    m_pixels.setBrightness(10);

    RGB_RED = m_pixels.Color(100, 0, 0);

  }