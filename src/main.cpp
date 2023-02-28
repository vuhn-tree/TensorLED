#include <Adafruit_NeoPixel.h>
#include <M5Core2.h>

#define LED_PIN 26  // Port B
#define POT_PIN 13  // Port C
#define NUMPIXELS 3

const int DISP_OFFSET = 25;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
    NUMPIXELS, LED_PIN,
    NEO_GRB + NEO_KHZ800);  // set number of LEDs, pin number, LED type.

const uint32_t RGB_RED = pixels.Color(100, 0, 0);
const uint32_t RGB_GREEN = pixels.Color(0, 100, 0);
const uint32_t RGB_BLUE = pixels.Color(0, 0, 100);

int potVal = 0;  // Stores the value currently read by the sensor.

char colorOption = 'g';

void setup() {
  M5.begin();
  pixels.begin();
  pixels.setBrightness(10);

  pinMode(POT_PIN, INPUT);  // Sets the specified pin to input mode.

  M5.Axp.SetLcdVoltage(2600);
  M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
  M5.Lcd.drawString("RGB Monitor", 0, 0, 4);

  Serial.begin(115200);
}

void loop() {
  M5.update();

  char buf[50];

  const float powerTemp = M5.Axp.GetTempInAXP192();
  sprintf(buf, "Powr Temp: %2.1fC", powerTemp);
  M5.Lcd.drawString(buf, 0, DISP_OFFSET, 4);

  const float batV = M5.Axp.GetBatVoltage();
  const float batA = M5.Axp.GetBatCurrent();
  sprintf(buf, "Batt.: %2.2fV %2.1fmA", batV, batA);
  M5.Lcd.drawString(buf, 0, DISP_OFFSET * 2, 4);

  const float busV = M5.Axp.GetVBusVoltage();
  const float busA = M5.Axp.GetVBusCurrent();
  sprintf(buf, "VBUS: %2.2fV %2.1fmA", busV, busA);
  M5.Lcd.drawString(buf, 0, DISP_OFFSET * 3, 4);

  const float vinV = M5.Axp.GetVinVoltage();
  const float vinA = M5.Axp.GetVinCurrent();
  sprintf(buf, "vin: %2.2fV %2.1fmA", vinV, vinA);
  M5.Lcd.drawString(buf, 0, DISP_OFFSET * 4, 4);

  potVal = analogRead(POT_PIN);  // read the value from the sensor.
  const int normalVal = map(potVal, 0, 4096, 0, 255);
  sprintf(buf, "Norm Pot: %03d%", normalVal);
  M5.Lcd.drawString(buf, 0, DISP_OFFSET * 5, 4);
  pixels.setBrightness(normalVal);

  const int lcdPotVal = map(potVal, 0, 4096, 2500, 3300);
  M5.Axp.SetLcdVoltage(lcdPotVal);

  int counter = 0;
  while (Serial.available()) {
    // String chary = Serial.readString();
    colorOption = Serial.read();

    sprintf(buf, "[%d] color: %c", counter, colorOption);
    M5.Lcd.drawString(buf, 0, DISP_OFFSET * 6, 4);
    ++counter;
  }

  switch (colorOption) {
    case 'r':
      pixels.setPixelColor(1, RGB_RED);
      break;

    case 'g':
      pixels.setPixelColor(1, RGB_GREEN);
      break;

    case 'b':
      pixels.setPixelColor(1, RGB_BLUE);
      break;

    default:
      break;
  }

  pixels.show();  // sends the updated color to the hardware.
  delay(500);

  if (M5.BtnA.read()) {
    M5.shutdown();
  }

  if (M5.BtnC.read()) {
    M5.Axp.SetLcdVoltage(3300);
  }
}