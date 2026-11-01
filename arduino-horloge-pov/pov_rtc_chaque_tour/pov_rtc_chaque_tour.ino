#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

const byte LEDS[8] = {3, 4, 5, 6, 7, 8, 9, 10};
const int COLONNES = 60;
const int SENS = -1;

int heure, minute, seconde;
int colHeures, colMinutes, colSecondes;
unsigned long derniereLecture = 0;

const byte PIN_HALL = 2;

volatile unsigned long debutTour = 0;
volatile unsigned long dureeTour = 50000;
volatile bool nouveauTour = false;

void tourFait() {
  unsigned long maintenant = micros();
  dureeTour = maintenant - debutTour;
  debutTour = maintenant;
  nouveauTour = true;
}

void lireHeure() {
  DateTime maintenant = rtc.now();
  heure = maintenant.hour();
  minute = maintenant.minute();
  seconde = maintenant.second();
}

byte barre(byte n) {
  return (1 << n) - 1;
}

byte octetColonne(int c) {
  byte octet = 0;
  if (c % 5 == 0) octet |= 0b10000000;
  if (c % 15 == 0) octet |= 0b11000000;
  if (c == colHeures) octet |= barre(4);
  if (c == colMinutes) octet |= barre(6);
  if (c == colSecondes) octet |= barre(7);
  return octet;
}

void afficher(byte octet) {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(LEDS[i], bitRead(octet, i));
  }
}

void setup() {
  for (byte i = 0; i < 8; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(PIN_HALL, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_HALL), tourFait, FALLING);
  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  if (!nouveauTour) return;
  nouveauTour = false;
  noInterrupts();
  unsigned long debut = debutTour;
  unsigned long pas = dureeTour / COLONNES;
  interrupts();
  lireHeure();
  colHeures = (heure % 12) * 5 + minute / 12;
  colMinutes = minute;
  colSecondes = seconde;
  for (int c = 0; c < COLONNES; c++) {
    int colonne = (SENS == 1) ? c : (COLONNES - c) % COLONNES;
    afficher(octetColonne(colonne));
    while (micros() - debut < (c + 1) * pas) {}
  }
  afficher(0);
}
