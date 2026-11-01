const byte PIN_BOUTON = 2;
const byte PIN_LED = 9;

int compteur = 0;
bool avant = HIGH;

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool etat = digitalRead(PIN_BOUTON);
  if (avant == HIGH && etat == LOW) {
    compteur++;
    digitalWrite(PIN_LED, compteur % 2);
    Serial.println(compteur);
  }
  avant = etat;
}
