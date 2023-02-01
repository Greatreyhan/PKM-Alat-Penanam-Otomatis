#include <Wire.h>
#include <I2C_Anything.h>

// Self defined Pin
#define SensorProximity    8
#define RELAY1_VERTIKAL    22 
#define RELAY2_VERTIKAL    23
#define RELAY1_HORIZONTAL  24    
#define RELAY2_HORIZONTAL  25
#define RELAY1_JALAN       28
#define RELAY2_JALAN       29
#define RELAY_ROTOR        26
#define RELAY_PUMP         27
#define RELAY_BORA         30
#define RELAY_BORB         31
#define TRIG_KANAN         13
#define ECHO_KANAN         12
#define TRIG_TENGAH        11
#define ECHO_TENGAH        10
#define TRIG_KIRI          8
#define ECHO_KIRI          7
#define IR_SENSOR          9
#define DELAY_MOTOR        100
#define DELAY_ROTOR        1000
#define DELAY_PUMP         2000
#define MY_ADDRESS         8

#define KANAN   1
#define TENGAH  2
#define KIRI    3

volatile uint8_t getMaju = 0;
volatile uint8_t getMundur = 0;
volatile uint8_t getKanan = 0;
volatile uint8_t getKiri = 0;
volatile uint8_t getBor = 0;
volatile uint8_t getRotate = 0;
volatile uint8_t getMasuk = 0;
volatile uint32_t timeDelay = 0;

long durasi_kanan, durasi_kiri, durasi_tengah, long_kanan, long_kiri, long_tengah;
byte ir_sensor;

void setup() {
  
    //Bagian Mekanisme Gerak
    pinMode(RELAY1_VERTIKAL, OUTPUT);
    pinMode(RELAY2_VERTIKAL, OUTPUT);
    pinMode(RELAY1_HORIZONTAL, OUTPUT);
    pinMode(RELAY2_HORIZONTAL, OUTPUT);
    pinMode(RELAY1_JALAN, OUTPUT);
    pinMode(RELAY2_JALAN, OUTPUT);
    pinMode(RELAY_ROTOR, OUTPUT);
    pinMode(RELAY_PUMP, OUTPUT);
    pinMode(RELAY_BORA, OUTPUT);
    pinMode(RELAY_BORB, OUTPUT);
    pinMode(TRIG_KANAN, OUTPUT);
    pinMode(ECHO_KANAN, INPUT);
    pinMode(TRIG_TENGAH, OUTPUT);
    pinMode(ECHO_TENGAH, INPUT);
    pinMode(TRIG_KIRI, OUTPUT);
    pinMode(ECHO_KIRI, INPUT);
    Serial.begin(9600);  

    //         
//
//    digitalWrite(RELAY_ROTOR,HIGH);
//    delay(1000);
//    // deteksi magnet
//    while(ir_sensor == 0){
//      // roter on
//      ir_sensor = digitalRead(IR_SENSOR);
//      if(ir_sensor == 1){
//        
//        // roter off
//        digitalWrite(RELAY_ROTOR,LOW);
//  
//        // tunda selama 3 detik
//        delay(3000);
//      } 
//    }
    
//    digitalWrite(RELAY_ROTOR,HIGH);
//    delay(1000);
//    // deteksi magnet
//    while(ir_sensor == 0){
//      // roter on
//      ir_sensor = digitalRead(IR_SENSOR);
//      if(ir_sensor == 1){
//        
//        // roter off
//        digitalWrite(RELAY_ROTOR,LOW);
//  
//        // tunda selama 3 detik
//        delay(3000);
//      } 
//    }
}

