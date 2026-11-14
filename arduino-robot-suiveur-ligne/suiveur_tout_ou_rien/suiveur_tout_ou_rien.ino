const byte PIN_GAUCHE = A0;
const byte PIN_CENTRE = A1;
const byte PIN_DROIT = A2;
const byte PIN_ENA = 5;
const byte PIN_IN1 = 6;
const byte PIN_IN2 = 7;
const byte PIN_IN3 = 8;
const byte PIN_IN4 = 9;
const byte PIN_ENB = 10;
const int SEUIL = 500;
const byte VITESSE = 130;

void roues(int gauche, int droite) {
  analogWrite(PIN_ENA, gauche);
  analogWrite(PIN_ENB, droite);
}

void setup() {
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
}

void loop() {
  bool gaucheNoir = analogRead(PIN_GAUCHE) > SEUIL;
  bool droitNoir = analogRead(PIN_DROIT) > SEUIL;
  if (gaucheNoir) {
    roues(0, VITESSE);
  } else if (droitNoir) {
    roues(VITESSE, 0);
  } else {
    roues(VITESSE, VITESSE);
  }
}
