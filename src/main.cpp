#include <Arduino.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <SPI.h> 

TFT_eSPI tft = TFT_eSPI();
XPT2046_Touchscreen ts = XPT2046_Touchscreen(33);
bool wasTouched = false;

void readyForTouch() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextFont(2); 
  tft.drawCentreString("touch me", 160, 110, 2);
}

void setup() {
  Serial.begin(115200);
 
  // Wake up the screen
  tft.init();
  tft.setRotation(1); 
  readyForTouch();

  // 3. Route the hidden wires, then wake up the touch controller
  SPI.begin(25, 39, 32, 33);
  ts.begin();
}

void loop() {
  // Ask our new touch object if the screen is being pressed
  bool isTouched = ts.touched();

  if (isTouched && !wasTouched) {
    tft.fillScreen(TFT_GREEN);
    tft.setTextColor(TFT_RED, TFT_GREEN);
    tft.setTextFont(4); 
    tft.drawCentreString("stop touching me!", 160, 110, 4);
    wasTouched = true;
  }
  
  if (!isTouched && wasTouched) {
    readyForTouch();
    wasTouched = false;
  }
}
