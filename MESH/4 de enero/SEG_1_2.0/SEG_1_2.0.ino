#include <SoftwareSerial.h>
   
SoftwareSerial Seg1(8, 9); // (DOUT,DIN) -> (RX,TX)
int r; // numero random que simula una lectura
char ID [] = "A1"; // Identificacion del modulo 


void setup() {
  Serial.begin(19200);   //initialize serial
  Seg1.begin(19200);
  
}

void loop() {

  // simulacion de muestra y tiempo
  r = random(400,450);

  //info que manda
  Seg1.flush();
  Seg1.write(ID);
  Seg1.println(r);
  
  delay(1000);
  
   //envia la info  que escribo en el serial desde el pc
  if (Serial.available()) {
      Seg1.print((char)Serial.read()); 
  }
  
 
  
}
