#include <Servo.h>

const byte NB = 4;
const byte BROCHES[NB] = {4, 5, 6, 7};
Servo servo[NB];

// base, épaule, coude, pince (la pince : 30 = ouverte, 90 = fermée)
const int POSES[][NB] = {
  {90, 90, 90, 30},
  {45, 60, 120, 30},
  {45, 60, 120, 90},
  {45, 90, 90, 90},
  {135, 90, 90, 90},
  {135, 60, 120, 90},
  {135, 60, 120, 30},
  {90, 90, 90, 30},
};
const byte NB_POSES = sizeof(POSES) / sizeof(POSES[0]);

int actuel[NB] = {90, 90, 90, 30};
byte etape = 0;
unsigned long dernierPas = 0;
unsigned long arrivee = 0;

void setup() {
  for (byte i = 0; i < NB; i++) {
    servo[i].attach(BROCHES[i]);
    servo[i].write(actuel[i]);
  }
}

void loop() {
  if (millis() - dernierPas < 15) return;
  dernierPas = millis();

  bool arrive = true;
  for (byte i = 0; i < NB; i++) {
    if (actuel[i] < POSES[etape][i]) actuel[i]++;
    else if (actuel[i] > POSES[etape][i]) actuel[i]--;
    if (actuel[i] != POSES[etape][i]) arrive = false;
    servo[i].write(actuel[i]);
  }

  if (arrive) {
    if (arrivee == 0) arrivee = millis();
    if (millis() - arrivee >= 400) {
      etape = (etape + 1) % NB_POSES;
      arrivee = 0;
    }
  }
}
