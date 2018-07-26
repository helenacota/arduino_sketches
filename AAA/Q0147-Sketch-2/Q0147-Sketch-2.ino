#define pinBotaoA 5
#define pinBotaoB 4
#define pinPotenciometro A0
#define pinEnableMotorA 9      //Porta Digital PWM~
#define pinEnableMotorB 10     //Porta Digital PWM~

#define pinSentido1MotorA 3
#define pinSentido2MotorA 2

#define pinSentido1MotorB 7
#define pinSentido2MotorB 6

byte estadoA = 0;
bool estadoBotaoA = true;
bool estadoAntBotaoA = true;
unsigned long delayBotaoA;

byte estadoB = 0;
bool estadoBotaoB = true;
bool estadoAntBotaoB = true;
unsigned long delayBotaoB;

void setup() {
  Serial.begin(9600);
  pinMode(pinBotaoA, INPUT_PULLUP);
  pinMode(pinBotaoB, INPUT_PULLUP);
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);

  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);
}

void loop() {
Serial.println("vai");

  estadoBotaoA = digitalRead(pinBotaoA);
  if (!estadoBotaoA && estadoAntBotaoA) {
     if ((millis() - delayBotaoA) > 20) {
        estadoA++;
        if (estadoA > 2) {
           estadoA = 0;
        }
        delayBotaoA = millis();
     }
  }
  estadoAntBotaoA = estadoBotaoA;

  estadoBotaoB = digitalRead(pinBotaoB);
  if (!estadoBotaoB && estadoAntBotaoB) {
     if ((millis() - delayBotaoB) > 20) {
        estadoB++;
        if (estadoB > 2) {
           estadoB = 0;
        }
        delayBotaoB = millis();
     }
  }
  estadoAntBotaoB = estadoBotaoB;


  //if (estadoA == 0) {
  if (false) {
     analogWrite(pinEnableMotorA, 0);
  } else {
     Serial.println("oieeAA");
     analogWrite(pinEnableMotorA, 200); 

     if (estadoA == 1) {
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
     } else {
        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);      
     }
  } 


  if (false) {
     analogWrite(pinEnableMotorB, 0);
  } else {
     Serial.println("Ae");
     analogWrite(pinEnableMotorB, 200); 

     if (estadoB == 1) {
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);
     } else {
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, LOW);      
     }
  } 
  delay(500);
}

