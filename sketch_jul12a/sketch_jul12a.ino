void setup() {
  // put your setup code here, to run once:
  //pinMode(10,OUTPUT);
  //pinMode(9,OUTPUT);
  //pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //sirene();
  //sinos();
  //digitalWrite(7, HIGH);
  analogWrite(5, 2);
  delay(2000);
  analogWrite(5, 0);
  //digitalWrite(7, LOW);
  delay(2000);
}

void sinos() {
  int Luz1 = 10;
  int Luz2 = 9;
  int Luz3 = 6;
  int Luz4 = 5;
  digitalWrite(Luz4, HIGH);
  delay(1000);
  digitalWrite(Luz4, LOW);
  digitalWrite(Luz2, HIGH);
  delay(1000);
  digitalWrite(Luz2, LOW);
  digitalWrite(Luz3, HIGH);
  delay(1000);
  digitalWrite(Luz3, LOW);
  digitalWrite(Luz1, HIGH);
  delay(1000);
  digitalWrite(Luz1, LOW);
  delay(2000);

  digitalWrite(Luz1, HIGH);
  delay(1000);
  digitalWrite(Luz1, LOW);
  digitalWrite(Luz3, HIGH);
  delay(1000);
  digitalWrite(Luz3, LOW);
  digitalWrite(Luz4, HIGH);
  delay(1000);
  digitalWrite(Luz4, LOW);
  digitalWrite(Luz2, HIGH);
  delay(1000);
  digitalWrite(Luz2, LOW);
  delay(2000);

}

void sirene(){
  int Luz1 = 10;
  int Luz2 = 9;
  int Luz3 = 6;
  int Luz4 = 5;
  digitalWrite(Luz4, HIGH);
  digitalWrite(Luz3, HIGH);
  digitalWrite(Luz2, LOW);
  digitalWrite(Luz1, LOW);
  delay(400);
  digitalWrite(Luz4, LOW);
  digitalWrite(Luz3, LOW);
  digitalWrite(Luz2, HIGH);
  digitalWrite(Luz1, HIGH);
  delay(400);  
}

