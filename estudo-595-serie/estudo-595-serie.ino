#define pinSH_CP 9   //Pino Clock
#define pinST_CP 10  //Pino Latch
#define pinDS    11  //Pino Data
#define qtdeCI   2

void ci74HC595Write(byte pino, bool estado);

void setup() {
   pinMode(pinSH_CP, OUTPUT);
   pinMode(pinST_CP, OUTPUT);
   pinMode(pinDS, OUTPUT);


      ci74HC595Write(1, HIGH);
delay(3000);
}

void loop() {

  for (int nL=0; nL<24; nL++) {
      ci74HC595Write(nL, HIGH);
      delay(100); 
      ci74HC595Write(nL, LOW);
  }



  for (int nL=0; nL<8; nL++) {
      ci74HC595Write(nL, HIGH);
  }
  delay(1000);
  for (int nL=0; nL<8; nL++) {
      ci74HC595Write(nL, LOW);
  }
  for (int nL=8; nL<16; nL++) {
      ci74HC595Write(nL, HIGH);
  }
  delay(1000);
  for (int nL=8; nL<16; nL++) {
      ci74HC595Write(nL, LOW);
  }

  // 3º CI ?!?
  /*for (int nL=16; nL<24; nL++) {
      ci74HC595Write(nL, HIGH);
  }
  delay(1000);
  for (int nL=16; nL<24; nL++) {
      ci74HC595Write(nL, LOW);
  }
  delay(500);
  */

  for (int nP=0; nP<5; nP++) {
      for (int nL=0; nL<16; nL++) {
          ci74HC595Write(nL, HIGH);
      }
      delay(100);
      for (int nL=0; nL<16; nL++) {
          ci74HC595Write(nL, LOW);
      }
      delay(100);
  }
  delay(400);


  for (int nP=0; nP<3; nP++) {
    for (int nL=0; nL<16; nL++) {
        ci74HC595Write(nL, HIGH);
        delay(10); 
    }
    for (int nL=15; nL>=0; nL--) {
        ci74HC595Write(nL, LOW);
        delay(10); 
    }
  }
   
}

void ci74HC595Write(byte pino, bool estado) {
static byte ciBuffer[qtdeCI];

bitWrite(ciBuffer[pino / 8], pino % 8, estado);

digitalWrite(pinST_CP, LOW); //Inicia a Transmissão

digitalWrite(pinDS, LOW);    //Apaga Tudo para Preparar Transmissão
digitalWrite(pinSH_CP, LOW);

for (int nC = qtdeCI-1; nC >= 0; nC--) {
    for (int nB = 7; nB >= 0; nB--) {

        digitalWrite(pinSH_CP, LOW);  //Baixa o Clock      
        
        digitalWrite(pinDS,  bitRead(ciBuffer[nC], nB) );     //Escreve o BIT
        
        digitalWrite(pinSH_CP, HIGH); //Eleva o Clock
        digitalWrite(pinDS, LOW);     //Baixa o Data para Previnir Vazamento      
    }  
}

digitalWrite(pinST_CP, HIGH);  //Finaliza a Transmissão

}

