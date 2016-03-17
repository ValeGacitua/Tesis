#include <SoftwareSerial.h>
   
SoftwareSerial Antares(8, 9); // (DOUT,DIN) -> (RX,TX)

char data[5];
char dat;
int i;
int j=2;
int k; 
char S1 [4];
char S2 [4];

void setup() {
  
  Serial.begin(19200);   //initialize serial
  Antares.begin(19200);
 // Antares.listen();
}

void loop() {
  
            
     if (Antares.available()) {
          dat = Antares.read(); 
         // Serial.print(dat);
         
         if (dat != '\r'){
          
            data [i] = dat;
//            Serial.print(i);
//            Serial.print(data[i]);             
            i++; 
            
            if ( data[i]=='B'&& data[i+1]=='1' ){

                
                S2[k]= data[j];
                j++;
                k++;
//                Serial.print(k);
//                Serial.print("k");
                Serial.print(S2[k]);
               
              } //fin tercer if  
            else if( j>3 ){
                 if( k>3 ){
                  j=2;
                  k=0;
                  }                             
              } 
                                                     
            }//fin segundo if
            
         else if (i>4) {
              i=0;
              }// fin else 
                               
        }//fin primer ir
        
    }
   


 
   


 
