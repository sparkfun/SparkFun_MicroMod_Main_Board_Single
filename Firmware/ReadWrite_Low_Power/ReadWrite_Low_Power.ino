/*
  SD Card Read/Write

  This example shows how to read and write data to and from an SD card file
  The circuit:

  SD card attached to SPI bus as follows:

   SD Card   <=> MicroMod Main Board <=> Artemis Processor Board
   -----------------------------------------------------------------
   SD ENABLE <=>  I2C_SDA1-PROCESSOR <=> pin 9
   PICO/SDO  <=>  SPI_PROCESSOR_SDO  <=> pin 38
   POCI/SDI  <=>  SPI_PROCESSOR_SDI  <=> pin 43
   CLK       <=>  SPI_PROCESSOR_SCK  <=> pin 42
   CS        <=>  D1_PROCESSOR       <=> pin 1 (Main Board - Single)
   or ...
   CS        <=>  G4_PROCESSOR       <=> pin 28 (Main Board - Double)

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>

//==========ARTEMIS==========
// The microSD Card CS pin is D1 for the MicroMod Main Board - Single and Artemis Processor (D1). Adjust for your processor if necessary.
const int SD_CS_PIN = 1;
// The microSD Card's CS pin is G4 for the MicroMod Main Board - Double and Artemis Processor (D28). Adjust for your processor if necessary.
//const int SD_CS_PIN = 28; 

// The microSD Card CS pin is SDA1 for the MicroMod Main Board - Single and Artemis Processor (D9). Adjust for your processor if necessary.
const int SD_ENABLE = 9;

File myFile;

void setup() {

  pinMode(SD_ENABLE, OUTPUT);  //sets the digital pin as output
  digitalWrite(SD_ENABLE, LOW);  //Power MicroSD card socket, pin is active low

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
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

  digitalWrite(SD_ENABLE, HIGH);  //remove power from MicroSD card socket for low power applications

}// end setup()

void loop() {
  // nothing happens after setup

}//end loop()
