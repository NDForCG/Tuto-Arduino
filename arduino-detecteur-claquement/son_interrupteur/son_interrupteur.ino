const byte PIN_SON = A0;
const byte PIN_LED = 8;
const unsigned int FENETRE = 50;
const int SEUIL = 150;
const unsigned int PAUSE = 400;
bool allumee = false;
unsigned long dernierClap = 0;
int mesureAmplitude() {
  unsigned long debut = millis();
  int mini = 1023;
  int maxi = 0;
  while (millis() - debut < FENETRE) {
    int valeur = analogRead(PIN_SON);
    mini = min(mini, valeur);
    maxi = max(maxi, valeur);
  }
  return maxi - mini;
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (mesureAmplitude() > SEUIL && millis() - dernierClap > PAUSE) {
    dernierClap = millis();
    allumee = !allumee;
    digitalWrite(PIN_LED, allumee);
  }
}
