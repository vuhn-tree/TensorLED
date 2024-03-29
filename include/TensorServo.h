#ifndef TENSOR_SERVO_H
#define TENSOR_SERVO_H

#include <PinDefines.h>
#include <Wire.h>

#include "Adafruit_PWMServoDriver.h"

#define SERVOMIN 102  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 512  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN \
  500  // This is the rounded 'minimum' microsecond length based on the minimum
       // pulse of 102
#define USMAX \
  2500  // This is the rounded 'maximum' microsecond length based on the maximum
        // pulse of 512
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

class TensorServo {
 public:
  TensorServo();
  void setServoPulse(uint8_t n, double pulse);
  void servo_angle_write(uint8_t n, int Angle);

 private:
  Adafruit_PWMServoDriver m_pwm{Adafruit_PWMServoDriver(0x40, Wire1)};
};

#endif // TENSOR_SERVO_H