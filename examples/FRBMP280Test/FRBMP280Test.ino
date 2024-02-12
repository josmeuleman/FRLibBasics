// Demo for communication with a PixHawk Pitot sensor with Flight Recorder PCB
// Required hardware:
// - FlightRecorder PCB V2. V1 does not support the BMP280
// - 1x Barometer BMP280
// Connections :
// - BMP280 inserted in U3
// for V1, the connector on the board is J9
// Required libraries:
// - FRLibBasics (download the zip from https://github.com/josmeuleman/FRLibBasics)
// - Adafruit_BMP280 (with dependencies)
//
// 2024-02-12, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <Adafruit_BMP280.h> 

const int I2C_SDA = 21;                 // V2, The data pin for I2C communication
const int I2C_SCL = 22;                 // V2, The clock pin for I2C communcation

const int MYBMP_I2C_ADDRESS = 0x76;     // I2C address of the Pitot sensor

const int BAUDSERIAL = 9600;  //baud rate for serial communication

Adafruit_BMP280 MyBMP; // Make an object for the sensor

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
  //I2C address for BMP Sensor is 0x76, on bus 0, with a -1 to +1 PSI range
  MyBMP = Adafruit_BMP280(&Wire);
  // Start communication with the Pitot Sensor. If this fails, the program will stop here
  if (!MyBMP.begin(MYBMP_I2C_ADDRESS)) {
    Serial.println("Error communicating with BMP sensor");
    return;
  }
  else {
    Serial.println("BMP280 found!");
  }

}

//---------------------------------------------------------------------------------------------------------
// LOOP
// This block of code is looped infinitely
//---------------------------------------------------------------------------------------------------------
void loop() {
  // insert your script here to read the sensor and print to the serial port 


}


