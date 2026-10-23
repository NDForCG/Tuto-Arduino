const byte PIN = 2;
volatile long compteur = 0;
void setup() {
  Serial.begin(9600);
  pinMode(PIN, INPUT);
  int n = digitalPinToInterrupt(PIN);
  attachInterrupt(n, compte, RISING);
}
void loop() {
  Serial.println(compteur);
  delay(200);
}
void compte() {
  compteur++;
}
