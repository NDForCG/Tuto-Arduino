#include <Stepper.h>

const int PAS_PAR_TOUR = 2048;
const byte POT = A0;

Stepper moteur(PAS_PAR_TOUR, 8, 10, 9, 11);
int position = 0;

void setup() {
  moteur.setSpeed(10);
}

void loop() {
  int lecture = analogRead(POT);
  int cible = map(lecture, 0, 1023, 0, PAS_PAR_TOUR);
  if (abs(cible - position) > 8) {
    moteur.step(cible - position);
    position = cible;
  }
}
