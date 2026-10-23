#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  int valeur = analogRead(A0);
  int colonnes = map(valeur, 0, 1023, 0, 8);
  for (int x = 0; x < 8; x++) {
    if (x < colonnes) {
      lc.setColumn(0, 7 - x, 0xFF);
    } else {
      lc.setColumn(0, 7 - x, 0);
    }
  }
  delay(50);
}
