import processing.serial.*;
Serial mySerial;
PrintWriter output;
void setup() {
   mySerial = new Serial( this, "COM5", 19200 );
   output = createWriter( "ikki.txt" );
}
void draw() {
    if (mySerial.available() > 0 ) {
         String value = mySerial.readString();
         if ( value != null ) {
              output.println( value );
         }
    }
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}
