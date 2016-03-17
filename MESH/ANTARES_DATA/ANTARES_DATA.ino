#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
   
SoftwareSerial Antares(9, 10); // (DOUT,DIN) -> (RX,TX)

char data[7];
char dat;
int i;
File Archivo;

void setup() {
  
  Serial.begin(19200);   //initialize serial
  Antares.begin(19200);


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  Archivo = SD.open("ikki.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (Archivo) {
    Serial.print("Writing to test.txt...");
    Archivo.println("testing 1, 2, 3.");
    // close the file:
    Archivo.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

}

void loop() {
  
            
     if (Antares.available()) {
          dat = Antares.read(); 
//          Serial.println(dat);
         
         if (dat != '\r'){
          
            data [i] = dat;
//            Serial.print(i);
            Serial.print(data[i]);             
            i++; 
             }
         else if (i>6) {
              i=0;
              }// fin else 
                                     
        
                                  
        }//fin primer ir
            
    }
   


 
   


 
