
#include <TensorServo.h>

TensorServo::TensorServo() {
    m_pwm = Adafruit_PWMServoDriver(0x40, Wire1);
}