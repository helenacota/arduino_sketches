#define motorEsqIn 5
#define motorEsqOut 6
#define motorDirIn 9
#define motorDirOut 10

int potEsqY = 0;
int potDirX = 0;
int velocidade = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorEsqIn,OUTPUT);
  pinMode(motorEsqOut,OUTPUT);
  pinMode(motorDirIn,OUTPUT);
  pinMode(motorDirOut,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  potEsqY = analogRead(A1);
  potDirX = analogRead(A0);

  if(potEsqY >= 510 && potEsqY <= 540)
  {
    velocidade = 0;
    freia();
  }else{
    if(potEsqY < 510){
      velocidade = map(potEsqY,510,0,0,255);
      paraFrente(velocidade);
    }else{
      velocidade = map(potEsqY,510,1023,0,255);
      paraTras(velocidade);
    }
  }
  Serial.println(String(potEsqY) + " - " + String(velocidade));
  delay(100);

}

void freia(){
  digitalWrite(motorEsqIn, HIGH);
  digitalWrite(motorEsqOut, HIGH);
  digitalWrite(motorDirIn, HIGH);
  digitalWrite(motorDirOut, HIGH);
}

void paraTras(int velocidade){
  analogWrite(motorEsqIn, velocidade);
  analogWrite(motorEsqOut, 0);
  analogWrite(motorDirIn, velocidade);
  analogWrite(motorDirOut, 0);
}

void paraFrente(int velocidade){
  analogWrite(motorEsqIn, 0);
  analogWrite(motorEsqOut, velocidade);
  analogWrite(motorDirIn, 0);
  analogWrite(motorDirOut, velocidade);
}

