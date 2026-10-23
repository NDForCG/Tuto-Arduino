#include <Wire.h>
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000);
}
void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x00);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 1);
  byte s = Wire.read();
  Serial.println(s, HEX);
  delay(1000);
}
