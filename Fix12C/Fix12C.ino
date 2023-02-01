#include <Wire.h>
#include <I2C_Anything.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define SLAVE_ADDRESS 8

uint32_t getMaju = 0;
uint32_t getMundur = 0;
uint32_t getKanan = 0;
uint32_t getKiri = 0;

void setup() 
{
  Wire.begin(D1, D2);
  Serial.begin(9600);
}  
void loop() {
   kirimData();
   delay(1000);
}  

void kirimData(){
     getMaju = 124;
     getMundur = 32;
     getKanan = 12;
     getKiri = 11;
    Wire.beginTransmission (SLAVE_ADDRESS);
     I2C_writeAnything (getMaju);
     Serial.println(getMaju);
     I2C_writeAnything (getMundur);
     Serial.println(getMundur);
     I2C_writeAnything (getKanan);
     Serial.println(getKanan);
     I2C_writeAnything (getKiri);
     Serial.println(getKiri);
    Wire.endTransmission();
}
