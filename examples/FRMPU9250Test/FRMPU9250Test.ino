// Testscript for checking communication with a MPU9250 accelerometer & gyro on Flight Recorder Board
// Required hardware:
// - FlightRecorder PCB V2. V1 does not support a MPU9250
// - 1x MPU9250
// Connections:
// - MPU9260 inserted in U2
// Required libraries:
// - FRLib (download from https://github.com/josmeuleman/FRLib, unzipped in ../Documents/Arduino/libraries/ )
// - MPU9250 by Bolder Flight Systems
// - Eigen by Bolder Flight Systems
//
// 2024-02-12, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include <mpu9250.h>

const int I2C_SDA = 21; // The data pin for I2C communication
const int I2C_SCL = 22; // The clock pin for I2C communcation
const int MPU9250_ADDRESS = 0x68; // The I2C address of the MPU9250 sensor

const int BAUDSERIAL = 9600;  //baud rate for serial communication

bfs::Mpu9250 myMPU; // Make an object for the sensor

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
  myMPU.Config(&Wire, bfs::Mpu9250::I2C_ADDR_PRIM);
  // Start communication with the MPU Sensor. If this fails, the program will stop here
  if (!myMPU.Begin()) {
    Serial.println("Error communicating with MPU9250");
    while (true) {};
  }
  else {
    Serial.println("MPU9250 found!");
  }
}

//---------------------------------------------------------------------------------------------------------
// LOOP
// This block of code is looped infinitely
//---------------------------------------------------------------------------------------------------------
void loop() {
  // insert your script here to read the sensor and print to the serial port 
}

