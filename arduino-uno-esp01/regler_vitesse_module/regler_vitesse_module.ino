#include <SoftwareSerial.h>

SoftwareSerial espSerie(7, 6);  // RX, TX

void setup() {
  Serial.begin(9600);
  espSerie.begin(115200);
  espSerie.println("AT+UART_DEF=9600,8,1,0,0");
  delay(1000);
  espSerie.begin(9600);
  espSerie.println("AT");
  delay(500);
  while (espSerie.available()) {
    Serial.write(espSerie.read());
  }
}

void loop() {
}
