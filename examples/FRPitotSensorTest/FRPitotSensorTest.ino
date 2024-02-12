// Demo for communication with a PixHawk Pitot sensor with Flight Recorder PCB
// Required hardware:
// - FlightRecorder PCB V2. For V1, the pinout is different. Old pinnumbers are in the comments
// - 1x Pitot Sensor (tested on PX4AirspeedV1.1)
// Connections (V2):
// - J21 (screw terminal), 3.3V - PixHawk, 5V (yes this will work)
// - J21 (screw terminal), SCL - PixHawk, SCL
// - J21 (screw terminal), SDA - PixHawk, SDA
// - J21 (screw terminal), GND - PixHawk, GND
// for V1, the connector on the board is J9
// Required libraries:
// - FRLibBasics (download the zip from https://github.com/josmeuleman/FRLibBasics)
// - ms4525do
//
// 2024-02-11, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <ms4525do.h> 

const int I2C_SDA = 21;                 // V2, The data pin for I2C communication
const int I2C_SCL = 22;                 // V2, The clock pin for I2C communcation
//const int I2C_SDA = 33;                 // V1, The data pin for I2C communication
//const int I2C_SCL = 32;                 // V1, The clock pin for I2C communcation
const int PITOT_I2C_ADDRESS = 0x28;     // I2C address of the Pitot sensor

const int BAUDSERIAL = 9600;  //baud rate for serial communication

bfs::Ms4525do MyPitot; // Make an object for the sensor
String PitotString; // String for the data of the pitot sensor for writing, plotting or logging

//---------------------------------------------------------------------------------------------------------
// SETUP
// This block of code is only run once at the beginning
//---------------------------------------------------------------------------------------------------------
void setup() {
  // Start the Serial communication to your computer. Make sure the baud rate of the monitor is equal to the baud rate as set here
  Serial.begin(BAUDSERIAL);

  // Set up the communication for I2C sensors
  Wire.begin(I2C_SDA, I2C_SCL);
  Wire.setClock(400000);
  //I2C address for Pitot Sensor is 0x28, on bus 0, with a -1 to +1 PSI range
  MyPitot.Config(&Wire, PITOT_I2C_ADDRESS, 1.0f, -1.0f);
  // Start communication with the Pitot Sensor. If this fails, the program will stop here
  if (!MyPitot.Begin()) {
    Serial.println("Error communicating with pitot sensor");
    return;
  }

}

//---------------------------------------------------------------------------------------------------------
// LOOP
// This block of code is looped infinitely
//---------------------------------------------------------------------------------------------------------
void loop() {
  // insert your script here to read the sensor and print to the serial port 

}


