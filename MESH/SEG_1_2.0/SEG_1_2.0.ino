#include <SoftwareSerial.h>
   
SoftwareSerial Seg1(9, 10); // (DOUT,DIN) -> (RX,TX)
int MP; // numero random que simula una lectura
int CO;
int T;
int hum;
char ID [] = "A01"; // Identificacion del modulo 


void setup() {
  Serial.begin(19200);   //initialize serial
  Seg1.begin(19200);
  
}

void loop() {

  // simulacion de muestra y tiempo
  MP = random(1000,1500);
  CO = random(300,500);
  T = random(10,99);
  hum = random(200,250);

  //info que manda
  Seg1.flush();
  Seg1.print(ID);
  Seg1.print("*");
  Seg1.print(MP);
  Seg1.print("*");
  Seg1.print(CO);
  Seg1.print("*");
  Seg1.print(T);
  Seg1.print("*");
  Seg1.println(hum);
  
  delay(10000);
  
   //envia la info  que escribo en el serial desde el pc
  if (Serial.available()) {
      Seg1.print((char)Serial.read()); 
  }
  
 
  
}
