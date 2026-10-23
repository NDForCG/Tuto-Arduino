#include <SPI.h>

const int PIN_SS = 10;
SPISettings reglage(1000000, MSBFIRST, SPI_MODE0);

void setup() {
  Serial.begin(9600);
  pinMode(PIN_SS, OUTPUT);
  digitalWrite(PIN_SS, HIGH);
  SPI.begin();
}

void loop() {
  byte valeur = analogRead(A0) / 4;
  SPI.beginTransaction(reglage);
  digitalWrite(PIN_SS, LOW);
  byte reponse = SPI.transfer(valeur);
  digitalWrite(PIN_SS, HIGH);
  SPI.endTransaction();
  Serial.print("envoye ");
  Serial.print(valeur);
  Serial.print("  recu ");
  Serial.println(reponse);
  delay(200);
}
