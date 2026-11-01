const byte PIN_DO = 2;
const byte PIN_LED = 8;
const unsigned int PAUSE = 400;
bool allumee = false;
unsigned long dernierClap = 0;

void setup() {
  pinMode(PIN_DO, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (digitalRead(PIN_DO) == LOW && millis() - dernierClap > PAUSE) {
    dernierClap = millis();
    allumee = !allumee;
    digitalWrite(PIN_LED, allumee);
  }
}
