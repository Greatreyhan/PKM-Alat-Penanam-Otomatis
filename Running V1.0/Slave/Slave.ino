#include <Wire.h>
#include <I2C_Anything.h>

// Self defined Pin
#define SensorProximity 8

#define MY_ADDRESS 8

volatile uint8_t getMaju = 0;
volatile uint8_t getMundur = 0;
volatile uint8_t getKanan = 0;
volatile uint8_t getKiri = 0;
volatile uint8_t getBor = 0;
volatile uint8_t getRotate = 0;
volatile uint8_t getMasuk = 0;
volatile uint32_t timeDelay = 0;

void setup() {
   Serial.begin(9600);         
}

void loop() {
  Wire.begin(MY_ADDRESS);               
  Wire.onReceive(receiveEvent); 
   Serial.println("Start");
   Serial.println(getMaju);
   Serial.println(getMundur);
   Serial.println(getKanan);
   Serial.println(getKiri);
   Serial.println(getBor);
   Serial.println(getRotate);
   Serial.println(getMasuk);
   Serial.println(timeDelay);
   Serial.println("End");
  delay(1000);
}

void receiveEvent(int howMany) {
   I2C_readAnything (getMaju);
   I2C_readAnything (getMundur);
   I2C_readAnything (getKanan);
   I2C_readAnything (getKiri);
   I2C_readAnything (getBor);
   I2C_readAnything (getRotate);
   I2C_readAnything (getMasuk);
   I2C_readAnything (timeDelay);

}

void stopper(){


  delay(250);
  }
