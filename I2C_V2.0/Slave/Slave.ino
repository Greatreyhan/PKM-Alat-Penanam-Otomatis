#include <Wire.h>
#include <I2C_Anything.h>

const byte MY_ADDRESS = 42;

void setup() 
{
  Wire.begin (D1,D2);
  Serial.begin (115200);
  Serial.println("Start Receive");
  Wire.onReceive (receiveEvent);
}  // end of setup

volatile boolean haveData = false;
volatile byte fan;

void loop() 
{
  if (haveData)
    {
    Serial.print ("Received fan = ");
    Serial.println (fan);
    haveData = false;
    }  // end if haveData
}  // end of loop

// called by interrupt service routine when incoming data arrives
void receiveEvent (int howMany)
 {
 if (howMany >= (sizeof fan))
   {
   I2C_readAnything (fan);
   haveData = true;
   }  // end if have enough data
 }
