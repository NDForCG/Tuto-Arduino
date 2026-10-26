#include <WiFi.h>
#include <WebServer.h>

const char* RESEAU = "MaBox";
const char* MOT_DE_PASSE = "motdepasse";
const byte PIN_LED = 4;

WebServer serveur(80);
bool allumee = false;

void afficherPage() {
  String html = "<meta charset='utf-8'><h1>La LED est ";
  html += allumee ? "allumée" : "éteinte";
  html += "</h1><a href='/on'>Allumer</a> ";
  html += "<a href='/off'>Éteindre</a>";
  serveur.send(200, "text/html", html);
}

void allumer() {
  allumee = true;
  digitalWrite(PIN_LED, HIGH);
  serveur.sendHeader("Location", "/");
  serveur.send(303);
}

void eteindre() {
  allumee = false;
  digitalWrite(PIN_LED, LOW);
  serveur.sendHeader("Location", "/");
  serveur.send(303);
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(RESEAU, MOT_DE_PASSE);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());
  serveur.on("/", afficherPage);
  serveur.on("/on", allumer);
  serveur.on("/off", eteindre);
  serveur.begin();
}

void loop() {
  serveur.handleClient();
}
