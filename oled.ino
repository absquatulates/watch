#include <SPI.h>
#include <Wire.h>
#include "adafruit/Adafruit-GFX-Library-master/Adafruit_GFX.h"
#include <adafruit/Adafruit_SSD1306-master/Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_DC 8
#define OLED_CS 10
#define OLED_RESET 9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);


#define NUMFLAKES 10 /////////////////////////////////////////////////////////////////////////////
#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

static const unsigned char PROGMEM logo_bmp[] = 
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

 

void setup() {
  Serial.begin(9600);
  
  if (!display.begin(SSD1306_SWITCHCAPVCC))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  // För att slippa Startup-skärmen
  display.display();
  display.clearDisplay();

  display.drawBitmap(
    (display.width() - LOGO_WIDTH) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);

  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  //display.display();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

} 