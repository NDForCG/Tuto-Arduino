const byte PIN_GAUCHE = A0;
const byte PIN_CENTRE = A1;
const byte PIN_DROIT = A2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(PIN_GAUCHE));
  Serial.print("  ");
  Serial.print(analogRead(PIN_CENTRE));
  Serial.print("  ");
  Serial.println(analogRead(PIN_DROIT));
  delay(200);
}
