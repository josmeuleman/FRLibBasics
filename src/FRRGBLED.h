// Class for RGBLed for FlightRecorder board v2
// 
// 2024-03-19, Jos Meuleman, Inholland Aeronautical & Precision Engineering, The Netherlands

#ifndef FRRGBLED_h
#define FRRGBLED_h

// Pin numbers on FlightRecorder board v2
const byte PINLEDRED = 33;
const byte PINLEDGREEN = 32;
const byte PINLEDBLUE = 25;

// Brightness corrections for combined lights
const byte BRIGHTNESSRED = 7;
const byte BRIGHTNESSGREEN = 255;
const byte BRIGHTNESSBLUE = 15;

enum rgbcolors {
  BLACK = 0,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE 
};


class RGBLED {
  public:
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
  
private:
  bool _isOn;
  byte _pinNumberRed;
  byte _pinNumberGreen;
  byte _pinNumberBlue;
  byte _brightnessRed;
  byte _brightnessGreen;
  byte _brightnessBlue;
  
  rgbcolors _lastColor;
  
};

#endif