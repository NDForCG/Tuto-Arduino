#include <Servo.h>

const byte NB = 4;
const byte BROCHES[NB] = {4, 5, 6, 7};
const byte POTS[NB] = {A0, A1, A2, A3};
Servo servo[NB];
int actuel[NB] = {90, 90, 90, 90};
int cible[NB] = {90, 90, 90, 90};
unsigned long dernierPas = 0;

void setup() {
  for (byte i = 0; i < NB; i++) {
    servo[i].attach(BROCHES[i]);
    servo[i].write(actuel[i]);
  }
}

void loop() {
  for (byte i = 0; i < NB; i++) {
    cible[i] = map(analogRead(POTS[i]), 0, 1023, 0, 180);
  }
  if (millis() - dernierPas >= 15) {
    dernierPas = millis();
    for (byte i = 0; i < NB; i++) {
      if (actuel[i] < cible[i]) actuel[i]++;
      else if (actuel[i] > cible[i]) actuel[i]--;
      servo[i].write(actuel[i]);
    }
  }
}
