#include <Wire.h>
void setup() {
  Serial.begin(9600);
  Wire.begin();
}
void loop() {
  for (byte adresse = 1; adresse < 127; adresse++) {
    Wire.beginTransmission(adresse);
    if (Wire.endTransmission() == 0) {
      Serial.print("Appareil trouvé : 0x");
      Serial.println(adresse, HEX);
    }
  }
  delay(2000);
}
