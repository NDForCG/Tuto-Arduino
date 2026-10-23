const byte PIN_X = A0;
const byte PIN_Y = A1;

int direction(int valeur) {
  if (valeur < 412) {
    return -1;
  }
  if (valeur > 612) {
    return 1;
  }
  return 0;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int dx = direction(analogRead(PIN_X));
  int dy = direction(analogRead(PIN_Y));
  Serial.print("dx = ");
  Serial.print(dx);
  Serial.print("   dy = ");
  Serial.println(dy);
  delay(300);
}
