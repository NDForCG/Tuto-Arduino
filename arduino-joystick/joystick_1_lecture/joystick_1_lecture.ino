const byte PIN_X = A0;
const byte PIN_Y = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(PIN_X);
  int y = analogRead(PIN_Y);
  Serial.print("x = ");
  Serial.print(x);
  Serial.print("   y = ");
  Serial.println(y);
  delay(300);
}
