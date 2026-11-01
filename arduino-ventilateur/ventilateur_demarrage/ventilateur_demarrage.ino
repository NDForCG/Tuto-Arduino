const byte PIN_POT = A0;
const byte PIN_VENTILO = 9;
const byte SEUIL = 80;

int precedente = 0;

void setup() {
  pinMode(PIN_VENTILO, OUTPUT);
}

void loop() {
  int lecture = analogRead(PIN_POT);
  int vitesse = map(lecture, 0, 1023, 0, 255);
  if (vitesse < 20) {
    vitesse = 0;
  }
  if (precedente == 0 && vitesse > 0 && vitesse < SEUIL) {
    analogWrite(PIN_VENTILO, 255);
    delay(200);
  }
  analogWrite(PIN_VENTILO, vitesse);
  precedente = vitesse;
}
