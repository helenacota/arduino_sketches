// montagem do braco
// https://img.filipeflop.com/files/download/Manual-Montagem-Bra%C3%A7o-Robotico.pdf

#include<Servo.h>

#define servoBase 9
#define servoBraco 6
#define servoExt 5
#define servoGarra 3

Servo servoBa;
Servo servoBr;
Servo servoEx;
Servo servoGa;

int valorAngBase = 25;
int valorAngBraco = 25;
int valorAngExt = 25;
int valorAngGarra = 60;

int valorAnt = 0;
int valorPotBraco = 0;
int valorPotBase = 0;
int valorPotExt = 0;
int valorPotGarra = 0;

unsigned long lasttime = 0;
int botao2 = LOW;

void setup() {
  // put your setup code here, to run once:

  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);

  servoBa.attach(servoBase);
  servoBr.attach(servoBraco);
  servoEx.attach(servoExt);
  servoGa.attach(servoGarra);
  Serial.begin(9600);
  //servo.write(300);
  //delay(3000);
  Serial.println("setup OK!");
}

void loop() {
  valorPotBraco = analogRead(A1);
  valorPotBase = analogRead(A0);

  valorPotExt = analogRead(A4);
  valorPotGarra = analogRead(A3);
  
  valorAngBase = map(valorPotBase,0,1023,10,175);
  valorAngBraco = map(valorPotBraco,0,1023,140,30);
  valorAngExt = map(valorPotExt,0,1023,10,175);
  //valorAngGarra = map(valorPotGarra,0,1023,15,60); // de 10 a 55 para garra

  botao2 = digitalRead(10);
  if(botao2 == LOW && (lasttime+500) < millis()){
    lasttime = millis();
    if(valorAngGarra == 60){
      valorAngGarra = 15;
    }else{
      valorAngGarra = 60;
      
    }
  }

  Serial.println("base: " + String(valorAngBase) + " - braco: " + String(valorAngBraco) + " - ext: " + String(valorAngExt) + " - garra: " + String(valorAngGarra));
  
  servoBa.write(valorAngBase);
  servoBr.write(valorAngBraco);
  servoEx.write(valorAngExt);
  servoGa.write(valorAngGarra);

  delay(100);

  /*if(dir == 0)
  {
    valorAng += 10;
  }else{
    valorAng -= 10;
  }

  if(valorAng > 180)
  {
    valorAng = 180;
    dir = 1;
  }
  
  if(valorAng < 10)
  {
    valorAng = 10;
    dir = 0;
  }

  */
  

}
