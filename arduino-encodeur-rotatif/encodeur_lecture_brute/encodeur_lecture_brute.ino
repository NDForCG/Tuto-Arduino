const byte PIN_CLK = 2;
const byte PIN_DT = 3;

int position = 0;
int clkAvant = HIGH;

void setup() {
  pinMode(PIN_CLK, INPUT_PULLUP);
  pinMode(PIN_DT, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int clk = digitalRead(PIN_CLK);
  if (clk == LOW && clkAvant == HIGH) {
    if (digitalRead(PIN_DT) == HIGH) {
      position++;
    } else {
      position--;
    }
    Serial.println(position);
  }
  clkAvant = clk;
}
