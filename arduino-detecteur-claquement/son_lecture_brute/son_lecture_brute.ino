const byte PIN_SON = A0;
const byte PIN_LED = 8;
const int SEUIL = 600;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valeur = analogRead(PIN_SON);
  Serial.println(valeur);
  if (valeur > SEUIL) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
  delay(100);
}
