const byte PIN_DO = 2;

void setup() {
  pinMode(PIN_DO, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(PIN_DO));
  delay(200);
}
