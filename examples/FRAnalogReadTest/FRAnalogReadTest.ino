// Testscript for testing the analog input on the Flight Recorder PCB v2
// Required hardware:
// - 2x potmeter
// - 6x breadboard cables female-male
// - FlightRecorder PCB V2. For V1, the pinout is different. Old pinnumbers are in the comments
// Connections:
// - J19 (V2) / J6 (v1) to potmeter. The middle pin of the potmeter (wiper) connected to the middle pin of the connector on the board
// - J18 (V2) / J7 (v1) to potmeter. The middle pin of the potmeter (wiper) connected to the middle pin of the connector on the board
// Required libraries:
// - FRLibBasics (download from https://github.com/josmeuleman/FRLibBasics , unzipped in ../Documents/Arduino/libraries/ )
//
// 2024-02-12, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <FRGeneric.h>

const int PINAD[2] = {34, 39}; //V2, Analog input pin numbers
//const int PINAD[2] = {35, 34}; //V1, Analog input pin numbers

void setup() {
  Serial.begin(9600); // Start the serial communciation
  // Assign the two pins for input
  for (int i=0; i<2; i++) {
    pinMode(PINAD[i], INPUT);
  }
}

void loop() {
  // Loop through the two pins
  for (int i=0; i<2; i++) {
    int val = analogRead(PINAD[i]); // Read the analog input

    // For the Serial plotter, it may be conventient if the variable has a name
    // This will give the name A1 and A2 to the signal
    Serial.print("A"); 
    Serial.print(i+1);
    Serial.print(":");
    Serial.print(createIntString(val));  // Print the value
    
  }
  Serial.println(); // New line
  delay(10);
}
