#include <SoftwareSerial.h>
   
SoftwareSerial Seg2(8, 9); // (DOUT,DIN) -> (RX,TX)
int r; // numero random que simula una lectura
String ID = "B1"; // Identificacion del modulo 


void setup() {
  Serial.begin(19200);   //initialize serial
  Seg2.begin(19200);
  
}

void loop() {

  // simulacion de muestra y tiempo
  r = random(300,350);

  //info que manda
  Seg2.flush();
  Seg2.print(ID);
  Seg2.print(r);
  Seg2.println(fin);
  delay(1000);
  
  //envia la info  que escribo en el serial desde el pc
  if (Serial.available()) {
      Seg2.print(Serial.read()); 
  }
  
 
  
}
