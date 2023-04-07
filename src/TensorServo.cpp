
#include <TensorServo.h>

TensorServo::TensorServo() {}

void TensorServo::setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  pulselength = 1000000;  // 1,000,000 us per second
  pulselength /= 50;      // 50 Hz
  Serial.print(pulselength);
  Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength);
  Serial.println(" us per bit");
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  m_pwm.setPWM(n, 0, pulse);
}

void TensorServo::servo_angle_write(uint8_t n, int Angle) {
  double pulse = Angle;
  pulse = pulse / 90 + 0.5;
  setServoPulse(n, pulse);
}