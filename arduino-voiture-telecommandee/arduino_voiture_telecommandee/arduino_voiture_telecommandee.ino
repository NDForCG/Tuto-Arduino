#include <SoftwareSerial.h>

const byte PIN_RX = 2;
const byte PIN_TX = 3;
const byte PIN_ENA = 5;
const byte PIN_IN1 = 6;
const byte PIN_IN2 = 7;
const byte PIN_IN3 = 8;
const byte PIN_IN4 = 9;
const byte PIN_ENB = 10;
const byte VITESSE = 150;

SoftwareSerial bt(PIN_RX, PIN_TX);
unsigned long dernierOrdre = 0;

void moteur(byte in1, byte in2, int sens) {
  digitalWrite(in1, sens > 0);
  digitalWrite(in2, sens < 0);
}

void rouler(int gauche, int droite) {
  moteur(PIN_IN1, PIN_IN2, gauche);
  moteur(PIN_IN3, PIN_IN4, droite);
}

void setup() {
  bt.begin(9600);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  analogWrite(PIN_ENA, VITESSE);
  analogWrite(PIN_ENB, VITESSE);
}

void loop() {
  if (bt.available()) {
    char c = bt.read();
    dernierOrdre = millis();
    switch (c) {
      case 'F': rouler(1, 1); break;
      case 'B': rouler(-1, -1); break;
      case 'L': rouler(-1, 1); break;
      case 'R': rouler(1, -1); break;
      case 'S': rouler(0, 0); break;
    }
  }
  if (millis() - dernierOrdre > 500) {
    rouler(0, 0);
  }
}
