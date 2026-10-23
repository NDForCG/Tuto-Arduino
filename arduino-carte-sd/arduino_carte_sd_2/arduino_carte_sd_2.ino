#include <SPI.h>
#include <SD.h>

void setup() {
  Serial.begin(9600);
  if (!SD.begin(10)) {
    Serial.println("Carte absente ou illisible");
    while (true) {}
  }
  File fichier = SD.open("MESURES.CSV");
  if (fichier) {
    while (fichier.available()) {
      Serial.write(fichier.read());
    }
    fichier.close();
  }
}
void loop() {}
