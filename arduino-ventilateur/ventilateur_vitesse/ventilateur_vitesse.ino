const byte PIN_POT = A0;
const byte PIN_VENTILO = 9;

void setup() {
  pinMode(PIN_VENTILO, OUTPUT);
}

void loop() {
  int lecture = analogRead(PIN_POT);
  int vitesse = map(lecture, 0, 1023, 0, 255);
  analogWrite(PIN_VENTILO, vitesse);
}
