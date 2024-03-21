// Class for receiving PPM signals, and add it to logger
// 
// 2023-04-16, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include "Arduino.h"
#include "FRPPMReceiverSensor.h"
#include "FRGeneric.h"

PPMReceiverSensor* PPMReceiverSensor::_instance = nullptr;

volatile unsigned long PPMReceiverSensor::_lastPulseUS;
volatile uint16_t PPMReceiverSensor::_channel;
volatile int* PPMReceiverSensor::_channelValues;

PPMReceiverSensor::PPMReceiverSensor(int pinNumber, int numberOfChannels) {
  _instance = this; // Store a pointer to this instance
  _numberOfChannels = numberOfChannels;
  _pinNumber = pinNumber;
 
  if (_channelValues != 0) {
    delete[] _channelValues;
  }
  _channelValues = new int[_numberOfChannels];
  
  for (int i = 0; i < _numberOfChannels; i++) {
	_channelValues[i] = 0;
  }
  _channel = 0;
}

PPMReceiverSensor::~PPMReceiverSensor() {
  detachInterrupt(_pinNumber);
  delete[] _channelValues;
}

void PPMReceiverSensor::Init(){
  pinMode(_pinNumber, INPUT);
  attachInterruptArg(digitalPinToInterrupt(_pinNumber), ppm_isr, this, CHANGE);
  _lastPulseUS = micros();
}


void PPMReceiverSensor::SetPrefix(String prefix) {
  _prefix = prefix; 
}

int PPMReceiverSensor::ReadChannel(int ChannelNumber) {
  if ((ChannelNumber >= 0) && (ChannelNumber < _numberOfChannels)) {
    return (_channelValues[ChannelNumber]);
  } 
  else {
    return (0);
  }
}

void PPMReceiverSensor::CountPulse() {
  unsigned long tNow = micros();
  if (digitalRead(_pinNumber)) {
    _lastPulseUS = micros();
  } else {
    long x = tNow - _lastPulseUS;
    _lastPulseUS = tNow;
    if (x > _PULSETHRESHUS) {
      _channel = 0;
    }
    else {
	  if (_channel < _numberOfChannels) {
	    _channelValues[_channel] = x;
        _channel++;
	  }
	}
  }  
}

void IRAM_ATTR PPMReceiverSensor::ppm_isr(void* arg) {
  PPMReceiverSensor* receiver = reinterpret_cast<PPMReceiverSensor*>(arg);
  receiver->CountPulse();
}
