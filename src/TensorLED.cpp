#include <TensorLED.h>

TensorLED::TensorLED() {
  m_pixels.begin();
  m_pixels.setBrightness(10);
}

void TensorLED::setColor(char& colorInput) {
  switch (colorInput) {
    case 'r':
    // red
      m_pixels.setPixelColor(1, m_pixels.Color(100, 0, 0));
      break;

    case 'g':
    // green
      m_pixels.setPixelColor(1, m_pixels.Color(0, 100, 0));
      break;

    case 'b':
    // blue
      m_pixels.setPixelColor(1, m_pixels.Color(0, 0, 100));
      break;

    default:
      break;
  }

  m_pixels.show();
}

void TensorLED::setBrightness(const int brightness) {
    m_pixels.setBrightness(brightness);
}