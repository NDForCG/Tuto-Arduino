#include <SoftwareSerial.h>

SoftwareSerial espSerie(7, 6);  // RX, TX

void setup() {
  Serial.begin(9600);
  espSerie.begin(9600);
}

void loop() {
  if (espSerie.available()) {
    Serial.write(espSerie.read());
  }
  if (Serial.available()) {
    espSerie.write(Serial.read());
  }
}
