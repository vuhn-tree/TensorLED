#include <Adafruit_NeoPixel.h>
#include <M5Core2.h>
#include <TensorLED.h>
#include <TensorServo.h>
#include <PinDefines.h>

const int DISP_OFFSET = 25;

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

int potVal = 0;  // Stores the value currently read by the sensor.
char colorInput = 'g';

TensorServo* tensorServo{nullptr};
TensorLED* tensorLED{nullptr};

unsigned long waitTime = 3000; // ms
unsigned long startTime = millis();

void setup() {
  M5.begin();

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
 
void recvWithEndMarker()
{
   static byte ndx = 0;
   char endMarker = '\n';
   char rc;

   while (Serial.available() > 0 && newData == false)
   {
      rc = Serial.read();
      if (rc == '\r') // ignore carruage return
      {
         return;
      }
      if (rc != endMarker)
      {
         receivedChars[ndx] = rc;
         ndx++;
         if (ndx >= numChars)
         {
            ndx = numChars - 1;
         }
      }
      else
      {
         receivedChars[ndx] = '\0'; // terminate the string
         ndx = 0;
         newData = true;
      }
   }
}

void loop() {
  M5.update();

  char buf[40];

  // const float powerTemp = M5.Axp.GetTempInAXP192();
  // sprintf(buf, "Powr Temp: %2.1fC", powerTemp);
  // M5.Lcd.drawString(buf, 0, DISP_OFFSET, 4);

  // const float batV = M5.Axp.GetBatVoltage();
  // const float batA = M5.Axp.GetBatCurrent();
  // sprintf(buf, "Batt.: %2.2fV %2.1fmA", batV, batA);
  // M5.Lcd.drawString(buf, 0, DISP_OFFSET * 2, 4);

  // const float busV = M5.Axp.GetVBusVoltage();
  // const float busA = M5.Axp.GetVBusCurrent();
  // sprintf(buf, "VBUS: %2.2fV %2.1fmA", busV, busA);
  // M5.Lcd.drawString(buf, 0, DISP_OFFSET * 3, 4);

  // const float vinV = M5.Axp.GetVinVoltage();
  // const float vinA = M5.Axp.GetVinCurrent();
  // sprintf(buf, "vin: %2.2fV %2.1fmA", vinV, vinA);
  // M5.Lcd.drawString(buf, 0, DISP_OFFSET * 4, 4);

  potVal = analogRead(PORT_C);  // read the value from the sensor.
  const int normalVal = map(potVal, 0, 4096, 0, 255);
  sprintf(buf, "Norm Pot: %03d%", normalVal);
  M5.Lcd.drawString(buf, 0, DISP_OFFSET * 5, 4);

  int counter = 0;
  while(Serial.available() > 0) {
    colorInput = Serial.read();
    sprintf(buf, "[%d] color: %c", counter, colorInput);
    M5.Lcd.drawString(buf, 0, DISP_OFFSET * 6, 4);
    ++counter;
  }
  // if(Serial.available() > 0) {
  //   recvWithEndMarker();
  //   std::string s = receivedChars;
  //   M5.Lcd.drawString(s.c_str(), 0, DISP_OFFSET * 4, 4);

  // std::string delimiter = ",";

  // size_t pos = 0;
  // std::string token;

  // pos = s.find(delimiter);
  // token = s.substr(0, pos);
  // M5.Lcd.drawString(token.c_str(), 0, DISP_OFFSET * 1, 4); 
  // s.erase(0, pos + delimiter.length());


  // pos = s.find(delimiter);
  // token = s.substr(0, pos);
  // M5.Lcd.drawString(token.c_str(), 0, DISP_OFFSET * 2, 4); 
  // s.erase(0, pos + delimiter.length());

  // pos = s.find(delimiter);
  // token = s.substr(0, pos);
  // M5.Lcd.drawString(token.c_str(), 0, DISP_OFFSET * 3, 4); 
  // s.erase(0, pos + delimiter.length());

  // }

  if(millis() - startTime >= waitTime) {
    long randomVal = random(0, 100);
    sprintf(buf, "Rand: %03ld%", randomVal);
    M5.Lcd.drawString(buf, 0, DISP_OFFSET * 3, 4);
    tensorServo->servo_angle_write(0, random(0, 100));   
     startTime = millis();
  }

  tensorLED->setColor(colorInput);
  // tensorServo->servo_angle_write(0, normalVal);
  // tensorServo->servo_angle_write(1, normalVal);

  delay(20);

  if (M5.BtnA.read()) {
    M5.shutdown();
  }

  if (M5.BtnC.read()) {
    M5.Axp.SetLcdVoltage(3300);
  }
}