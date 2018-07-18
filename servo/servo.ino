#include<Servo.h>

#define servoBase 5
#define potBase A0

Servo servo;

int valorAngBase;
int valorPotBase;
void setup() {
  // put your setup code here, to run once:
  servo.attach(servoBase);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorPotBase = analogRead(potBase);
  Serial.println(valorPotBase);
  valorAngBase = map(valorPotBase,0,1024,0,180);
  valorAngBase = map(valorAngBase,0,180,180,0);
  servo.write(valorAngBase);
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
