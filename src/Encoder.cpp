#include "encoder.h"

const int MIN_RPM_SAMPLE_TIME = 250;  // in msec

Encoder::Encoder(int encoderPin, int resolution) {
  _encoderPin = encoderPin;
  _encoderCount = 0;
  _rpm = 0;
  _lastCountTime = millis();
  _resolution = resolution;
  pinMode(_encoderPin, INPUT_PULLUP);
}

void Encoder:reset() {
  _encoderCount = 0;
  _lastCountTime = timeNow;
}

void Encoder::isr() {   // TODO add debounce delay
  _encoderCount++;
}

float Encoder::getRPM() {
  unsigned long timeNow = millis();
  if (timeNow - _lastCountTime >= MIN_RPM_SAMPLE_TIME) {
    _rpm = 60000.0 * _encoderCount /((timeNow - _lastCountTime) * _resolution);
    _lastCountTime = timeNow;
    _encoderCount = 0;
  }
  return _rpm;
}