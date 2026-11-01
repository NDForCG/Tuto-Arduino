const byte PIN_BOUTON = 2;
const byte PIN_LED = 9;

volatile int compteur = 0;

void appui() {
  compteur++;
  digitalWrite(PIN_LED, compteur % 2);
}

void setup() {
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(PIN_BOUTON), appui, FALLING);
}

void loop() {
  Serial.println(compteur);
  delay(2000);
}
