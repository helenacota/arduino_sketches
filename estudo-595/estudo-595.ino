// This is the working code for SN74HC595

#define DS_pin 4
#define STCP_pin 6
#define SHCP_pin 5
// declare DS, STCP, and SHCP pin as numbers, not as variables. Thanks Steven Van Hulle
boolean registers[8]; // default values = false ( = 0 )
int time1 = 300;         // set delay time
void writeReg() {
  digitalWrite(STCP_pin, LOW);        // fixed, SHCP_pin ==> STCP_pin
  for (int i=7; i>=0; i--)                     // An array, register[8] for example, has 8 indexes noted as 0-7. Thanks rtcinema
  {
    digitalWrite(SHCP_pin, LOW);     // fixed, SHCP_pin ==> STCP_pin
    digitalWrite(DS_pin, registers[i]);
    digitalWrite(SHCP_pin, HIGH);    // fixed, SHCP_pin ==> STCP_pin
  }
  digitalWrite(STCP_pin, HIGH);      // fixed, SHCP_pin ==> STCP_pin
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  writeReg(); // write the default set of registers[] to DS_pin, one by one
}
void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i=0; i<=7; i++) // fixed, i<=7 is a bit easier to understand than i<8
  {
    registers[i]=HIGH;
    delay(time1);
    writeReg();
    Serial.print(i);
  }
  Serial.println("vai");
  for (int i=7; i>=0; i--) // fixed
  {
    registers[i]=LOW;
    delay(time1);
    writeReg();
    Serial.print(i);  
   }
  
  Serial.println("volta");
  delay(1000); // rest between loops
  
}
