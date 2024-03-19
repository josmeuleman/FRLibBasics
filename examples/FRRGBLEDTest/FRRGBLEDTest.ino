// Testscript for testing the button and the LED on the ESP PCB
// Required hardware:
// - FlightRecorder PCB V2. This script is not suitable for V1
// - RGB LED
// Connections:
// - None (all wired on PCB)
// Required libraries:
// - FRLib (download the zip from https://github.com/josmeuleman/FRLibBasics)
//
// 2024-02-11, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <FRRGBLED.h>

byte runner = 0;
RGBLED myLed;


//---------------------------------------------------------------------------------------------------------
// SETUP
// This block of code is only run once at the beginning
//---------------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  myLed.SetColorBalance(true);
  delay(1000);
  Serial.println("Demo of RGB LED");
}


//---------------------------------------------------------------------------------------------------------
// LOOP
// This block of code is looped infinitely
//---------------------------------------------------------------------------------------------------------
void loop() {

  Serial.println("Loop through 8 colors");
  for (byte color = 0; color < 8; color++) {
    Serial.println(color);
    myLed.SetColor(color);
    delay(1000);
  }
  myLed.SetColor(runner);

  Serial.println("Do simple on/off");
  Serial.println("-on");
  myLed.SetState(true);
  delay(1000);
  Serial.println("-off");
  myLed.SetState(false);
  delay(1000);
  
  Serial.println("colors are balanced by default, such at red green and blue have similar brightness");
  Serial.println("unbalanced gives the highest brighness");
  Serial.println("-First a red light in balanced mode");
  myLed.SetColor(RED);
  delay(2000);
  Serial.println("-Now a red light in unbalanced mode");
  myLed.SetColorBalance(false);
  myLed.SetColor(RED);
  delay(2000);
  myLed.SetColorBalance(true);

  Serial.println("you can use color names   BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE ");
  Serial.println("blend colors work best in balanced mode ");
  myLed.SetColor(MAGENTA);
  delay(1000);
  myLed.SetColor(YELLOW);
  
  delay(1000);
}
