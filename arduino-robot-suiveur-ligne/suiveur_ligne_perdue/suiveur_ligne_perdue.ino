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
const byte BASE = 120;
const int KP = 12;
int dernierCote = 0;

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
  int gauche = analogRead(PIN_GAUCHE);
  int centre = analogRead(PIN_CENTRE);
  int droit = analogRead(PIN_DROIT);
  if (gauche > SEUIL || centre > SEUIL || droit > SEUIL) {
    if (gauche > droit) {
      dernierCote = -1;
    } else if (droit > gauche) {
      dernierCote = 1;
    }
    int correction = (gauche - droit) * KP / 100;
    roues(constrain(BASE - correction, 0, 255),
          constrain(BASE + correction, 0, 255));
  } else if (dernierCote < 0) {
    roues(0, BASE);
  } else {
    roues(BASE, 0);
  }
}
