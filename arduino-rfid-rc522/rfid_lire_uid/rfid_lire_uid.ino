#include <SPI.h>
#include <MFRC522.h>

const byte PIN_SS = 10;
MFRC522 lecteur(PIN_SS, MFRC522::UNUSED_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  lecteur.PCD_Init();
}

void loop() {
  if (!lecteur.PICC_IsNewCardPresent()) return;
  if (!lecteur.PICC_ReadCardSerial()) return;

  for (byte i = 0; i < lecteur.uid.size; i++) {
    if (lecteur.uid.uidByte[i] < 0x10) Serial.print("0");
    Serial.print(lecteur.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  lecteur.PICC_HaltA();
}
