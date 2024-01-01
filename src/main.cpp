#include <Adafruit_NeoPixel.h>
#include <M5Core2.h>
#include <PinDefines.h>
#include <TensorLED.h>
#include <TensorServo.h>

const int DISP_OFFSET = 25;

const byte numChars = 32;
char receivedChars[numChars];  // an array to store the received data

boolean newData = false;

int potVal = 0;  // Stores the value currently read by the sensor.
char colorInput = 'g';

TensorServo* tensorServo{nullptr};
TensorLED* tensorLED{nullptr};

unsigned long waitTime = 1500;
unsigned long startTime = millis();

boolean potMode = false;
int lcdBrightness = 2500;
boolean servoReverse = false;
boolean servoWheelReverse = false;
int servoVal = 0;
int servoWheelVal = 0;
boolean stopServos = false;

int cur_value1 = 0, cur_value2 = 0;

void setup() {
  M5.begin();

  // pinMode(PORT_A, INPUT);  // Sets the specified pin to input mode.
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(PORT_C, INPUT);  // Sets the specified pin to input mode.

  M5.Axp.SetLcdVoltage(2600);
  M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  M5.Lcd.drawString("RGB Monitor", 0, 0, 4);
  M5.Axp.SetLcdVoltage(2600);

  Serial.begin(9600);

  tensorServo = new TensorServo();
  tensorLED = new TensorLED();
  tensorLED->setBrightness(120);
}

void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (rc == '\r')  // ignore carruage return
    {
      return;
    }
    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    } else {
      receivedChars[ndx] = '\0';  // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}

void loop() {
  M5.update();

  char buf[40];

  potVal = analogRead(PORT_C);  // read the value from the sensor.
  const int normalVal = map(potVal, 0, 4096, 0, 255);
  sprintf(buf, "Norm Pot: %03d%", normalVal);
  M5.Lcd.drawString(buf, 0, DISP_OFFSET * 5, 4);

  cur_value1 = digitalRead(32);  // read the value of BUTTON. 
  M5.Lcd.drawString(std::to_string(cur_value1).c_str(), 0, DISP_OFFSET * 2, 4);
  cur_value2 = digitalRead(33);  // read the value of BUTTON. 
  M5.Lcd.drawString(std::to_string(cur_value2).c_str(), 0, DISP_OFFSET * 3, 4);
  

  int counter = 0;
  while (Serial.available() > 0) {
    colorInput = Serial.read();
    sprintf(buf, "[%d] color: %c", counter, colorInput);
    M5.Lcd.drawString(buf, 0, DISP_OFFSET * 6, 4);
    ++counter;
  }

  // if(Serial.available() > 0) {
  //   recvWithEndMarker();
  //   std::string s = receivedChars;
  //   M5.Lcd.drawString(s.c_str(), 0, DISP_OFFSET * 4, 4);
  // }

  //   if (potMode) {
  //     tensorServo->servo_angle_write(0, normalVal);
  //   } else if (millis() - startTime >= waitTime) {
  //     long randomVal = random(0, 100);
  //     sprintf(buf, "Rand: %03ld%", randomVal);
  //     M5.Lcd.drawString(buf, 0, DISP_OFFSET * 3, 4);
  //    //  tensorServo->servo_angle_write(0, random(0, 100));
  //    //  tensorServo->servo_angle_write(1, random(0, 255));
  //     startTime = millis();
  //   }



if (stopServos == false) {
    tensorLED->setColor(colorInput);
  if (!potMode) {
    if (servoReverse) {
      servoVal--;
    } else {
      servoVal++;
    }

    tensorServo->servo_angle_write(0, servoVal);
    if (servoVal <= 0) {
      servoReverse = false;
    }
    if (servoVal >= 90) {
      servoReverse = true;
    }


    if (servoWheelReverse) {
      servoWheelVal--;
    } else {
      servoWheelVal++;
    }

    tensorServo->servo_angle_write(1, servoWheelVal);
   if (servoWheelVal <= 0) {
      servoWheelReverse = false;
    }
    if (servoWheelVal >= 255) {
      servoWheelReverse = true;
    }

  } else {
    tensorServo->servo_angle_write(0, normalVal);
  }

} 
// else {
//   if (M5.BtnA.read()) {
//     char red = 'r';
//     tensorLED->setColor(red);
//   }
//   if (M5.BtnB.read()) {
//     char green = 'g';
//     tensorLED->setColor(green);
//   }
//   if (M5.BtnC.read()) {
//     char blue = 'b';
//     tensorLED->setColor(blue);
//   }
// }
  
  if (!digitalRead(32)) {
        char red = 'r';
    tensorLED->setColor(red);
  }

  if (!digitalRead(33)) {
        char blue = 'b';
    tensorLED->setColor(blue);
  
  }

  if (!digitalRead(33) && !digitalRead(32)) {
        char green = 'g';
    tensorLED->setColor(green);
  }

  delay(20);

    if (M5.BtnA.read()) {
    // M5.shutdown();
    
    stopServos = true;
    tensorServo->servo_angle_write(1, 45);
    tensorServo->servo_angle_write(0, 45);
  }

  if (M5.BtnB.read()) {
    potMode = !potMode;
  }

  if (M5.BtnC.read()) {
    if (lcdBrightness == 3300) {
      lcdBrightness = 2500;
    } else {
      lcdBrightness += 200;
    }
    M5.Axp.SetLcdVoltage(lcdBrightness);
  }
}