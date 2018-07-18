int red = 5;
int green = 6;
int blue = 7;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //luz = analogRead(A0);
  changeColor(HIGH, LOW, LOW);
  Serial.println("RED");
  delay(500);

  /*changeColor(LOW, HIGH, LOW);
  Serial.println("GREEN");
  delay(1000);*/

  changeColor(LOW, LOW, HIGH);
  Serial.println("BLUE");
  delay(500);

  /*
  changeColor(HIGH, LOW, HIGH);
  Serial.println("ROXO");
  delay(1000);
  */
}

void changeColor(int vRed, int vGreen, int vBlue){
  digitalWrite(red, vRed);
  digitalWrite(green, vGreen);
  digitalWrite(blue, vBlue);
}

