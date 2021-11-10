/*
  SD Card Read/Write

  This example shows how to read and write data to and from an SD card file
  The circuit:

  SD card attached to SPI bus as follows:

   SD Card  - MicroMod Artemis Processor Board
   -----------------------------------
   COPI/SDO - pin 38
   CIPO/SDI - pin 43
   CLK      - pin 42
   CS       - pin 1 (Main Board - Single) or 28 (Main Board - Double)

  created   Nov 2010
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>

//ARTEMIS
#define SD_CS_PIN 1 // The microSD Card CS pin is D1 for the MicroMod Main Board - Single and Artemis Processor (D1). Adjust for your processor if necessary.
//#define SD_CS_PIN 28 // The microSD Card's CS pin is G4 for the MicroMod Main Board - Double and Artemis Processor (D28). Adjust for your processor if necessary.

File myFile;

void setup() {
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
}

void loop() {
  // nothing happens after setup
}
