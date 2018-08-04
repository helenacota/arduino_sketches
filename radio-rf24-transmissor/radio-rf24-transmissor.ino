#include <RF24.h>

//*************** Definição dos Pinos ***********************
#define pinCE    9 // era 7
#define pinCSN   8
#define pinPot1  A1  //Frente e Reverso
#define pinPot2  A2  //Direito e Esquerdo
#define pinBotao A0

struct tipoDadosRF
{
   int pot1 = 512;
   int pot2 = 512;
   boolean botao = false;
};
tipoDadosRF dadosRF;

RF24 radio(pinCE,pinCSN);

const uint64_t pipeOut = 0xE8E8F0F0E1LL;


//*************** Controle do Joystick ************
boolean botaoAnt = HIGH;
boolean botao    = HIGH;


void setup() {
  //*************** Controle do RF ***********************
  radio.begin();
  radio.setPALevel( RF24_PA_LOW );     //RF24_PA_MIN  / RF24_PA_LOW / RF24_PA_HIGH / RF24_PA_MAX
  radio.setDataRate( RF24_250KBPS );   //RF24_250KBPS / RF24_1MBPS  / RF24_2MBPS
  radio.openWritingPipe(pipeOut);


  //*************** Controle do Joystick ************
  pinMode(pinBotao, INPUT_PULLUP);

  delay(100);
}


void loop() {
  //*************** Controle do RF ***********************
  radio.write( &dadosRF, sizeof(tipoDadosRF) );


  //*************** Controle do Joystick ************
  dadosRF.pot1 = analogRead(pinPot1);
  dadosRF.pot2 = analogRead(pinPot2);
    
  botao = digitalRead(pinBotao);
  if (botao && (botao != botaoAnt)) {
     dadosRF.botao = !dadosRF.botao;
  }
  botaoAnt = botao;
}
