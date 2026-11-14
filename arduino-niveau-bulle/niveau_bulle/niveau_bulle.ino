#include <Wire.h>

const byte MPU = 0x68;
const byte LEDS[5] = {3, 4, 5, 6, 7};
const float ALPHA = 0.1;

float angle = 0;

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

float mesureAngle() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6);
  int x = lire16();
  lire16();
  int z = lire16();
  return degrees(atan2(x, z));
}

void setup() {
  Wire.begin();
  reveille();
  for (byte i = 0; i < 5; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  float brut = mesureAngle();
  angle = (1 - ALPHA) * angle + ALPHA * brut;
  int pos = constrain(round(angle / 3) + 2, 0, 4);
  for (byte i = 0; i < 5; i++) {
    digitalWrite(LEDS[i], i == pos);
  }
  Serial.println(angle);
  delay(20);
}
