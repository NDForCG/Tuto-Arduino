const byte PIN_SON = A0;
const byte PIN_LED = 8;
const unsigned int FENETRE = 50;
const int SEUIL = 150;
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
  Serial.begin(9600);
}

void loop() {
  int amplitude = mesureAmplitude();
  Serial.println(amplitude);
  if (amplitude > SEUIL) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}
