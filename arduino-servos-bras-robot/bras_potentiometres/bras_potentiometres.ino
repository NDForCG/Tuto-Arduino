#include <Servo.h>

const byte NB = 4;
const byte BROCHES[NB] = {4, 5, 6, 7};
const byte POTS[NB] = {A0, A1, A2, A3};
Servo servo[NB];

void setup() {
  for (byte i = 0; i < NB; i++) {
    servo[i].attach(BROCHES[i]);
  }
}

void loop() {
  for (byte i = 0; i < NB; i++) {
    int angle = map(analogRead(POTS[i]), 0, 1023, 0, 180);
    servo[i].write(angle);
  }
  delay(15);
}
