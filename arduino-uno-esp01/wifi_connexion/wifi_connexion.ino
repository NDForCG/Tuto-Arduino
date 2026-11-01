#include <SoftwareSerial.h>
#include <WiFiEsp.h>

const char RESEAU[] = "MaBox";
const char MOT_DE_PASSE[] = "motdepasse";

SoftwareSerial espSerie(7, 6);  // RX, TX

void setup() {
  Serial.begin(9600);
  espSerie.begin(9600);
  WiFi.init(&espSerie);
  while (WiFi.begin(RESEAU, MOT_DE_PASSE) != WL_CONNECTED) {
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());
}

void loop() {
}
