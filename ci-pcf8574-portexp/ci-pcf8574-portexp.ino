#include <Wire.h>

#define qtdeCi  3

byte enderecosPCF8574[qtdeCi] = {32,33,34};                //PCF8574P - Endereços de 32 a 39     32-> A0=0 A1=0 A2=0     0=GND           PINOS:
                                                           //  ou                                33-> A0=1 A1=0 A2=0     1=VCC             PCF8574P ou PCF8574AP (DIP16) 
                                                           //PCF8574T                            34-> A0=0 A1=1 A2=0                       A0=1 
                                                           //  ou                                35-> A0=1 A1=1 A2=0                       A1=2
                                                           //PCF8574TS                           36-> A0=0 A1=0 A2=1                       A2=3
                                                           //                                    37-> A0=1 A1=0 A2=1
                                                           //                                    38-> A0=0 A1=1 A2=1                       PCF8574TS ou PCF8574ATS (SSOP20)
                                                           //                                    39-> A0=1 A1=1 A2=1                       A0=6
                                                           //                                                                              A1=7   
                                                           //PCF8574AP - Endereços de 56 a 63    56-> A0=0 A1=0 A2=0                       A2=9
                                                           //  ou                                57-> A0=1 A1=0 A2=0  
                                                           //PCF8574AT                           58-> A0=0 A1=1 A2=0                       PCF8574T ou PCF8574AT (SO16)
                                                           //  ou                                59-> A0=1 A1=1 A2=0                       A0=1
                                                           //PCF8574ATS                          60-> A0=0 A1=0 A2=1                       A1=2
                                                           //                                    61-> A0=1 A1=0 A2=1                       A2=3
                                                           //                                    62-> A0=0 A1=1 A2=1
                                                           //                                    63-> A0=1 A1=1 A2=1 
bool ciPCF8574PinMode(byte pino, int modo = -1);
void ciPCF8574Write(byte pino, bool estado);
bool ciPCF8574Read(byte pino);


void setup() {
    Wire.begin();

    for (int nL=0; nL <= 11; nL++) { 
        ciPCF8574PinMode(nL, INPUT);
    }

    for (int nL=12; nL <= 23; nL++) { 
        ciPCF8574PinMode(nL, OUTPUT);
    }
}

void loop() {
static unsigned long delayPisca;

  if ( (millis() - delayPisca) < 500 ) {
     ciPCF8574Write(12, HIGH);
     ciPCF8574Write(16, LOW);
     ciPCF8574Write(20, HIGH);
  } else {
     ciPCF8574Write(12, LOW);
     ciPCF8574Write(16, HIGH);
     ciPCF8574Write(20, LOW);
  }
  if ( (millis() - delayPisca) > 1000 ) {
     delayPisca = millis();
  }


  ciPCF8574Write(12, !ciPCF8574Read(0));
  ciPCF8574Write(13, !ciPCF8574Read(1));
  ciPCF8574Write(14, !ciPCF8574Read(2));
  ciPCF8574Write(15, !ciPCF8574Read(3));
  ciPCF8574Write(16, !ciPCF8574Read(4));
  ciPCF8574Write(17, !ciPCF8574Read(5));
  ciPCF8574Write(18, !ciPCF8574Read(6));
  ciPCF8574Write(19, !ciPCF8574Read(7));
  ciPCF8574Write(20, !ciPCF8574Read(8));
  ciPCF8574Write(21, !ciPCF8574Read(9));
  ciPCF8574Write(22, !ciPCF8574Read(10));
  ciPCF8574Write(23, !ciPCF8574Read(11));

}


bool ciPCF8574PinMode(byte pino, int modo) {
static byte modoPinos[qtdeCi];

  if (modo == -1) {
     return bitRead(modoPinos[pino / 8], pino % 8); 
  } else {
     bitWrite(modoPinos[pino / 8], (pino % 8), modo);
     return modo;
  }
}


void ciPCF8574Write(byte pino, bool estado) {
static bool inicio = true;
static byte estadoPin[qtdeCi];

    if (inicio) {
       byte estadoCI;
       for (int nL = 0; nL < qtdeCi; nL++) {

           for (int nM = 0; nM < 8; nM++) {
               bitWrite(estadoCI, nM, !ciPCF8574PinMode(nM + (nL * 8)) );  
           }
           estadoPin[nL] = estadoCI;
       }
       inicio = false;
    }

    bitWrite(estadoPin[pino / 8], pino % 8, estado);
    
    Wire.beginTransmission(enderecosPCF8574[pino / 8]);    
    Wire.write(estadoPin[pino / 8]);                            
    Wire.endTransmission();        
}

bool ciPCF8574Read(byte pino) {
byte lido;
bool estado;

   Wire.requestFrom(enderecosPCF8574[pino / 8], 1);
   if(Wire.available()) {   
      lido = Wire.read();        
   }
       
   estado = bitRead(lido, pino % 8);
   return estado;  
}


