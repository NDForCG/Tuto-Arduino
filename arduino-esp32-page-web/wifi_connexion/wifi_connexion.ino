#include <WiFi.h>

const char* RESEAU = "MaBox";
const char* MOT_DE_PASSE = "motdepasse";

void setup() {
  Serial.begin(115200);
  WiFi.begin(RESEAU, MOT_DE_PASSE);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());
}

void loop() {
}
