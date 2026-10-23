int seuil = 500;
void setup() {
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int lumiere = analogRead(A0);
  Serial.println(lumiere);
  if (lumiere < seuil) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  delay(100);
}
