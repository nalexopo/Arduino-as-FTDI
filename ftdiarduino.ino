#include <Arduino.h>
#include <string.h>

//declare your arduino UART pins
#define RXD2 16  
#define TXD2 17

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //USB 
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Hello world");
  
}

void loop() {
while( Serial2.available()) 
  {
    char c=0;
    c=char(Serial2.read());
    Serial.print(c);
           
  }

  // USBUART rx ----> UART1 tx
  while( Serial.available()) 
  {
    char c=0;
    c=char(Serial.read());
    Serial2.print(c);
    
  } 
}
