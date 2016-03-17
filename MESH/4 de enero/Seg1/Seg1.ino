#include <SoftwareSerial.h>
   
SoftwareSerial Seg1(8, 9); // (DOUT,DIN) -> (RX,TX)
int r; // numero random que simula una lectura
unsigned long tiempo; // tiempo al que r fue enviado

char ID []= {"A1"}; // Identificacion del modulo


void setup() {
  Serial.begin(19200);   //initialize serial
  Seg1.begin(19200);
  
}

void loop() {

  // simulacion de muestra y tiempo
  r = random(250,300);
  
  
  //info que manda
  Seg1.print(ID);
  Seg1.print(r);
  Seg2.println( ID ); 
  delay(1000);
  
  //envia la info  
  if (Serial.available()) {
      Seg1.print((char)Serial.read()); 
  }
 
  
}
