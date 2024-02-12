// Testscript for testing two servos with the analog input
// Required hardware:
// - 2x potmeter
// - 6x breadboard cables female-male
// - 2x small servos (eg. TGY-TG9) with cable
// - FlightRecorder PCB V2. For V1, the pinout is different. Old pinnumbers are in the comments 
// Connections:
// - J19 (V2) / J6 (v1) to potmeter. The middle pin of the potmeter (wiper) connected to the middle pin of the connector on the board
// - J18 (V2) / J7 (v1) to potmeter. The middle pin of the potmeter (wiper) connected to the middle pin of the connector on the board
// - J10 (V2) / J11 (V1) to servo
// - J11 (V2) / J12 (V1) to servo
// Required libraries:
// - ESP32Servo.h (script tested on version 0.12.1)
// Important note:
// Servos may drain too much current from the ESP board, causing it to reboot
// This can be solved by using external power to the board.
//
// 2023-03-04, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <ESP32Servo.h>


const int PINAD[2] = {34, 39}; //V2, Analog input pin numbers
//const int PINAD[2] = {35, 34}; //V1, Analog input pin numbers
const int PINSERVO[2] = {26, 27};  //V2, Servo pin numbers
//const int PINSERVO[2] = {25, 26}; //V1, Servo pin numbers

Servo myServo[2];  // create a servo object

//---------------------------------------------------------------------------------------------------------
// SETUP
// This block of code is only run once at the beginning
//---------------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  // Assign the two pins for input & two pins for the output
  for (int i=0; i<2; i++) {
    pinMode(PINAD[i], INPUT);
    myServo[i].attach(PINSERVO[i]);
  }
}

//---------------------------------------------------------------------------------------------------------
// LOOP
// This block of code is looped infinitely
//---------------------------------------------------------------------------------------------------------
void loop() {
  // Loop through the two pins
  for (int i=0; i<2; i++) {
    int val = analogRead(PINAD[i]); // Read the analog input (between 0 and 4095)
    int pos = map(val, 0, 4095, 0, 180); // map the val to pos between 0 and 180 (degrees)
    myServo[i].write(pos);
    Serial.print(pos);  // Print to the screen
    Serial.print("; "); //
  }
  Serial.println(); //newline
  delay(10);
}
