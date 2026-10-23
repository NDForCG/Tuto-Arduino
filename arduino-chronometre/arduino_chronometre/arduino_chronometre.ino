const byte SEGMENTS[7] = {2, 3, 4, 5, 6, 7, 8};
const byte CHIFFRES[4] = {9, 10, 11, 12};
const byte POINT = 13;
const byte MARCHE = A0;
const byte RAZ = A1;

const byte MOTIFS[10] = {
  0b0111111,  // 0
  0b0000110,  // 1
  0b1011011,  // 2
  0b1001111,  // 3
  0b1100110,  // 4
  0b1101101,  // 5
  0b1111101,  // 6
  0b0000111,  // 7
  0b1111111,  // 8
  0b1101111   // 9
};

long cumule = 0;
long depart = 0;
long dernierAppui = 0;
bool enMarche = false;

void setup() {
  for (byte i = 0; i < 7; i++) {
    pinMode(SEGMENTS[i], OUTPUT);
  }
  for (byte i = 0; i < 4; i++) {
    pinMode(CHIFFRES[i], OUTPUT);
  }
  pinMode(POINT, OUTPUT);
  pinMode(MARCHE, INPUT_PULLUP);
  pinMode(RAZ, INPUT_PULLUP);
}

void afficher(byte position, byte c, bool point) {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(CHIFFRES[i], LOW);
  }
  for (byte i = 0; i < 7; i++) {
    digitalWrite(SEGMENTS[i], bitRead(MOTIFS[c], i));
  }
  digitalWrite(POINT, point);
  digitalWrite(CHIFFRES[position], HIGH);
  delay(2);
}

void lireBoutons() {
  if (millis() - dernierAppui < 250) return;
  if (digitalRead(MARCHE) == LOW) {
    dernierAppui = millis();
    if (enMarche) cumule += millis() - depart;
    else depart = millis();
    enMarche = !enMarche;
  }
  if (digitalRead(RAZ) == LOW) {
    dernierAppui = millis();
    cumule = 0;
    depart = millis();
  }
}

void loop() {
  lireBoutons();
  long ms = cumule;
  if (enMarche) ms += millis() - depart;
  byte minutes = (ms / 60000) % 100;
  byte secondes = (ms / 1000) % 60;
  afficher(0, minutes / 10, false);
  afficher(1, minutes % 10, true);
  afficher(2, secondes / 10, false);
  afficher(3, secondes % 10, false);
}
