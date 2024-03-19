// Class for RGBRGBLED for FlightRecorder board v2
// 
// 2024-03-19, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#include "Arduino.h"
#include "FRRGBLED.h"

RGBLED::RGBLED() {
  _isOn = false;
  _pinNumberRed = PINLEDRED;
  _pinNumberGreen = PINLEDGREEN;
  _pinNumberBlue = PINLEDBLUE;
  pinMode(_pinNumberRed, OUTPUT);
  pinMode(_pinNumberGreen, OUTPUT);
  pinMode(_pinNumberBlue, OUTPUT);
  _brightnessRed = BRIGHTNESSRED;
  _brightnessGreen = BRIGHTNESSGREEN;
  _brightnessBlue = BRIGHTNESSBLUE;
}

RGBLED::RGBLED(byte pinNumberRed, byte pinNumberGreen, byte pinNumberBlue) {
  _isOn = false;
  _pinNumberRed = pinNumberRed;
  _pinNumberGreen = pinNumberGreen;
  _pinNumberBlue = pinNumberBlue;
  pinMode(_pinNumberRed, OUTPUT);
  pinMode(_pinNumberGreen, OUTPUT);
  pinMode(_pinNumberBlue, OUTPUT);
  _brightnessRed = BRIGHTNESSRED;
  _brightnessGreen = BRIGHTNESSGREEN;
  _brightnessBlue = BRIGHTNESSBLUE;  
}

RGBLED::RGBLED(byte pinNumberRed, byte pinNumberGreen, byte pinNumberBlue, bool colorBalance) {
  _isOn = false;
  _pinNumberRed = pinNumberRed;
  _pinNumberGreen = pinNumberGreen;
  _pinNumberBlue = pinNumberBlue;
  pinMode(_pinNumberRed, OUTPUT);
  pinMode(_pinNumberGreen, OUTPUT);
  pinMode(_pinNumberBlue, OUTPUT);
  if (colorBalance) {
    _brightnessRed = BRIGHTNESSRED;
    _brightnessGreen = BRIGHTNESSGREEN;
    _brightnessBlue = BRIGHTNESSBLUE;	  
  }
  else {
    _brightnessRed = 255;
    _brightnessGreen = 255;
    _brightnessBlue = 255;		  
  }
}

RGBLED::~RGBLED() {
}

void RGBLED::SetPinNumber(byte pinNumberRed, byte pinNumberGreen, byte pinNumberBlue) {
  _pinNumberRed = pinNumberRed;
  _pinNumberGreen = pinNumberGreen;
  _pinNumberBlue = pinNumberBlue;
  pinMode(_pinNumberRed, OUTPUT);
  pinMode(_pinNumberGreen, OUTPUT);
  pinMode(_pinNumberBlue, OUTPUT);

}

void RGBLED::SetColorBalance(bool colorBalance) {
  if (colorBalance) {
    _brightnessRed = BRIGHTNESSRED;
    _brightnessGreen = BRIGHTNESSGREEN;
    _brightnessBlue = BRIGHTNESSBLUE;	  
  }
  else {
    _brightnessRed = 255;
    _brightnessGreen = 255;
    _brightnessBlue = 255;		  
  }
}

void RGBLED::SetState(bool state) {
  analogWrite(_pinNumberRed, _brightnessRed*state);
  analogWrite(_pinNumberGreen, _brightnessGreen*state);
  analogWrite(_pinNumberBlue, _brightnessBlue*state);
}

void RGBLED::SetColor(rgbcolors inColor) {
  analogWrite(_pinNumberRed, ((inColor >> 0) & 1)*_brightnessRed);
  analogWrite(_pinNumberGreen, ((inColor >> 1) & 1)*_brightnessGreen);
  analogWrite(_pinNumberBlue, ((inColor >> 2) & 1)*_brightnessBlue);	
}
void RGBLED::SetColor(byte colorValue) {
  SetColor(static_cast<rgbcolors>(colorValue));
}

void RGBLED::SetOn() {
  _isOn = true;
  SetState(_isOn);
}

void RGBLED::SetOff() {
  _isOn = false;
  SetState(_isOn);
}

void RGBLED::Toggle() {
  _isOn = !_isOn;
  SetState(_isOn);
}
