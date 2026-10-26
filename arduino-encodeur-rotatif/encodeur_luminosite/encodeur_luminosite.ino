const byte PIN_CLK = 2;
const byte PIN_DT = 3;
const byte PIN_LED = 9;
const byte PAS = 15;

int luminosite = 0;
int clkAvant = HIGH;
unsigned long dernierCran = 0;

void setup() {
  pinMode(PIN_CLK, INPUT_PULLUP);
  pinMode(PIN_DT, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  int clk = digitalRead(PIN_CLK);
  if (clk == LOW && clkAvant == HIGH && millis() - dernierCran > 5) {
    dernierCran = millis();
    if (digitalRead(PIN_DT) == HIGH) {
      luminosite = constrain(luminosite + PAS, 0, 255);
    } else {
      luminosite = constrain(luminosite - PAS, 0, 255);
    }
    analogWrite(PIN_LED, luminosite);
  }
  clkAvant = clk;
}
