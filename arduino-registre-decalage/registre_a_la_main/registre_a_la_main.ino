const byte PIN_DONNEE = 2;
const byte PIN_VERROU = 3;
const byte PIN_HORLOGE = 4;

void setup() {
  pinMode(PIN_DONNEE, OUTPUT);
  pinMode(PIN_VERROU, OUTPUT);
  pinMode(PIN_HORLOGE, OUTPUT);

  digitalWrite(PIN_VERROU, LOW);
  envoyerOctet(0b10110010);
  digitalWrite(PIN_VERROU, HIGH);
}

void loop() {
}

void envoyerOctet(byte valeur) {
  for (int i = 7; i >= 0; i--) {
    digitalWrite(PIN_DONNEE, bitRead(valeur, i));
    digitalWrite(PIN_HORLOGE, HIGH);
    digitalWrite(PIN_HORLOGE, LOW);
  }
}
