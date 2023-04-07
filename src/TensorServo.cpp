
#include <TensorServo.h>

TensorServo::TensorServo() {
  Wire1.begin(21, 22);
  m_pwm.begin();
  m_pwm.setPWMFreq(50);
}

void TensorServo::setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  pulselength = 1000000;  // 1,000,000 us per second
  pulselength /= 50;      // 50 Hz
  pulselength /= 4096;    // 12 bits of resolution
  pulse *= 1000;
  pulse /= pulselength;
  m_pwm.setPWM(n, 0, pulse);
}

void TensorServo::servo_angle_write(uint8_t n, int Angle) {
  double pulse = Angle;
  pulse = pulse / 90 + 0.5;
  setServoPulse(n, pulse);
}