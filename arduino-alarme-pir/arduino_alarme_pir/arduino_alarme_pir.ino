const byte PIN_PIR = 2;
const byte PIN_BOUTON = 4;
const byte PIN_BUZZER = 8;
const byte PIN_LED = 9;

bool alarme = false;

void setup() {
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_BOUTON, INPUT_PULLUP);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  delay(60000);
}

void loop() {
  if (digitalRead(PIN_PIR) == HIGH) {
    alarme = true;
  }
  if (digitalRead(PIN_BOUTON) == LOW) {
    alarme = false;
  }
  if (alarme) {
    digitalWrite(PIN_BUZZER, HIGH);
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_BUZZER, LOW);
    digitalWrite(PIN_LED, LOW);
  }
}
