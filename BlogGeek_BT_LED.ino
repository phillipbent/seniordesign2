//This sketch shows how to connect to a bluetooth device
// Arduino -> bluetooth
// Used with Android BlueTerm app

#include <SoftwareSerial.h> //Serial library

/**
 * Arduino connection HC-05 connection: 
 * HC-05  | Arduino
 * TX     | 5
 * RX     | 6
*/
// Here, we exchange them -
SoftwareSerial bt (5,6);  //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
int LEDPin = 13; //LED PIN on Arduino
int btdata; // the data given from the computer

void setup() {//Arduino Code (from Part I)
  bt.begin(115200);
  bt.println ("Bluetooth ON. Press 1 or 0 to blink LED..");
  pinMode (LEDPin, OUTPUT);
}

void loop() {
  if (bt.available()) {
    btdata = bt.read();
    if (btdata == '1') {
      //if 1
      digitalWrite (LEDPin, HIGH);
      bt.println ("LED ON!");
    }
    if (btdata == '0') {
      //if 0
      digitalWrite (LEDPin, LOW);
      bt.println ("LED OFF!");
    }
  }
  delay (100); //prepare for data
}
