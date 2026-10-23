#include <SPI.h>

volatile byte recu;
volatile bool nouveau;

void setup() {
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  pinMode(9, OUTPUT);
}

ISR(SPI_STC_vect) {
  recu = SPDR;
  SPDR = recu;
  nouveau = true;
}

void loop() {
  if (nouveau) {
    analogWrite(9, recu);
    nouveau = false;
  }
}
