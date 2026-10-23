#include <LedControl.h>

const byte PIN_X = A0;
const byte PIN_Y = A1;
const byte PIN_BOUTON = 2;
const byte PIN_DIN = 8;
const byte PIN_CLK = 10;
const byte PIN_CS = 9;

LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, 1);

byte colonne = 3;
byte ligne = 3;

int direction(int valeur) {
  if (valeur < 412) {
    return -1;
  }
  if (valeur > 612) {
    return 1;
  }
  return 0;
}

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);
}

void loop() {
  if (digitalRead(PIN_BOUTON) == HIGH) {
    lc.setLed(0, ligne, colonne, false);
  }
  colonne = constrain(colonne + direction(analogRead(PIN_X)), 0, 7);
  ligne = constrain(ligne - direction(analogRead(PIN_Y)), 0, 7);
  lc.setLed(0, ligne, colonne, true);
  delay(150);
}
