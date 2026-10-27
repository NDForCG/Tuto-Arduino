const byte PIN_DONNEE = 2;
const byte PIN_VERROU = 3;
const byte PIN_HORLOGE = 4;

void setup() {
  pinMode(PIN_DONNEE, OUTPUT);
  pinMode(PIN_VERROU, OUTPUT);
  pinMode(PIN_HORLOGE, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    envoyer(128 >> i);
    delay(100);
  }
  for (int i = 6; i > 0; i--) {
    envoyer(128 >> i);
    delay(100);
  }
}

void envoyer(byte valeur) {
  digitalWrite(PIN_VERROU, LOW);
  shiftOut(PIN_DONNEE, PIN_HORLOGE, MSBFIRST, valeur);
  digitalWrite(PIN_VERROU, HIGH);
}
