const byte POT = A0;
const byte LED = 9;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lecture = analogRead(POT);
  int lum = map(lecture, 0, 1023, 0, 255);
  analogWrite(LED, lum);
  Serial.println(lum);
  delay(50);
}
