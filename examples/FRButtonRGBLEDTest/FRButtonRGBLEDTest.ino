// Testscript for testing the button and the LED on the ESP PCB
// Required hardware:
// - FlightRecorder PCB V2. This script is not suitable for V1
// Connections:
// - None (all wired on PCB)
// Required libraries:
// - FRLib (download the zip from https://github.com/josmeuleman/FRLibBasics)
//
// 2024-02-11, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <FRLED.h>
#include <FRButton.h>

const int PINSWITCH = 35;
const int PINLEDBLUE = 25;
const int PINLEDRED = 33;
const int PINLEDGREEN = 32;


int ledMode = 0;

Button myButton(PINSWITCH, true);  // Create a button object with the given pin. True for an inverted button, false for a normal button


//---------------------------------------------------------------------------------------------------------
// SETUP
// This block of code is only run once at the beginning
//---------------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(PINLEDBLUE, OUTPUT);
  pinMode(PINLEDGREEN, OUTPUT);
  pinMode(PINLEDRED, OUTPUT);
}

//---------------------------------------------------------------------------------------------------------
// LOOP
// This block of code is looped infinitely
//---------------------------------------------------------------------------------------------------------
void loop() {
  // Checks if the button has changed from not pushed to pushed
  myButton.Update();              // Read the state of the button
  if (myButton.HasChangedUp()) {  //Check if the state has changed from low to high
    ledMode++;
    if (ledMode == 4) {
      ledMode = 0;
    }
    Serial.print("Toggle to different LED mode: ");
    Serial.println(ledMode);
    if (ledMode == 0) {
      digitalWrite(PINLEDBLUE, HIGH);
      digitalWrite(PINLEDGREEN, LOW);
      digitalWrite(PINLEDRED, LOW);

    }
    if (ledMode == 1) {
      digitalWrite(PINLEDBLUE, LOW);
      digitalWrite(PINLEDGREEN, HIGH);
      digitalWrite(PINLEDRED, LOW);
    }
    if (ledMode == 2) {
      digitalWrite(PINLEDBLUE, LOW);
      digitalWrite(PINLEDGREEN, LOW);
      digitalWrite(PINLEDRED, HIGH);
    }
    if (ledMode == 3) {
       digitalWrite(PINLEDBLUE, HIGH);
      digitalWrite(PINLEDGREEN, HIGH);
      digitalWrite(PINLEDRED, HIGH);
    }
  }

  delay(10);
}
