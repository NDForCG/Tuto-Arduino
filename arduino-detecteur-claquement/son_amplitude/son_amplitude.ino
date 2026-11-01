const byte PIN_SON = A0;
const unsigned int FENETRE = 50;

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
  Serial.begin(9600);
}

void loop() {
  Serial.println(mesureAmplitude());
}
