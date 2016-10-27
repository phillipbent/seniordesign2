#include <SoftwareSerial.h> //Serial library
SoftwareSerial bt (0,1);
int pirState=0;
int count=0;
int LED=13;
int place=0;
int PIR=4;

void setup() 
{
  pinMode(PIR,INPUT);
  pinMode(LED,OUTPUT);
  bt.begin( 115200 );    // 115200 is the default baud rate for the serial Bluetooth module
}
 
void loop() 
{
  // listen for the data
  
  pirState = digitalRead(PIR);//return 0 for off and 1 for on
  if (pirState > 0) 
 {
  bt.print("1");
  if ( bt.available() > 0 ) 
  {
  // read a numbers from serial port
    count = Serial.read();
  // turn on LED
        if (count > 0)
        {
        digitalWrite(LED, HIGH);
        place = 1;
        }
  } 
  }  
  else
  {
  }
  
}
