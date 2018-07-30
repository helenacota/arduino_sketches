#include<Servo.h>

#define servoPort 3

Servo servo;

int valorAng = 25;
int valorAnt = 0;
int valorPot = 0;
int dir=0;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPort);
  Serial.begin(9600);
  //servo.write(300);
  //delay(3000);
  Serial.println("setup OK!");
}

void loop() {
  // put your main code here, to run repeatedly:


  valorPot = analogRead(A0);
  valorAng = map(valorPot,0,1023,0,55);

  if(valorAnt != valorAng){
    valorAnt = valorAng;
    Serial.println(String(valorPot) + " - " + String(valorAng));
    servo.write(valorAng);
  }

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
