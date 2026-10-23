#include <SPI.h>
#include <SD.h>

const int PIN_CS = 10;

void setup() {
  Serial.begin(9600);
  if (!SD.begin(PIN_CS)) {
    Serial.println("Carte absente ou illisible");
    while (true) {}
  }
  Serial.println("Carte prete");
}

void loop() {
  int valeur = analogRead(A0);
  File fichier = SD.open("MESURES.CSV", FILE_WRITE);
  if (fichier) {
    fichier.print(millis() / 1000);
    fichier.print(";");
    fichier.println(valeur);
    fichier.close();
    Serial.println(valeur);
  } else {
    Serial.println("Ouverture impossible");
  }
  delay(1000);
}
