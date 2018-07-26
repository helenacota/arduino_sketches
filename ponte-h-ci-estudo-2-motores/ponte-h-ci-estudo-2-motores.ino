//#define pinBotaoA 5
//#define pinBotaoB 4
//#define pinPotenciometro A0
#define pinEnableMotorA 9      //Porta Digital PWM~
#define pinEnableMotorB 10     //Porta Digital PWM~

#define pinSentido1MotorA 3
#define pinSentido2MotorA 2

#define pinSentido1MotorB 7
#define pinSentido2MotorB 6

byte estadoA = 0;
//bool estadoBotaoA = true;
//bool estadoAntBotaoA = true;
//unsigned long delayBotaoA;

//byte estadoB = 0;
//bool estadoBotaoB = true;
//bool estadoAntBotaoB = true;
//unsigned long delayBotaoB;

void setup() {
  Serial.begin(9600);
  //pinMode(pinBotaoA, INPUT_PULLUP);
  //pinMode(pinBotaoB, INPUT_PULLUP);
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);

  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);

  estadoA = 1;

//    digitalWrite(pinEnableMotorA, HIGH); 
//    digitalWrite(pinEnableMotorB, HIGH); 
}

void loop() {

Serial.println("vai");

    analogWrite(pinEnableMotorA, 200); 
    analogWrite(pinEnableMotorB, 100); 

    digitalWrite(pinSentido1MotorA, LOW);
    digitalWrite(pinSentido2MotorA, HIGH);

    digitalWrite(pinSentido1MotorB, LOW);
    digitalWrite(pinSentido2MotorB, HIGH);

  delay(3000);

Serial.println("volta");
    digitalWrite(pinSentido1MotorA, HIGH);
    digitalWrite(pinSentido2MotorA, LOW);

    digitalWrite(pinSentido1MotorB, HIGH);
    digitalWrite(pinSentido2MotorB, LOW);

  delay(3000);

//if (estadoA == 0) {
  //   analogWrite(pinEnableMotorA, 0);
  //} else {
 /*    analogWrite(pinEnableMotorA, map(500, 0, 1023, 0, 255)); 

     if (estadoA == 1) {
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
     } else {
        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);      
     }*/
  //} 


  /*if (estadoB == 0) {
     analogWrite(pinEnableMotorB, 0);
  } else {
     analogWrite(pinEnableMotorB, map(analogRead(pinPotenciometro), 0, 1023, 0, 255)); 

     if (estadoB == 1) {
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);
     } else {
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, LOW);      
     }
  } */
  delay(100);
}

