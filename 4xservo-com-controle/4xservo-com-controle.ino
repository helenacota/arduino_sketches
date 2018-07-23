#include<Servo.h>

#define servo1 3
#define servo2 4
#define servo3 5
#define servo4 6
#define potCima A0
#define potBaixo A1

Servo servoA;
Servo servoB;
Servo servoC;
Servo servoD;

int valorAng1 = 10;
int valorAng2 = 20;
int valorAng3 = 30;
int valorAng4 = 40;

int valorPot1 = 0;
int valorPot2 = 0;
int valorPot3 = 0;
int valorPot4 = 0;
int bebado = 100;

void setup() {
  // put your setup code here, to run once:
  servoA.attach(servo1);
  servoB.attach(servo2);
  servoC.attach(servo3);
  servoD.attach(servo4);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorPot1 = analogRead(potCima);
  valorPot2 = analogRead(potBaixo);
  valorPot3 = analogRead(potCima);
  valorPot4 = analogRead(potBaixo);
  //Serial.println(valorPotBase);
  valorAng1 = map(valorPot1,0,1024,0,180);
  valorAng2 = map(valorPot2,0,1024,0,180);
  valorAng3 = map(valorPot3,0,1024,0,180);
  valorAng4 = map(valorPot4,0,1024,0,180);
  servoA.write(valorAng1);
  servoB.write(valorAng2);
  servoC.write(valorAng3);
  servoD.write(valorAng4);
  /*servoA.write(bebado);
  servoB.write(bebado);
  servoC.write(bebado);
  servo4.write(bebado);*/
  delay(100);
  /*servo.write(30);
  delay(2000);
  servo.write(60);
  delay(2000);
  servo.write(90);
  delay(2000);
  servo.write(120);
  delay(2000);
  servo.write(150);
  delay(2000);
  servo.write(180);
  delay(2000);*/
}
