#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>

#define PIN 32       // Port A
#define NUMPIXELS 3  

const int INFO_HEIGHT_POS = 25;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
    NUMPIXELS, PIN,
    NEO_GRB +
        NEO_KHZ800);  //set number of LEDs, pin number, LED type.

uint32_t RGB_RED = pixels.Color(100, 0, 0);
uint32_t RGB_GREEN = pixels.Color(0, 100, 0);
uint32_t RGB_BLUE = pixels.Color(0, 0, 100);

void setup() {
  M5.begin();      
  pixels.begin();  


  M5.Axp.SetLcdVoltage(2600);
  M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  M5.Lcd.drawString("RGB Monitor", 0, 0, 4);
}

int i = 0, j = 1, k = 2;

void loop() {
  M5.update();

  char buf[50];

  const float powerTemp = M5.Axp.GetTempInAXP192();
  sprintf(buf, "Powr Temp: %2.1fC", powerTemp);
  M5.Lcd.drawString(buf, 0, INFO_HEIGHT_POS, 4);

  const float batV =  M5.Axp.GetBatVoltage();
  const float batA =  M5.Axp.GetBatCurrent();
  sprintf(buf, "Power: %2.2fV %2.1fmA", batV, batA);
  M5.Lcd.drawString(buf, 0, INFO_HEIGHT_POS + 25, 4);

  if(M5.BtnB.read()) {
    pixels.setPixelColor(1, RGB_GREEN);
  } else {
    pixels.setPixelColor(1, RGB_RED);
  }

  pixels.show();  //sends the updated color to the hardware.
  delay(500);

  if(M5.BtnA.read()) {
    M5.shutdown();  
  } 

  
}