#include <SoftwareSerial.h>

const byte PIN_RX = 10;
const byte PIN_TX = 11;
const byte PIN_LED = 13;

SoftwareSerial bt(PIN_RX, PIN_TX);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (bt.available()) {
    char c = bt.read();
    if (c == '1') {
      digitalWrite(PIN_LED, HIGH);
      bt.println("LED allumee");
    }
    if (c == '0') {
      digitalWrite(PIN_LED, LOW);
      bt.println("LED eteinte");
    }
  }
}
