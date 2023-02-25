#include <M5Core2.h>
#include <Adafruit_NeoPixel.h>

#define PIN 32       // Port A
#define NUMPIXELS 3  

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
    NUMPIXELS, PIN,
    NEO_GRB +
        NEO_KHZ800);  //set number of LEDs, pin number, LED type.

void setup() {
  M5.begin();      
  pixels.begin();  
  M5.Lcd.println(("RGB Tester"));
}

int i = 0, j = 1, k = 2;

void loop() {
  pixels.setPixelColor(i++, pixels.Color(100, 0, 0));  // Bright red
  pixels.setPixelColor(j++, pixels.Color(0, 100, 0));  // Bright green
  pixels.setPixelColor(k++, pixels.Color(0, 0, 100));  // Bright blue
  pixels.show();  //sends the updated color to the hardware.
  delay(500);
  if (i == 3)
    i = 0;
  else if (j == 3)
    j = 0;
  else if (k == 3)
    k = 0;
}