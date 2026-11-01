#include <SPI.h>
#include <MFRC522.h>

const byte PIN_SS = 10;
MFRC522 lecteur(PIN_SS, MFRC522::UNUSED_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  lecteur.PCD_Init();
  lecteur.PCD_DumpVersionToSerial();
}

void loop() {
}
