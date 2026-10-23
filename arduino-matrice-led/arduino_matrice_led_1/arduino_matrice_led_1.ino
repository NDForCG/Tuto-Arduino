#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);

const byte coeur[8] = {
  0b00000000,
  0b01100110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

const byte fleche[8] = {
  0b00001000,
  0b00001100,
  0b00001110,
  0b11111111,
  0b11111111,
  0b00001110,
  0b00001100,
  0b00001000
};

void afficher(const byte dessin[8]) {
  for (int rangee = 0; rangee < 8; rangee++) {
    for (int colonne = 0; colonne < 8; colonne++) {
      lc.setLed(0, rangee, colonne,
                bitRead(dessin[rangee], colonne));
    }
  }
}

const byte texte[] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0x62, 0x92, 0x92, 0x92, 0x8C, 0,  // S
  0x7E, 0x88, 0x88, 0x88, 0x7E, 0,  // A
  0xFE, 0x02, 0x02, 0x02, 0x02, 0,  // L
  0xFC, 0x02, 0x02, 0x02, 0xFC, 0,  // U
  0x80, 0x80, 0xFE, 0x80, 0x80, 0,  // T
  0, 0, 0, 0, 0, 0, 0, 0
};

void defile() {
  int total = sizeof(texte);
  for (int debut = 0; debut <= total - 8; debut++) {
    for (int x = 0; x < 8; x++) {
      lc.setColumn(0, 7 - x, texte[debut + x]);
    }
    delay(100);
  }
}

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  afficher(coeur);
  delay(1500);
  afficher(fleche);
  delay(1500);
  defile();
}
