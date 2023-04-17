#include <TensorLED.h>

TensorLED::TensorLED() {
  m_pixels.begin();
  m_pixels.setBrightness(10);
}

void TensorLED::setLEDColor(char& colorInput) {
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

void TensorLED::setLEDBrightness(const int brightness) {
    m_pixels.setBrightness(brightness);
}