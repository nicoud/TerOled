//TerGfxOled.ino  Compare to TerOled

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define  OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


void setup() {
  display.begin();
  display.setTextColor(WHITE); 
  display.clearDisplay();
  display.display();
}
byte val;
void loop() {
  display.clearDisplay();
  display.setCursor (0,0);
  display.println ("Gfx");
  display.println (val++,BIN);
  display.display();
      delay (100);
}
