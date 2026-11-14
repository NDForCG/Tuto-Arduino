#include <Wire.h>

const byte MPU = 0x68;

void reveille() {
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
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
  int haut = Wire.read();
  int bas = Wire.read();
  Serial.println((haut << 8) | bas);
  delay(300);
}
