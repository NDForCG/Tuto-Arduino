const byte PIN_VENTILO = 9;

void setup() {
  pinMode(PIN_VENTILO, OUTPUT);
}

void loop() {
  analogWrite(PIN_VENTILO, 255);
}
