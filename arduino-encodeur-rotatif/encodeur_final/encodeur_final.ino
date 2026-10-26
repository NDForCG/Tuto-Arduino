const byte PIN_CLK = 2;
const byte PIN_DT = 3;
const byte PIN_SW = 4;
const byte PIN_LED = 9;
const byte PAS = 15;

int luminosite = 0;
bool allumee = true;
int clkAvant = HIGH;
int swAvant = HIGH;
unsigned long dernierCran = 0;
unsigned long dernierAppui = 0;

void setup() {
  pinMode(PIN_CLK, INPUT_PULLUP);
  pinMode(PIN_DT, INPUT_PULLUP);
  pinMode(PIN_SW, INPUT_PULLUP);
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
  }
  clkAvant = clk;

  int sw = digitalRead(PIN_SW);
  if (sw == LOW && swAvant == HIGH && millis() - dernierAppui > 30) {
    dernierAppui = millis();
    allumee = !allumee;
  }
  swAvant = sw;

  if (allumee) {
    analogWrite(PIN_LED, luminosite);
  } else {
    analogWrite(PIN_LED, 0);
  }
}
