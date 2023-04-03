#include <Wire.h>

#include "Adafruit_PWMServoDriver.h"

// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire1);
class TensorServo {
public:
  TensorServo();

private:
  Adafruit_PWMServoDriver m_pwm;
//   Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire1);
};