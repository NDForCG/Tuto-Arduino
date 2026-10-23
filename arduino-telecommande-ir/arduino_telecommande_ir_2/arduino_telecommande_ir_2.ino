#include <IRremote.hpp>

const byte PIN_IR = 2;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(PIN_IR, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    byte code = IrReceiver.decodedIRData.command;
    Serial.print("0x");
    Serial.println(code, HEX);
    IrReceiver.resume();
  }
}
