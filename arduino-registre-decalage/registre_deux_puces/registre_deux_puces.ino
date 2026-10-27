const byte PIN_DONNEE = 2;
const byte PIN_VERROU = 3;
const byte PIN_HORLOGE = 4;

void setup() {
  pinMode(PIN_DONNEE, OUTPUT);
  pinMode(PIN_VERROU, OUTPUT);
  pinMode(PIN_HORLOGE, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    envoyer16(0x8000 >> i);
    delay(60);
  }
}

void envoyer16(unsigned int valeur) {
  digitalWrite(PIN_VERROU, LOW);
  shiftOut(PIN_DONNEE, PIN_HORLOGE, MSBFIRST, valeur >> 8);
  shiftOut(PIN_DONNEE, PIN_HORLOGE, MSBFIRST, valeur & 0xFF);
  digitalWrite(PIN_VERROU, HIGH);
}
