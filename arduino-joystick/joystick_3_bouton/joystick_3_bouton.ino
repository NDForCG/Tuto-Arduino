const byte PIN_X = A0;
const byte PIN_Y = A1;
const byte PIN_BOUTON = 2;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BOUTON, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(PIN_X);
  int y = analogRead(PIN_Y);
  int b = digitalRead(PIN_BOUTON);
  Serial.print("x = ");
  Serial.print(x);
  Serial.print("   y = ");
  Serial.print(y);
  Serial.print("   bouton = ");
  Serial.println(b);
  delay(300);
}
