#include <LedControl.h>
const byte NB = 6;
LedControl lc = LedControl(12, 11, 10, NB);
const byte DESSUS = 0;
const byte DESSOUS = 1;
const byte DEVANT = 2;
const byte DERRIERE = 3;
const byte GAUCHE = 4;
const byte DROITE = 5;
const byte TOUR[NB] = {0, 2, 0, 0, 1, 3};
byte image[NB][8];
void montre() {
  for (byte f = 0; f < NB; f++) {
    for (byte r = 0; r < 8; r++) {
      lc.setRow(f, r, image[f][r]);
    }
  }
}
void dessine(byte face, byte colonne, byte rangee, bool etat) {
  for (byte i = 0; i < TOUR[face]; i++) {
    byte t = colonne;
    colonne = 7 - rangee;
    rangee = t;
  }
  bitWrite(image[face][rangee], colonne, etat);
}
void point(byte x, byte y, byte z, bool etat) {
  if (z == 7) dessine(DESSUS, x, 7 - y, etat);
  if (z == 0) dessine(DESSOUS, x, y, etat);
  if (y == 0) dessine(DEVANT, x, 7 - z, etat);
  if (y == 7) dessine(DERRIERE, 7 - x, 7 - z, etat);
  if (x == 0) dessine(GAUCHE, 7 - y, 7 - z, etat);
  if (x == 7) dessine(DROITE, y, 7 - z, etat);
}
void efface() {
  memset(image, 0, sizeof(image));
}
void planTourne() {
  for (byte k = 0; k < 32; k++) {
    float a = k * PI / 16;
    efface();
    for (byte x = 0; x < 8; x++) {
      for (byte y = 0; y < 8; y++) {
        float ecart = (x - 3.5) * sin(a) - (y - 3.5) * cos(a);
        if (abs(ecart) < 0.6) {
          for (byte z = 0; z < 8; z++) point(x, y, z, true);
        }
      }
    }
    montre();
    delay(70);
  }
}
void balayage() {
  for (byte f = 0; f < NB; f++) {
    efface();
    for (byte r = 0; r < 8; r++) image[f][r] = 255;
    montre();
    delay(400);
  }
}
byte gx[6], gy[6], gz[6];
void nouvelleGoutte(byte i) {
  byte c = random(8);
  byte face = random(4);
  if (face == 0) { gx[i] = c; gy[i] = 0; }
  if (face == 1) { gx[i] = 7; gy[i] = c; }
  if (face == 2) { gx[i] = c; gy[i] = 7; }
  if (face == 3) { gx[i] = 0; gy[i] = c; }
  gz[i] = 7;
}
void pluie() {
  efface();
  for (byte i = 0; i < 6; i++) {
    nouvelleGoutte(i);
    gz[i] = i + 1;
  }
  for (byte pas = 0; pas < 80; pas++) {
    for (byte i = 0; i < 6; i++) {
      point(gx[i], gy[i], gz[i], false);
      if (gz[i] == 0) nouvelleGoutte(i);
      else gz[i]--;
      point(gx[i], gy[i], gz[i], true);
    }
    montre();
    delay(90);
  }
}
void spirale() {
  efface();
  for (byte s = 0; s < 56; s++) {
    byte p = s % 28;
    byte x, y;
    if (p < 7)       { x = p;      y = 0; }
    else if (p < 14) { x = 7;      y = p - 7; }
    else if (p < 21) { x = 21 - p; y = 7; }
    else             { x = 0;      y = 28 - p; }
    point(x, y, s / 7, true);
    montre();
    delay(60);
  }
  delay(800);
}
const byte MOT[32] = {
  0x00, 0x62, 0x92, 0x92, 0x92, 0x8C, 0x00, 0x7E,
  0x88, 0x88, 0x88, 0x7E, 0x00, 0xFE, 0x02, 0x02,
  0x02, 0x02, 0x00, 0xFC, 0x02, 0x02, 0x02, 0xFC,
  0x00, 0x80, 0x80, 0xFE, 0x80, 0x80, 0x00, 0x00
};
const byte ANNEAU[4] = {DEVANT, DROITE, DERRIERE, GAUCHE};
void texte() {
  for (byte dec = 0; dec < 64; dec++) {
    efface();
    for (byte q = 0; q < 32; q++) {
      byte colonne = MOT[(q + 32 - dec % 32) % 32];
      for (byte r = 0; r < 8; r++) {
        dessine(ANNEAU[q / 8], q % 8, r, bitRead(colonne, 7 - r));
      }
    }
    montre();
    delay(80);
  }
}
void flash() {
  for (byte f = 0; f < NB; f++) lc.setIntensity(f, 15);
  for (byte f = 0; f < NB; f++) {
    for (byte r = 0; r < 8; r++) image[f][r] = 255;
  }
  montre();
  delay(1500);
  for (byte f = 0; f < NB; f++) lc.setIntensity(f, 3);
}
void setup() {
  for (byte f = 0; f < NB; f++) {
    lc.shutdown(f, false);
    lc.setIntensity(f, 3);
    lc.clearDisplay(f);
  }
}
void loop() {
  planTourne();
  balayage();
  pluie();
  spirale();
  texte();
  flash();
}
