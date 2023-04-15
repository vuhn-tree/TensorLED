#include <TensorLED.h>

// uint32_t RGB_RED;
// uint32_t RGB_GREEN;
// uint32_t RGB_BLUE;

TensorLED::TensorLED() {
//   m_pixels = Adafruit_NeoPixel(
//       NUM_LEDS, PORT_B,
//       NEO_GRB + NEO_KHZ800);  // set number of LEDs, pin number, LED type.
  m_pixels.begin();
  m_pixels.setBrightness(10);

//   RGB_RED = m_pixels.Color(100, 0, 0);
//   RGB_GREEN = m_pixels.Color(0, 100, 0);
//   RGB_BLUE = m_pixels.Color(0, 0, 100);
}

void TensorLED::setLEDColor(char colorInput) {
  switch (colorInput) {
    case 'r':
      m_pixels.setPixelColor(1, m_pixels.Color(100, 0, 0));
      break;

    case 'g':
      m_pixels.setPixelColor(1, m_pixels.Color(0, 100, 0));
      break;

    case 'b':
      m_pixels.setPixelColor(1, m_pixels.Color(0, 0, 100));
      break;

    default:
      break;
  }

  m_pixels.show();
}