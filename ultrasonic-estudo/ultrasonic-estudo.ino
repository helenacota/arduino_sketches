#include<Servo.h>
#include <Ultrasonic.h>

#define servoPort 3

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);


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

    //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  /*Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec); */
  
  Serial.println("Angulo: "+ String(valorAng) + " Distancia: " + cmMsec);

  servo.write(valorAng);
  delay(100);
  

}
