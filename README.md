# FRLibBasics
Basics FlightRecorder Library for Arduino IDE. This library contains sublibraries and examples for making a flight recorder for an ESP32.
The library is written for the Project2.2 for Aeronautical & Precision Engineerring at Inholland, Delft.
The Library is updated for Flight Recorder Board V2

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
The class LED allows for controlling binary outputs such as LEDs. 
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

## FRRGBLED
The class RGBLED interfaces the RGB led on the Flight Recorder board (v2 only

	#include <FRRGBLED.h>
	RGBLED();
	RGBLED(byte pinNumberRed, byte pinNumberGreen, byte pinNumberBlue);
	RGBLED(byte pinNumberRed, byte pinNumberGreen, byte pinNumberBlue, bool colorBalance);
	~RGBLED();

	void SetPinNumber(byte pinNumberRed, byte pinNumberGreen, byte pinNumberBlue);
  
	void SetColorBalance(bool colorBalance);
	void SetBrightness(byte inBrightnessRed, byte inBrightnessGreen, byte inBrightnessBlue);

	void SetState(bool state);
	void SetColor(rgbcolors color);
	void SetColor(byte color);
  
	void SetOn();
	void SetOff();
	void Toggle();
	
Examples:
- RGBLEDTest.ino	
	
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
- FRTimingDemo1.ino
- FRTimingDemo2.ino
Demonstrates the difference between using delay and millis() in the duration of loops.

## Other examples

**FRGPSTest.ino**

Read the Serial2 port and prints the data to the Serial monitor. Useful for checking connection with GPS Sensor. This example does not decode the signal, it merely prints the raw data

**FRServoAnalogReadTest.ino**

Uses ESP32Servo library for controlling servo's with the analog input.

**FRSDWriteExample.ino**

Template for writing lines to an SD card.

**MultipleBlinks**

Solution to the assignment to make the internal LED blink at fixed interval.