void loop() {
//  delay(10000);
//  digitalWrite(RELAY1_JALAN,LOW);
//digitalWrite(RELAY2_JALAN,HIGH);
//delay(32000);
//digitalWrite(RELAY1_JALAN,LOW);
//digitalWrite(RELAY2_JALAN,LOW);  


//  Wire.begin(MY_ADDRESS);               
//  Wire.onReceive(receiveEvent); 
//
//  // maju 3 detik

//  
//  // 22 detik turun
//  digitalWrite(RELAY1_VERTIKAL,LOW);
//  digitalWrite(RELAY2_VERTIKAL,HIGH);
//  delay(2200);
//  digitalWrite(RELAY1_VERTIKAL,LOW);
//  digitalWrite(RELAY2_VERTIKAL,LOW);
//   
//  // bor on clockwise
//  digitalWrite(RELAY_BORA,LOW);
//  digitalWrite(RELAY_BORB,HIGH);
//  
//  // turun full
//  digitalWrite(RELAY1_VERTIKAL,LOW);
//  digitalWrite(RELAY2_VERTIKAL,HIGH);
//  delay(5000);
//  digitalWrite(RELAY1_VERTIKAL,LOW);
//  digitalWrite(RELAY2_VERTIKAL,LOW);
//  
//  // bor off
//  digitalWrite(RELAY_BORA,LOW);
//  digitalWrite(RELAY_BORB,LOW);
//  
  // 24 detik keatas
  digitalWrite(RELAY1_VERTIKAL,HIGH);
  digitalWrite(RELAY2_VERTIKAL,LOW);
  delay(24000);
//  
//  // roter on
//  digitalWrite(RELAY_ROTOR,HIGH);
//  
//  // deteksi magnet
//  while(ir_sensor == 0){
//    ir_sensor = digitalRead(IR_SENSOR);
//    if(ir_sensor == 1){
//      
//      // roter off
//      digitalWrite(RELAY_ROTOR,LOW);
//
//      // tunda selama 3 detik
//      delay(3000);
//    } 
//  }
//
//  // roter on
//  digitalWrite(RELAY_ROTOR,HIGH);
//
//  // deteksi magnet
//  while(ir_sensor == 0){
//    ir_sensor = digitalRead(IR_SENSOR);
//    if(ir_sensor == 1){
//      
//      // roter off
//      digitalWrite(RELAY_ROTOR,LOW);
//
//      // tunda selama 3 detik
//      delay(3000);
//    } 
//  }
//  
//  // maju 5 detik
//  digitalWrite(RELAY1_JALAN,LOW);
//  digitalWrite(RELAY2_JALAN,HIGH);
//  delay(5000);
//  digitalWrite(RELAY1_JALAN,LOW);
//  digitalWrite(RELAY2_JALAN,LOW);
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
    digitalWrite(RELAY1_VERTIKAL, LOW);
    digitalWrite(RELAY2_VERTIKAL, LOW);
    digitalWrite(RELAY1_HORIZONTAL, LOW);
    digitalWrite(RELAY2_HORIZONTAL, LOW);
    digitalWrite(RELAY1_JALAN, LOW);
    digitalWrite(RELAY2_JALAN, LOW);
    digitalWrite(RELAY_ROTOR, LOW);
    digitalWrite(RELAY_PUMP, LOW);
    digitalWrite(RELAY_BORA, LOW);
    digitalWrite(RELAY_BORB, LOW);
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

void Jalan_Mundur(){
  digitalWrite(RELAY1_JALAN,HIGH);
  digitalWrite(RELAY2_JALAN,LOW);
}

void Jalan_Maju(){
  digitalWrite(RELAY1_JALAN,LOW);
  digitalWrite(RELAY2_JALAN,HIGH);
}

void Jalan_Kanan(){
  digitalWrite(RELAY1_HORIZONTAL,HIGH);
  digitalWrite(RELAY2_HORIZONTAL,LOW);
}

void Jalan_Kiri(){
  digitalWrite(RELAY1_HORIZONTAL,LOW);
  digitalWrite(RELAY2_HORIZONTAL,HIGH);
}

void Jalan_Atas(){
  digitalWrite(RELAY1_VERTIKAL,HIGH);
  digitalWrite(RELAY2_VERTIKAL,LOW);
  Bor_CounterClockwise();
}

void Jalan_Bawah(){
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,HIGH);
  Bor_Clockwise();
}

void Jalan_Rotor_ON(){
  digitalWrite(RELAY_ROTOR,HIGH);
}

void Jalan_Rotor_OFF(){
  digitalWrite(RELAY_ROTOR,LOW);
}

void Jalan_Pump_ON(){
  digitalWrite(RELAY_PUMP,HIGH);
  delay(DELAY_PUMP);
}

void Jalan_Pump_OFF(){
  digitalWrite(RELAY_PUMP,LOW);
  delay(DELAY_PUMP);
}

void Bor_Clockwise(){
  digitalWrite(RELAY_BORA,HIGH);
  digitalWrite(RELAY_BORB,LOW);
}

void Bor_CounterClockwise(){
  digitalWrite(RELAY_BORA,LOW);
  digitalWrite(RELAY_BORB,HIGH);
}

void Read_Ping(){
  digitalWrite(TRIG_KANAN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_KANAN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_KANAN, LOW);
    durasi_kanan = pulseIn(ECHO_KANAN, HIGH);
    long_kanan = (durasi_kanan/2) / 29.1;
    Serial.print(long_kanan);
    Serial.println("cm");
  digitalWrite(TRIG_TENGAH, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_TENGAH, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_TENGAH, LOW);
    durasi_tengah = pulseIn(ECHO_TENGAH, HIGH);
    long_tengah = (durasi_tengah/2) / 29.1;
    Serial.print(long_tengah);
    Serial.println("cm");
  digitalWrite(TRIG_KIRI, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_KIRI, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_KIRI, LOW);
    durasi_kiri = pulseIn(ECHO_KIRI, HIGH);
    long_kiri = (durasi_kiri/2) / 29.1;
    Serial.print(long_kiri);
    Serial.println("cm");
}

void IR_Read(){
  ir_sensor = digitalRead(IR_SENSOR);
  Serial.print("Sensor Stopper");
  Serial.println(ir_sensor);
}
