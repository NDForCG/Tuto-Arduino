#include <Servo.h>

const byte NB = 4;
const byte BROCHES[NB] = {4, 5, 6, 7};
Servo servo[NB];

void setup() {
  for (byte i = 0; i < NB; i++) {
    servo[i].attach(BROCHES[i]);
    servo[i].write(90);
  }
}

void loop() {
  for (byte i = 0; i < NB; i++) {
    servo[i].write(45);
    delay(600);
    servo[i].write(135);
    delay(600);
    servo[i].write(90);
    delay(600);
  }
}
