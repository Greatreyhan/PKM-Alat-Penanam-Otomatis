#include <Wire.h>
#include <I2C_Anything.h>

#define SensorProximity    8
#define RELAY1_VERTIKAL    11 
#define RELAY2_VERTIKAL    12
#define RELAY1_HORIZONTAL  9     
#define RELAY2_HORIZONTAL  10
#define RELAY1_JALAN       5
#define RELAY2_JALAN       6
#define RELAY_ROTOR        7
#define RELAY_PUMP         8
#define DELAY_MOTOR        100
#define DELAY_ROTOR        1000
#define DELAY_PUMP         2000
#define MY_ADDRESS         8

volatile uint8_t getMaju = 0;
volatile uint8_t getMundur = 0;
volatile uint8_t getKanan = 0;
volatile uint8_t getKiri = 0;
volatile uint8_t getBor = 0;
volatile uint8_t getRotate = 0;
volatile uint8_t getMasuk = 0;
volatile uint32_t timeDelay = 0;

void setup() {
    pinMode(RELAY1_VERTIKAL, OUTPUT);
    pinMode(RELAY2_VERTIKAL, OUTPUT);
    pinMode(RELAY1_HORIZONTAL, OUTPUT);
    pinMode(RELAY2_HORIZONTAL, OUTPUT);
    pinMode(RELAY1_JALAN, OUTPUT);
    pinMode(RELAY2_JALAN, OUTPUT);
    pinMode(RELAY_ROTOR, OUTPUT);
    pinMode(RELAY_PUMP, OUTPUT);
    Serial.begin(9600);         
}

void loop() {             
  Disable_Relay();
  delay(DELAY_MOTOR);
}

void stopper(){
  delay(250);
}

void Disable_Relay(){
  digitalWrite(RELAY1_JALAN,LOW);
  digitalWrite(RELAY2_JALAN,LOW);
  digitalWrite(RELAY1_HORIZONTAL,LOW);
  digitalWrite(RELAY2_HORIZONTAL,LOW);
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,LOW);
  digitalWrite(RELAY_ROTOR,LOW);
  digitalWrite(RELAY_PUMP,LOW);
}

void Jalan_Maju(){
  digitalWrite(RELAY1_JALAN,HIGH);
  digitalWrite(RELAY2_JALAN,LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Mundur(){
  digitalWrite(RELAY1_JALAN,LOW);
  digitalWrite(RELAY2_JALAN,HIGH);
  delay(DELAY_MOTOR);
}

void Jalan_Kanan(){
  digitalWrite(RELAY1_HORIZONTAL,HIGH);
  digitalWrite(RELAY2_HORIZONTAL,LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Kiri(){
  digitalWrite(RELAY1_HORIZONTAL,LOW);
  digitalWrite(RELAY2_HORIZONTAL,HIGH);
  delay(DELAY_MOTOR);
}

void Jalan_Atas(){
  digitalWrite(RELAY1_VERTIKAL,HIGH);
  digitalWrite(RELAY2_VERTIKAL,LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Bawah(){
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,HIGH);
  delay(DELAY_MOTOR);
}

void Jalan_Rotor_ON(){
  digitalWrite(RELAY_ROTOR,HIGH);
  delay(DELAY_ROTOR);
}

void Jalan_Rotor_OFF(){
  digitalWrite(RELAY_ROTOR,LOW);
  delay(DELAY_ROTOR);
}

void Jalan_Pump_ON(){
  digitalWrite(RELAY_PUMP,HIGH);
  delay(DELAY_PUMP);
}

void Jalan_Pump_OFF(){
  digitalWrite(RELAY_PUMP,LOW);
  delay(DELAY_PUMP);
}
