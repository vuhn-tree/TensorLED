#include <Adafruit_NeoPixel.h>
#include <M5Core2.h>
#include <TensorLED.h>
#include <TensorServo.h>
#include <PinDefines.h>
// #include <sstream>

const int DISP_OFFSET = 25;

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

int potVal = 0;  // Stores the value currently read by the sensor.
char colorInput = 'g';

TensorServo* tensorServo{nullptr};
TensorLED* tensorLED{nullptr};

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

  // const int lcdPotVal = map(potVal, 0, 4096, 2500, 3300);
  // M5.Axp.SetLcdVoltage(lcdPotVal);

  // int counter = 0;
  // if (Serial.available() > 0) {
  //   // colorInput = Serial.read();
  //   // sprintf(buf, "[%d] color: %c", counter, colorInput);
  //   // M5.Lcd.drawString(buf, 0, DISP_OFFSET * 6, 4);
  //   // ++counter;
  //   // processIncomingByte(Serial.read());

  //   colorInput = Serial.read();
  //   sprintf(buf, "color: %c", colorInput);
  //   M5.Lcd.drawString(buf, 0, DISP_OFFSET * 6, 4);



  //   // std::string s = "scott>=tiger";
  //   // String str = Serial.readStringUntil('\n');
  //   // int test = Serial.parseInt();
  //   // std::string s = Serial.readString().c_str();
  //   // std::string delimiter = ">=";
  //   // std::string token = s.substr(0, s.find(">=")); // token is "scott"
  //   // sprintf(buf, "color: %d", test);
  //   // M5.Lcd.drawString(buf, 0, DISP_OFFSET * 4, 4);

  //   // std::string s = Serial.readString();
  //   // std::string delimiter = ">=";
  //   // std::string token = s.substr(0, s.find(delimiter)); // token is "scott"

  // }
  if(Serial.available()) {
   recvWithEndMarker();
    // sprintf(buf, "color: %s", receivedChars);
    std::string s = receivedChars;
M5.Lcd.drawString(s.c_str(), 0, DISP_OFFSET * 4, 4);

// std::string input("ab=xy z,time a=1s");
  // std::istringstream iss(s);

  // std::vector<Flag_name_value> flags;

  // std::string token;
  // // Flag_name_value flag;
  // while (std::getline(s, token, ',')) {
  //     size_t pos   = token.find('=');
  //     std::string name    = token.substr(0, pos);
  //     std::string value   = token.substr(pos + 1);
  //     // flags.push_back(flag);
  // }

//   std::string delimiter = ",";
//   // std::string token = s.substr(0, s.find(delimiter)); // token is "scott"

  char test1[] = "scott=foo,scott2=foo2\n";

  // char * ptr;
  // // while(ptr != NULL) {
  // ptr = strtok(receivedChars, "=");  //skip to first =
  // M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 2, 4);    
  // ptr = strtok(NULL, ",");  //get the diameter as a string
  // M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 4, 4);    


  // ptr = strtok(NULL, "=");  //skip to first =
  // M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 1, 4);    
  // ptr = strtok(NULL, ",");  //get the diameter as a string
  // M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 3, 4);    


  char * ptr;
  // // while(ptr != NULL) {
  ptr = strtok(receivedChars, ",");  //skip to first =
  M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 1, 4);    
  ptr = strtok(NULL, ",");  //get the diameter as a string
  M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 2, 4);    


  // ptr = strtok(NULL, "=");  //skip to first =
  // M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 1, 4);    
  ptr = strtok(NULL, ",");  //get the diameter as a string
  M5.Lcd.drawString(ptr, 0, DISP_OFFSET * 3, 4);    


  // }
  }

// size_t pos = 0;
// std::string token;
// while ((pos = s.find(delimiter)) != std::string::npos) {
//     token = s.substr(0, pos);

//     size_t pos   = token.find('=');
//     std::string name    = token.substr(0, pos);
//     std::string value   = token.substr(pos + 1);

//     // std::string fool = token.substr(0, token.find('+')); // token 
    
//     M5.Lcd.drawString(name.c_str(), 0, DISP_OFFSET * 4, 4);    
//     M5.Lcd.drawString(value.c_str(), 0, DISP_OFFSET * 2, 4);    
//     // std::cout << token << std::endl;
    
//     s.erase(0, pos + delimiter.length());
  
// }
// M5.Lcd.drawString(s.c_str(), 0, DISP_OFFSET * 3, 4);
    

  tensorLED->setColor(colorInput);
  // tensorServo->servo_angle_write(0, normalVal);
  // tensorServo->servo_angle_write(1, normalVal);

  delay(2000);

  if (M5.BtnA.read()) {
    M5.shutdown();
  }

  if (M5.BtnC.read()) {
    M5.Axp.SetLcdVoltage(3300);
  }
}