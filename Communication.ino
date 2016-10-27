#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 12

byte PIR1 = 4;
byte PIR2 = 2;
byte PIR3 = 7;
byte LED = 13;
int pirState=0;
int count=0;
int place=0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(36, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  pinMode(PIR1,INPUT);
  pinMode(PIR2,INPUT);
  pinMode(PIR3,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin( 115200 );    // 115200 is the default baud rate for the serial Bluetooth module

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() 
{
  // listen for the data
  
  pirState = digitalRead(PIR1)+digitalRead(PIR2)+digitalRead(PIR3);//return 0 for off and 1 for on
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
        colorWipe(strip.Color(127, 127, 127), 50); // White
        place = 1;
        }
  } 
  }  
  else
  {
  }
  
}
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}



