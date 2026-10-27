#include <SPI.h>
#include <MFRC522.h>

const byte PIN_SS = 10;
const byte PIN_VERTE = 6;
const byte PIN_ROUGE = 7;
const byte BADGE_OK[4] = {0x5A, 0x1C, 0x9F, 0x2B};
MFRC522 lecteur(PIN_SS, MFRC522::UNUSED_PIN);

void setup() {
  pinMode(PIN_VERTE, OUTPUT);
  pinMode(PIN_ROUGE, OUTPUT);
  SPI.begin();
  lecteur.PCD_Init();
}

void loop() {
  if (!lecteur.PICC_IsNewCardPresent()) return;
  if (!lecteur.PICC_ReadCardSerial()) return;
  if (memeBadge()) {
    digitalWrite(PIN_VERTE, HIGH);
    delay(2000);
    digitalWrite(PIN_VERTE, LOW);
  } else {
    digitalWrite(PIN_ROUGE, HIGH);
    delay(1000);
    digitalWrite(PIN_ROUGE, LOW);
  }
  lecteur.PICC_HaltA();
}

bool memeBadge() {
  if (lecteur.uid.size != 4) return false;
  for (byte i = 0; i < 4; i++) {
    if (lecteur.uid.uidByte[i] != BADGE_OK[i]) return false;
  }
  return true;
}
