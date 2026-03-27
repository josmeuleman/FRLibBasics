// Class for binary outputs such as LEDs
// 
// 2023-03-19, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include "Arduino.h"
#include "FRLED.h"

LED* LED::_instance = nullptr; // Initialize the static member variable

LED::LED() {
  _instance = this; // Store a pointer to this instance
  _pinNumber = -1;
  _isOn = false;
  _blinkMode = false;
  //_timer = timerBegin(0, 80, true);
  _timer = timerBegin(1000);
  //timerAttachInterrupt(_timer, &LED::onTimer, true);
  timerAttachInterrupt(_timer, &LED::onTimer);
}

LED::LED(int pinNumber) {
  _instance = this; // Store a pointer to this instance
  _pinNumber = pinNumber;
  _isOn = false;
  _blinkMode = false;   
  pinMode(_pinNumber, OUTPUT);
  //_timer = timerBegin(0, 80, true);
  _timer = timerBegin(1000);
  //timerAttachInterrupt(_timer, &LED::onTimer, true);
  timerAttachInterrupt(_timer, &LED::onTimer);
}

LED::~LED() {
  delete _timer;
}

void LED::SetPinNumber(int pinNumber) {
  _pinNumber = pinNumber;
  pinMode(_pinNumber, OUTPUT);
}

void LED::SetState(bool state) {
  digitalWrite(_pinNumber, state);
}

void LED::SetOn() {
  _isOn = true;
  SetState(_isOn);
  _blinkMode = false;  
  //timerAlarmDisable(_timer);
  timerStart(_timer);
}

void LED::SetOff() {
  _isOn = false;
  SetState(_isOn);
  _blinkMode = false;
  timerStop(_timer);
  //timerAlarmDisable(_timer);

}

void LED::Toggle() {
  _isOn = !_isOn;
  SetState(_isOn);
}

void LED::SetBlink(int interval) {
  _blinkFreqHz = 1000.0/interval;
  _blinkMode = true;
  if (_timer != NULL) {
	  //Serial.println("kill the timer");
	  timerEnd(_timer);
  }
  _timer = timerBegin(_blinkFreqHz);
  //timerAlarmWrite(_timer, _blinkIntervalUs, true);
  //timerAlarmEnable(_timer);
}

void IRAM_ATTR LED::onTimer() {
  static bool ledState = false;
  digitalWrite(_instance->_pinNumber, ledState);
  ledState = !ledState;
}

