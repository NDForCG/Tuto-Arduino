const byte PIN_SON = A0;
const byte PIN_LED = 8;
const unsigned int FENETRE = 50;
const int SEUIL = 150;
const unsigned int PAUSE_MIN = 150;
const unsigned int PAUSE_MAX = 800;
bool allumee = false;
byte claps = 0;
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
  bool fort = mesureAmplitude() > SEUIL;
  unsigned long maintenant = millis();
  if (claps > 0 && maintenant - dernierClap > PAUSE_MAX) {
    claps = 0;
  }
  if (fort && maintenant - dernierClap > PAUSE_MIN) {
    dernierClap = maintenant;
    claps++;
    if (claps == 2) {
      allumee = !allumee;
      digitalWrite(PIN_LED, allumee);
      claps = 0;
    }
  }
}
