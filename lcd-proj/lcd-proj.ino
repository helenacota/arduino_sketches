#include <LiquidCrystal.h>

// com 8 pinos de dados plugados
//LiquidCrystal lcd(2,3,4,6,7,8,9,10,11,12,13);
// com 4 pinos de dados plugados, e sem a porta RW (3)
LiquidCrystal lcd(2,4,10,11,12,13);
int bol = 0;
int xis = 15;
int dirbol = 1;
int dirxis = -1;
 
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(5, OUTPUT);
  analogWrite(5,110);

  /*lcd.print("Programa da Lena");
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.write("XoX");*/
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(bol,0);
  lcd.write("o");
  lcd.setCursor(xis,1);
  lcd.write("x");
  dirbol = direction(bol, dirbol);
  bol = bol + dirbol;
  dirxis = direction(xis, dirxis);
  xis = xis + dirxis;
  delay(150);
}

int direction(int col, int dir)
{
  int newdir = dir;
  if(col >= 15){
    newdir = -1;
  }
  if(col <= 0){
    newdir = 1;
  }
  return(newdir);
}

