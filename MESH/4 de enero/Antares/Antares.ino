#include <SoftwareSerial.h>
   
SoftwareSerial Antares(8, 9); // (DOUT,DIN) -> (RX,TX)



void setup() {
  Serial.begin(19200);   //initialize serial
  Antares.begin(19200);
  Antares.listen();
  
}

void loop() {

  String rawInfo;
  String Info;
  char data [8];
  
  char dat;
  int timeOut = 100; // tiempo al que deja de hacer "tomas" 
  unsigned long startTime;
  
   while ( millis() - startTime > timeOut){ // antes estaba en < pero se detena cuando
      // lee la info y la entrega ordenada 
      if (Antares.available()) {
      dat = Antares.read();  // imprime todo en una linea
      Serial.print(dat);
          if ( dat == '\r' || '\n'){ 
            break;                           
              }
          else {
             rawInfo += dat ;
             
             if (rawInfo.length()== 7){
             rawInfo.toCharArray(data, 8);
//             Serial.print(data[0]); 
//             Serial.print(data[1]); 
//             Serial.print(data[2]); 
//             Serial.print(data[3]); 
//             Serial.print(data[4]);
//             Serial.print(data[5]);
//             Serial.println(data[6]);
                }  
            }// fin else
           //Serial.print();          
         }// fin primer if
         
         
   }
}
  
   


 
