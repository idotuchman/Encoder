#include <Encoder.h>

const int ENCODER_RESOLUTION = 20;
const int MOTOR_A_ENCODER_PIN = D7;
const int MOTOR_B_ENCODER_PIN = D6;

Encoder encoderA(MOTOR_A_ENCODER_PIN, ENCODER_RESOLUTION);
Encoder encoderB(MOTOR_B_ENCODER_PIN, ENCODER_RESOLUTION);

void setup() {
  attachInterrupt(MOTOR_A_ENCODER_PIN, encoderAInterrupt, FALLING);
  attachInterrupt(MOTOR_B_ENCODER_PIN, encoderBInterrupt, FALLING);
}

void loop() {  
  double speedA, speedB;
  
  speedA = encoderA.getRPM();
  speedB = encoderB.getRPM();
}

void encoderAInterrupt() {
  encoderA.isr();
}

void encoderBInterrupt() {
  encoderB.isr();
}