#include <Wire.h>
#include <I2C_Anything.h>

// Self defined Pin
#define SensorProximity 8
#define RELAY1_KANAN 2
#define RELAY2_KANAN 3
#define RELAY1_KIRI  4
#define RELAY2_KIRI  5
#define DELAY_MOTOR 100
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
    //Bagian Mekanisme Gerak
    pinMode(RELAY1_KANAN, OUTPUT);
    pinMode(RELAY1_KIRI, OUTPUT);
    pinMode(RELAY2_KANAN, OUTPUT);
    pinMode(RELAY2_KIRI, OUTPUT);
    
    Serial.begin(9600);         
}

void loop() {
  Wire.begin(MY_ADDRESS);               
  Wire.onReceive(receiveEvent); 
  delay(DELAY_MOTOR);
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
   if(getMaju){
   }
   else{
   }
   if(getMundur){
   }
   else{
   }
   if(getKanan){
   }
   else{
    }
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
}

void stopper(){

  delay(250);
}

void Jalan_Maju(){
  /*
   * Relay Kanan : 
   * N1 - ON 
   * N2 - OFF
   * Relay Kiri  :
   * N1 - OFF
   * N2 - ON
   */
  digitalWrite(RELAY1_KANAN,HIGH);
  digitalWrite(RELAY2_KANAN,LOW);
  digitalWrite(RELAY1_KIRI, LOW);
  digitalWrite(RELAY2_KIRI, HIGH);
  delay(DELAY_MOTOR);
}

void Jalan_Mundur(){
    /*
   * Relay Kanan : 
   * N1 - OFF 
   * N2 - ON
   * Relay Kiri  :
   * N1 - ON
   * N2 - OFF
   */
  digitalWrite(RELAY1_KANAN,LOW);
  digitalWrite(RELAY2_KANAN,HIGH);
  digitalWrite(RELAY1_KIRI, HIGH);
  digitalWrite(RELAY2_KIRI, LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Kanan(){
   /*
   * Relay Kanan : 
   * N1 - ON
   * N2 - OFF
   * Relay Kiri  :
   * N1 - ON
   * N2 - OFF
   */
  digitalWrite(RELAY1_KANAN,HIGH);
  digitalWrite(RELAY2_KANAN,LOW);
  digitalWrite(RELAY1_KIRI, HIGH);
  digitalWrite(RELAY2_KIRI, LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Kiri(){
   /*
   * Relay Kanan : 
   * N1 - OFF
   * N2 - ON
   * Relay Kiri  :
   * N1 - OFF
   * N2 - ON
   */
  digitalWrite(RELAY1_KANAN,LOW);
  digitalWrite(RELAY2_KANAN,HIGH);
  digitalWrite(RELAY1_KIRI, LOW);
  digitalWrite(RELAY2_KIRI, HIGH);
  delay(DELAY_MOTOR);
}
