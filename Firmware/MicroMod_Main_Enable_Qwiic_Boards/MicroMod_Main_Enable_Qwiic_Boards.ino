/******************************************************************************

  WRITTEN BY: Ho Yun "Bobby" Chan
  @ SparkFun Electronics
  DATE: 1/3/2023
  GITHUB REPO: https://github.com/sparkfun/SparkFun_MicroMod_Main_Board_Single
  DEVELOPMENT ENVIRONMENT SPECIFICS:
    Firmware developed using Arduino IDE v1.8.12

  ========== DESCRIPTION==========
  This example code toggles the Qwiic Port's AP7347DQ 3.3V voltage 
  regulator's enable pin. The Qwiic-enabled boards with built-in
  power LED should blink. The Main Board's QWC LED will also blink
  as well. This example is based on Arduino's built-in Blink Example:

      https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

  Note that this example code works for both the MicroMod Main Board - Single v2.1
  and Double v2.2. 

  ========== HARDWARE CONNECTIONS ==========
  MicroMod Artemis Processor Board => MicroMod Main Board - Single => Qwiic Board

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
       MicroMod Artemis Processor Board - https://www.sparkfun.com/products/16401
       MicroMod Main Board - Single - https://www.sparkfun.com/products/20748
       MicroMod Environmental Function Board - https://www.sparkfun.com/products/18632
       SparkFun GPS Breakout - Chip Antenna, SAM-M8Q - https://www.sparkfun.com/products/15210

  LICENSE: This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

/*Define the power enable pin for the processor board for I2C_SCL1-PROCESSOR.
  Depending on the processor board, the Arduino pin may be different.*/


//==========ARTEMIS==========
// Qwiic Port's "Qwiic EN" pin <= MicroMod Main Board I2C_SCL1-PROCESSOR => Artemis Processor Board (D8)
#define QWIIC_EN 8 


//==========TEENSY==========
// Qwiic Port's "QWIIC_EN" pin <= MicroMod Main Board I2C_SCL1-PROCESSOR => Teensy Processor Board (24)
//#define QWIIC_EN 24


//==========SAMD51==========
// Qwiic Port's "QWIIC_EN" pin <= MicroMod Main Board I2C_SCL1-PROCESSOR => SAMD51 Processor Board (36)
//#define QWIIC_EN 36


//==========ESP32==========
// Qwiic Port's "QWIIC_EN" pin <= MicroMod Main Board I2C_SCL1-PROCESSOR => ESP32 Processor Board (?25??)
//#define QWIIC_EN 25


void setup() {
  // initialize the digital pin as an output.
    pinMode(QWIIC_EN, OUTPUT);
}



void loop() {
  digitalWrite(QWIIC_EN, HIGH); // turn the 3.3V regulator on (HIGH is the voltage level)
  delay(5000);                 // wait for a few seconds to do something with the Qwiic-enabled board(s)

  digitalWrite(QWIIC_EN, LOW);  // turn the 3.3V regulator off by making the voltage LOW
  delay(5000);                 // wait for a few seconds before turning Qwiic-enabled board(s) back on

}
