const byte LEDS[8] = {3, 4, 5, 6, 7, 8, 9, 10};
const int COLONNES = 60;
const unsigned long PAS = 833;

int heure = 10, minute = 8, seconde = 35;
int colHeures, colMinutes, colSecondes;

byte barre(byte n) {
  return (1 << n) - 1;
}

byte octetColonne(int c) {
  byte octet = 0;
  if (c % 5 == 0) octet |= 0b10000000;
  if (c % 15 == 0) octet |= 0b11000000;
  if (c == colHeures) octet |= barre(4);
  if (c == colMinutes) octet |= barre(6);
  if (c == colSecondes) octet |= barre(7);
  return octet;
}

void afficher(byte octet) {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(LEDS[i], bitRead(octet, i));
  }
}

void setup() {
  for (byte i = 0; i < 8; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  colHeures = (heure % 12) * 5 + minute / 12;
  colMinutes = minute;
  colSecondes = seconde;
  unsigned long debut = micros();
  for (int c = 0; c < COLONNES; c++) {
    afficher(octetColonne(c));
    while (micros() - debut < (c + 1) * PAS) {}
  }
  afficher(0);
}
