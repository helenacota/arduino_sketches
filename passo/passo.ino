#include<Stepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11
#define potBase A0

int stepsPerRevolution = 200; 

int valorPotBase;
int newSpeed = 60;
int mapSpeed = 0;
int oldmapSpeed = 0;
int botao1 = 0;
int botao2 = 0;

Stepper myStepper (stepsPerRevolution, in1, in3, in2, in4);

void setup() {

  pinMode(4,INPUT);
  pinMode(5,INPUT);
  // set the speed at 60 rpm:
  myStepper.setSpeed(newSpeed);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  valorPotBase = analogRead(potBase);

  //valorPotBase = 1024;
  valorPotBase = map(valorPotBase,0,1024,1024,0);
  mapSpeed = map(valorPotBase,0,1024,0,120);

  botao1 = digitalRead(4);
  botao2 = digitalRead(5);

  stepsPerRevolution = 0;
  if(botao1 == HIGH){
    stepsPerRevolution = 200;
  }
  if(botao2 == HIGH){
    stepsPerRevolution = -200;
  }
  if(mapSpeed == 0)
  {
    mapSpeed = oldmapSpeed;
  }
  
  if(mapSpeed != oldmapSpeed)
  {
    Serial.println("pot: " + String(valorPotBase) + " mapSpeed: " + String(mapSpeed) + " newSpeed: " + String(newSpeed));
    /*if(mapSpeed <= 0){
      newSpeed = mapSpeed * -1;
      stepsPerRevolution = -200;
    }else{*/
      newSpeed = mapSpeed;
      //stepsPerRevolution = 200;
    //}
    oldmapSpeed = mapSpeed;
    myStepper.setSpeed(newSpeed);
  }
  
  // step one revolution  in one direction:
  //Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(50);

  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(500);
}
