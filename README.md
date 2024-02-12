# FRLibBasics
Basics FlightRecorder Library for Arduino IDE. This library contains sublibraries and examples for making a flight recorder for an ESP32.
The library is written for the Project2.2 for Aeronautical & Precision Engineerring at Inholland, Delft.

## FRGeneric
Generic functions for several sub libraries
Methods:

	#include <FRGeneric.h>
	String createTimeString(int hour, int minute, int second)
	String createDateString(int year, int month, int day)
	String createFloatString(float value, unsigned int accuracy)
	String createIntString(int value)
	float mapf(float x, float in_min, float in_max, float out_min, float out_max) 

All generated strings are ended with a "; ". This is conventient for plotting signals in the Serial monitor, and for writing to a csv file.
Examples:
- FRAnalogReadTest.ino


## FRButton

The class button is allows for monitoring binary sensors such as buttons. 
Methods:

    #include <FRButton.h>
    Button();
    Button(int pinNumber);
    Button(int pinNumber, bool inverted);
    void SetPinNumber(int pinNumber);
    bool Update();
    bool GetState();
    bool HasChanged();
    bool HasChangedUp();
    bool HasChangedDown();
Examples:
- FRButtonLEDTest.ino

## FRLED
The class LED is allows for controlling binary outputs such as LEDs. 
Methods:

	#include <FRLED.h>
	LED();
	LED(int pinNumber);	
	void SetPinNumber(int pinNumber);
	void SetState(bool state);
	void SetOn();
	void SetOff();
	void Toggle();
    void SetBlink(int OnTimeMS, int OffTimeMS);
    void Update();	
	
Examples:
- FRButtonLEDTest.ino
- FRButtonLEDBlinkingTest.ino

	
## PPMReceiverSensor
The PPMReceiverSensor class is a class specifically for logging ppm signals. It is a variant on PPMReceiver, but based on the SensorManager class, using an interrupt routine.
Methods:

	PPMReceiverSensor(int pinNumber, int numberOfChannels)
	void Init();
	void SetPrefix(String prefix);
    int ReadChannel(int ChannelNumber);

Usage:

	#include <FRPPMReceiverSensor.h>
	PPMReceiverSensor MyReceiver(PINPPM, NUMBEROFCHANNELS);
	...
	MyReceiver.Init();
	...
	MyReceiver.ReadChannel(i);

Examples:
- FRPPMReceiverSensorTest.ino	
	
## FRTimer
The Timer class reates a timer object that uses the millis() command to ensure timing accurate timing of a loop
Methods:
	
	#include <FRTimer.h> 
	Timer();
	Timer(uint32_t loopTimeMS);
	void SetLoopTime(uint32_t loopTimeMS);
	void Start();
	bool WaitUntilEnd();
	long GetLoopDuration();
	bool LoopTimePassed();
  
Examples:
- FRTimerDemo.ino
- FRTimerAndOverSamplingDemo.ino

## Other examples

**FRAnalogReadTest.ino**

Reads and prints analog input.

**FRBMP280Test.ino**

Sets up communication to the BMP280 over I2C

**FRGPSTest.ino**

Read the Serial2 port and prints the data to the Serial monitor. Useful for checking connection with GPS Sensor. This example does not decode the signal, it merely prints the raw data

**FRMPU9250Test.ino**

Sets up communication to the MPU9250 over I2C

**FRPitotSensorTest**

Sets up communication to the Pitot sensor over I2C

**FRServoAnalogReadTest.ino**

Uses ESP32Servo library for controlling servo's with the analog input.

**FRTimeDemo.ino**

Demonstrates the uses of millis() and the duration of print statements.


