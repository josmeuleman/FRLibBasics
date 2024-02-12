// Testscript for testing the button and the LED on the ESP PCB
// Required hardware:
// - None (all available on PCB)
// Connections:
// - None (all wired on PCB)
// Required libraries:
// - FRLib (download the zip from https://github.com/josmeuleman/FRLibBasics)
//
// 2024-02-11, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <FRLED.h>
#include <FRButton.h>

const int PINSWITCH = 35; //V2
// const int PINSWITCH = 22; //V1

const int PINLED = 25; //V2, Blue led = 25; Red led = 33; Green Led = 32;
// const int PINLED = 21; //V1, only blue led


Button myButton(PINSWITCH, true); // Create a button object with the given pin. True for an inverted button, false for a normal button
LED myLed(PINLED); // Create a led object with the given pin.

//---------------------------------------------------------------------------------------------------------
// SETUP
// This block of code is only run once at the beginning
//---------------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
}

//---------------------------------------------------------------------------------------------------------
// LOOP
// This block of code is looped infinitely
//---------------------------------------------------------------------------------------------------------
void loop() {
  // Checks if the button has changed from not pushed to pushed
  myButton.Update(); // Read the state of the button
  if (myButton.HasChangedUp()) { //Check if the state has changed from low to high
    Serial.println("toggle");
    myLed.Toggle(); // Change the state of the led
  }
  delay(10);
}
