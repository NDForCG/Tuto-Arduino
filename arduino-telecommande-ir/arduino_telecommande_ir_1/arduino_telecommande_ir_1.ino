#include <IRremote.hpp>

const byte PIN_IR = 2;
const byte PIN_LED = 9;
const byte TOUCHE_UN = 0x0C;
const byte TOUCHE_PLUS = 0x15;
const byte TOUCHE_MOINS = 0x07;

bool allumee = false;
int luminosite = 120;

void setup() {
  IrReceiver.begin(PIN_IR);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    byte code = IrReceiver.decodedIRData.command;
    byte drapeaux = IrReceiver.decodedIRData.flags;
    bool repete = drapeaux & IRDATA_FLAGS_IS_REPEAT;
    if (code == TOUCHE_UN && !repete) {
      allumee = !allumee;
    }
    if (code == TOUCHE_PLUS) {
      luminosite = min(luminosite + 15, 255);
    }
    if (code == TOUCHE_MOINS) {
      luminosite = max(luminosite - 15, 0);
    }
    if (allumee) {
      analogWrite(PIN_LED, luminosite);
    } else {
      analogWrite(PIN_LED, 0);
    }
    IrReceiver.resume();
  }
}
