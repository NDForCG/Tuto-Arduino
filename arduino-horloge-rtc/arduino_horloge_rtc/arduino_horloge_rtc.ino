#include <RTClib.h>

RTC_DS3231 rtc;

void deux(int n, char fin) {
  if (n < 10) {
    Serial.print("0");
  }
  Serial.print(n);
  Serial.print(fin);
}

void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Horloge introuvable");
    while (true) {}
  }
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime t = rtc.now();
  int valeur = analogRead(A0);
  Serial.print(t.year());
  Serial.print('-');
  deux(t.month(), '-');
  deux(t.day(), ' ');
  deux(t.hour(), ':');
  deux(t.minute(), ':');
  deux(t.second(), ';');
  Serial.println(valeur);
  delay(1000);
}
