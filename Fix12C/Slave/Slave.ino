#include <Wire.h>
#include <I2C_Anything.h>
#define MY_ADDRESS 8

uint32_t getMaju = 0;
uint32_t getMundur = 0;
uint32_t getKanan = 0;
uint32_t getKiri = 0;

void setup() {
   Serial.begin(9600);         
}

void loop() {
  Wire.begin(MY_ADDRESS);               
  Wire.onReceive(receiveEvent); 
  delay(100);
}

void receiveEvent(int howMany) {
   I2C_readAnything (getMaju);
   Serial.println(getMaju);
   I2C_readAnything (getMundur);
   Serial.println(getMundur);
   I2C_readAnything (getKanan);
   Serial.println(getKanan);
   I2C_readAnything (getKiri);
   Serial.println(getKiri);
}
