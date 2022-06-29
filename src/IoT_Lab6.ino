/*
 * Project IoT_Lab6
 * Description:
 * Author:
 * Date:
 */

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
OledWingAdafruit display;

#define TEMP_IN A4

void setup() {
  pinMode(TEMP_IN, INPUT);
  
  display.setup();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.loop();
  display.clearDisplay();

  uint64_t reading = analogRead(TEMP_IN);
  double voltage = (reading * 3.3) / 4095.0;
  double celcius = (voltage - 0.5) * 100;

  display.println(String(int(celcius))+"c");
  display.setCursor(0,0);
  display.display();
}