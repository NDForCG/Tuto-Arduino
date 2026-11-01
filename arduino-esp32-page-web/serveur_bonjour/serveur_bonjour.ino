#include <WiFi.h>
#include <WebServer.h>

const char* RESEAU = "MaBox";
const char* MOT_DE_PASSE = "motdepasse";

WebServer serveur(80);

void afficherPage() {
  serveur.send(200, "text/html", "<h1>Bonjour !</h1>");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(RESEAU, MOT_DE_PASSE);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());
  serveur.on("/", afficherPage);
  serveur.begin();
}

void loop() {
  serveur.handleClient();
}
