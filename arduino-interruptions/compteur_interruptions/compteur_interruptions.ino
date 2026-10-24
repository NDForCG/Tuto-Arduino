const byte PIN_BOUTON = 2;
const byte PIN_LED = 9;

volatile int compteur = 0;
unsigned long dernier = 0;

void appui() {
  unsigned long maintenant = millis();
  if (maintenant - dernier > 50 && digitalRead(PIN_BOUTON) == LOW) {
    compteur++;
    digitalWrite(PIN_LED, compteur % 2);
  }
  dernier = maintenant;
}

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(PIN_BOUTON), appui, CHANGE);
}

void loop() {
  noInterrupts();
  int copie = compteur;
  interrupts();
  Serial.println(copie);
  delay(2000);
}
