#include <Wire.h>

const byte MPU = 0x68;

void reveille() {
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
}

int lire16() {
  int haut = Wire.read();
  int bas = Wire.read();
  return (haut << 8) | bas;
}

void setup() {
  Wire.begin();
  reveille();
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6);
  Serial.print(lire16());
  Serial.print(" ");
  Serial.print(lire16());
  Serial.print(" ");
  Serial.println(lire16());
  delay(300);
}
