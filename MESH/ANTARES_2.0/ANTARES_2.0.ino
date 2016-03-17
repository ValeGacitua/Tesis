#include <SoftwareSerial.h>
   
SoftwareSerial Antares(9, 10); // (DOUT,DIN) -> (RX,TX)

char data[16];
char dat;
int i = 0;
bool flag = 0;

void setup() {
  
  Serial.begin(19200);   //initialize serial
  Antares.begin(19200);

}

void loop() {
  
            
     if (Antares.available()) {
            dat = Antares.read(); 
            delay (10);
//          Serial.println(dat);
             data [i] = dat;
              i++; 
              
         if (dat == '\r'){
              flag = 1;
              i=0;  
                      
             }// fin dat == \'r'
                                     
      
                                  
        }//fin primer if
        
     if ( flag ==  true ){
          Serial.print(data); 
          flag = false;
           delay (10);
                }// fin flag == true
                   
    }
   


 
   


 
