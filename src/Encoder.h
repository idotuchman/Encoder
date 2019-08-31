#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder
{
  public: 
    Encoder(int encoderPin, int resolution);
    float getRPM();
    void reset();
    void isr();
      
  private: 
    int _encoderPin, _resolution;
    float _rpm;
    volatile byte _encoderCount;
    unsigned long _lastCountTime;
    
};

#endif      // ENCODER_H