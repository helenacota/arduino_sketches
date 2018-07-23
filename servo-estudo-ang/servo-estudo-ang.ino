#include<Servo.h>

#define servoPort 3

Servo servo;

int valorAng = 10;
int dir=0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPort);
  Serial.begin(9600);
  servo.write(10);
  delay(1000);
  Serial.println("setup OK!");
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(valorAng);

  if(dir == 0)
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

  servo.write(valorAng);
  delay(100);
  

}
