#include <SoftwareSerial.h>
#include <WiFiEsp.h>

const char RESEAU[] = "MaBox";
const char MOT_DE_PASSE[] = "motdepasse";
const byte PIN_LED = LED_BUILTIN;

SoftwareSerial espSerie(7, 6);  // RX, TX
WiFiEspServer serveur(80);
RingBuffer tampon(8);
bool allumee = false;
bool commande = false;

void envoyerPage(WiFiEspClient &client) {
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n"));
  client.print(F("<meta charset='utf-8'><h1>La LED est "));
  client.print(allumee ? F("allumée") : F("éteinte"));
  client.print(F("</h1><a href='/on'>Allumer</a> <a href='/off'>Éteindre</a>"));
}

void retourAccueil(WiFiEspClient &client) {
  client.print(F("HTTP/1.1 303 See Other\r\nLocation: /\r\nConnection: close\r\n\r\n"));
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
  espSerie.begin(9600);
  WiFi.init(&espSerie);
  while (WiFi.begin(RESEAU, MOT_DE_PASSE) != WL_CONNECTED) {
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());
  serveur.begin();
}

void loop() {
  WiFiEspClient client = serveur.available();
  if (client) {
    tampon.init();
    commande = false;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        tampon.push(c);
        if (tampon.endsWith("GET /on")) {
          allumee = true;
          digitalWrite(PIN_LED, HIGH);
          commande = true;
        } else if (tampon.endsWith("GET /off")) {
          allumee = false;
          digitalWrite(PIN_LED, LOW);
          commande = true;
        }
        if (tampon.endsWith("\r\n\r\n")) {
          if (commande) {
            retourAccueil(client);
          } else {
            envoyerPage(client);
          }
          break;
        }
      }
    }
    client.stop();
  }
}
