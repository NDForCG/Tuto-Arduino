#include <DHT.h>

const byte DHTPIN = 2;
const byte DHTTYPE = DHT11;
const byte PIN_LED = 9;
const float SEUIL = 28;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Erreur de lecture");
    return;
  }
  Serial.print(h);
  Serial.print(" %  ");
  Serial.println(t);
  if (t > SEUIL) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}
