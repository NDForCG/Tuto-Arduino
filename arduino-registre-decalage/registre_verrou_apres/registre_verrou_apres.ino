const byte PIN_DONNEE = 2;
const byte PIN_VERROU = 3;
const byte PIN_HORLOGE = 4;

void setup() {
  pinMode(PIN_DONNEE, OUTPUT);
  pinMode(PIN_VERROU, OUTPUT);
  pinMode(PIN_HORLOGE, OUTPUT);
}

void loop() {
  envoyer(0b00000001);
  delay(1000);
  envoyer(0b00000011);
  delay(1000);
  envoyer(0b00000111);
  delay(1000);
}

void envoyer(byte valeur) {
  digitalWrite(PIN_VERROU, LOW);
  shiftOut(PIN_DONNEE, PIN_HORLOGE, MSBFIRST, valeur);
  digitalWrite(PIN_VERROU, HIGH);
}
