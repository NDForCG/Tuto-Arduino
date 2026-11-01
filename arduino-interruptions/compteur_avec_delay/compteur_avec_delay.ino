const byte PIN_BOUTON = 2;
const byte PIN_LED = 9;

int compteur = 0;
bool avant = HIGH;
unsigned long dernier = 0;

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool etat = digitalRead(PIN_BOUTON);
  if (etat != avant) {
    if (etat == LOW && millis() - dernier > 50) {
      compteur++;
      digitalWrite(PIN_LED, compteur % 2);
      Serial.println(compteur);
      delay(2000);
    }
    dernier = millis();
    avant = etat;
  }
}
