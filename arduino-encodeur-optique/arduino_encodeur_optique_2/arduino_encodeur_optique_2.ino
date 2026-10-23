const byte PIN_A = 2, PIN_B = 3;
volatile long position = 0;
void setup() {
  Serial.begin(9600);
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  int n = digitalPinToInterrupt(PIN_A);
  attachInterrupt(n, voieA, RISING);
}
void voieA() {
  if (digitalRead(PIN_B) == LOW) position++;
  else position--;
}
void loop() {
  noInterrupts();
  long p = position;
  interrupts();
  Serial.println(p);
  delay(200);
}
