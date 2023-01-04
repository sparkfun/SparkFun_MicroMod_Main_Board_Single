/******************************************************************************

  WRITTEN BY: Ho Yun "Bobby" Chan
  @ SparkFun Electronics
  UPDATED: 1/3/2023
  DATE: 10/19/2021
  GITHUB REPO: https://github.com/sparkfun/SparkFun_MicroMod_Main_Board_Single
  DEVELOPMENT ENVIRONMENT SPECIFICS:
    Firmware developed using Arduino IDE v1.8.12

  ========== DESCRIPTION==========
  This example code toggles the Function Board's AP2112 3.3V voltage 
  regulator's enable pin. The Function Boards built-in power LED should blink.
  This example is based on Arduino's built-in Blink Example:

      https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

  Note that this example code uses the MicroMod Main Board - Single. The MicroMod
  Main Board - Double routes the PWR_EN# pins slightly different for the
  two function boards. 

  ========== HARDWARE CONNECTIONS ==========
  MicroMod Artemis Processor Board => MicroMod Main Board - Single => Function Board

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
       MicroMod Artemis Processor Board - https://www.sparkfun.com/products/16401
       MicroMod Main Board - Single - https://www.sparkfun.com/products/20748
       MicroMod Environmental Function Board - https://www.sparkfun.com/products/18632

  LICENSE: This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

/*Define the power enable pins for the processor board with either SDIO_DATA2 or A1.
  Depending on the processor board, the Arduino pin may be different. 

  Note: For MicroMod Main Board - Single v2.1, there is now only one GPIO available 
        to toggle the Power Enable 0 (PWR_EN0) pin. The previous defines for a few 
        Processor Boards are still available for those that have v1.1.

        For MicroMod Main Board - Single v1.1, certain Processor Boards like the 
        Artemis have SDIO_DATA2 and A1 available to control the Function Board's
        voltage regulator. SAMD51, ESP32, and STM32 Processor Board pins do not 
        have SDIO_DATA2, so users will need to reference the Processor Pin A1.
        Below are a few examples.*/



//==========ARTEMIS==========
//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v2.1 PWM1 => Artemis Processor Board (D45)
#define PWR_EN0 45

//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v1.1 SDIO_DATA2 => Artemis Processor Board (D4)
//#define PWR_EN0 4

//Alternative option that does the same thing. Make sure to just choose one for PWR_EN0
//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v1.1 A1 => Artemis Processor Board (A35)
//#define PWR_EN0 35



//==========TEENSY==========
//Function Board 0's "PWR_EN0" pin <= MicroMod Main- Single v2.1 PWM1 => Teensy Processor Board (2)
//#define PWR_EN0 2

//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v1.1 SDIO_DATA2 => Teensy Processor Board (39)
//#define PWR_EN0 39

//Alternative option that does the same thing. Make sure to just choose one for PWR_EN0
//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v1.1 A1 => Teensy Processor Board (A1)
//#define PWR_EN0 15



//Note: For those using Main - Single v1.1;
//      SAMD51, ESP32, and STM32 Processor Board Pins
//      do not have SDIO_DATA2 and SDIO_DATA1.

//==========SAMD51==========
//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v2.1 PWM1 => SAMD51 Processor Board (20)
//#define PWR_EN0 20

//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v1.1 A1 => SAMD51 Processor Board (18)
//#define PWR_EN0 18


//==========ESP32==========
//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v2.1 PWM1 => ESP32 Processor Board (12)
//#define PWR_EN0 12

//Function Board 0's "PWR_EN0" pin <= MicroMod Main - Single v1.1 A1 => ESP32 Processor Board (35)
//#define PWR_EN0 35



void setup() {
  // initialize the digital pin as an output.
    pinMode(PWR_EN0, OUTPUT);
}



void loop() {
  digitalWrite(PWR_EN0, HIGH); // turn the 3.3V regulator on (HIGH is the voltage level)
  delay(5000);                 // wait for a few seconds to do something with the function boards

  digitalWrite(PWR_EN0, LOW);  // turn the 3.3V regulator off by making the voltage LOW
  delay(5000);                 // wait for a few seconds before turning function boards back on

}
