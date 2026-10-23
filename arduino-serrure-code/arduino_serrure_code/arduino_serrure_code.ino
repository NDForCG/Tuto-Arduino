#include <Keypad.h>

char touches[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte lignes[4] = {9, 8, 7, 6};
byte colonnes[4] = {5, 4, 3, 2};
Keypad clavier = Keypad(makeKeymap(touches),
                        lignes, colonnes, 4, 4);

const String CODE = "2580";
const byte VERTE = 10;
const byte ROUGE = 11;
String saisie = "";

void setup() {
  pinMode(VERTE, OUTPUT);
  pinMode(ROUGE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char touche = clavier.getKey();
  if (touche != NO_KEY) {
    Serial.println(touche);
    if (touche == '#') {
      verifier();
      saisie = "";
    } else if (touche == '*') {
      saisie = "";
    } else {
      saisie += touche;
    }
  }
}

void verifier() {
  if (saisie == CODE) {
    digitalWrite(VERTE, HIGH);
    delay(2000);
    digitalWrite(VERTE, LOW);
  } else {
    digitalWrite(ROUGE, HIGH);
    delay(2000);
    digitalWrite(ROUGE, LOW);
  }
}
