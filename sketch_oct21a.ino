
byte PIR = 4;
byte LED = 13;
int pirState=0;
int count=0;
int place=0;

void setup() 
{
  pinMode(PIR,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin( 115200 );    // 115200 is the default baud rate for the serial Bluetooth module
}
 
void loop() 
{
  // listen for the data
  
  pirState = digitalRead(PIR);//return 0 for off and 1 for on
  if (pirState > 0) 
 {
  Serial.print("1");
  if ( Serial.available() > 0 ) 
  {
  // read a numbers from serial port
    count = Serial.parseInt();
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



