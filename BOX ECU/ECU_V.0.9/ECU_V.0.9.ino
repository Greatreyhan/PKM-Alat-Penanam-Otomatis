// Self defined Pin
#define RELAY1_VERTIKAL    27 
#define RELAY2_VERTIKAL    26
#define RELAY1_HORIZONTAL  24    
#define RELAY2_HORIZONTAL  25
#define RELAY1_JALAN       28
#define RELAY2_JALAN       29
#define RELAY_ROTOR        23
#define RELAY_PUMP         22
#define RELAY_BORA         30
#define RELAY_BORB         31
#define IR_SENSOR          9
#define DELAY_MOTOR        1000
#define DELAY_PUMP         2000
#define DELAY_CALL         500
#define MY_ADDRESS         8

#define D1 2
#define D2 3
#define D3 4
#define D4 5
#define DP 6

#define C0 18 // Data HC-SR04
#define C1 19

#define B0 9// Data Magnet Sensor

#define KANAN   1
#define TENGAH  2
#define KIRI    3

long durasi_kanan, durasi_kiri, durasi_tengah, long_kanan, long_kiri, long_tengah;
byte ir_sensor;

char data[3] = "";

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
  
    //Bagian Data 
    pinMode(D1, INPUT);
    pinMode(D2, INPUT);
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
    pinMode(DP, INPUT);
    Serial.begin(9600);

    //Bagian Sensor Jarak
    pinMode(C0, INPUT);
    pinMode(C1, INPUT);
//    attachInterrupt(digitalPinToInterrupt(C0), interr, CHANGE);
//    attachInterrupt(digitalPinToInterrupt(C1), interr, CHANGE);

    // Bagian Sensor Magnet
    pinMode(B0, INPUT);
    
    Disable_Relay();
    Serial.println("Begin");
}


void loop() {

    // Konfigurasi Sensor Magnet
    if(!(digitalRead(B0))){
      Serial.println("ada Magnet");
    }

    // Konfigurasi Sensor Jarak
    if(digitalRead(C0) == 0 && digitalRead(C1) == 0){
      Serial.println("Tidak Ada Halangan");
    }
    if(digitalRead(C0) == 0 && digitalRead(C1) == 1){
      Serial.println("Halangan di Kanan");
    }
    if(digitalRead(C0) == 1 && digitalRead(C1) == 0){
      Serial.println("Halangan di Tengah");
    }
    if(digitalRead(C0) == 1 && digitalRead(C1) == 1){
      Serial.println("Halangan di Kiri");
    }
  
    // Konfigurasi Relay
    if(digitalRead(DP) == 1){
      Serial.print(D1);
      Serial.print(D2);
      Serial.print(D3);
      Serial.println(D4);
      if(digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 0 && digitalRead(D4) == 0){
        // Null
        Serial.println("0000 : null");
        stopper();
      }
      if(digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 0 && digitalRead(D4) == 1){
        // Tanam
        Serial.println("0001 : Tanam");
        Tanam_Bibit();
        stopper();
      }
      if(digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 1 && digitalRead(D4) == 0){
        // Panah Atas
        Serial.println("0010 : Maju");
        Jalan_Maju();
        stopper();
      }
      if(digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 1 && digitalRead(D4) == 1){
        // Panah Bawah
        Serial.println("0011 : Mundur");
        Jalan_Mundur();
        stopper();
      }
      if(digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 0 && digitalRead(D4) == 0){
        // Panah Kanan
        Serial.println("0100 : Kanan");
        Jalan_Kanan();
        stopper();
      }
      if(digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 0 && digitalRead(D4) == 1){
        // Panah Kiri
        Serial.println("0101 : Kiri");
        Jalan_Kiri();
        stopper();
      }
      if(digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 1 && digitalRead(D4) == 0){
        // Jalan Kiri Maju
        Serial.println("0110 : Maju Kiri");
        Jalan_Maju_Kiri();
        stopper();
      }
      if(digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 1 && digitalRead(D4) == 1){
        // Jalan Kanan Maju
        Serial.println("0111 : Maju Kanan");
        Jalan_Maju_Kanan();
        stopper();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 0 && digitalRead(D4) == 0){
        // Jalan Kiri Mundur
        Serial.println("1000 : Mundur Kiri");
        Jalan_Mundur_Kiri();
        stopper();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 0 && digitalRead(D4) == 1){
        // Jalan Kanan Mundur
        Serial.println("1001 : Mundur Kanan");
        Jalan_Mundur_Kanan();
        stopper();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 1 && digitalRead(D4) == 0){
        // Null
        Serial.println("1010 : null");
        stopper();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 1 && digitalRead(D4) == 1){
        // Null
        Serial.println("1011 : null");
        Kalibrasi_Atas();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 1 && digitalRead(D3) == 0 && digitalRead(D4) == 0){
        // Null
        Serial.println("1100 : null");
        Kalibrasi_Bawah();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 1 && digitalRead(D3) == 0 && digitalRead(D4) == 1){
        // Null
        Serial.println("1101 : null");
        Kalibrasi_Rotor();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 1 && digitalRead(D3) == 1 && digitalRead(D4) == 0){
        // Null
        Serial.println("1110 : null");
        stopper();
      }
      if(digitalRead(D1) == 1 && digitalRead(D2) == 1 && digitalRead(D3) == 1 && digitalRead(D4) == 1){
        // Null
        Serial.println("1111 : null");
        stopper();
      }
    }

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

void interr(){
    Serial.println("Interrupt Running");
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
  stopper();
  digitalWrite(RELAY1_JALAN,HIGH);
  digitalWrite(RELAY2_JALAN,LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Mundur(){
  stopper();
  digitalWrite(RELAY1_JALAN,LOW);
  digitalWrite(RELAY2_JALAN,HIGH);
  delay(DELAY_MOTOR);
}

void Jalan_Kanan(){
  stopper();
  digitalWrite(RELAY1_HORIZONTAL,HIGH);
  digitalWrite(RELAY2_HORIZONTAL,LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Kiri(){
  stopper();
  digitalWrite(RELAY1_HORIZONTAL,LOW);
  digitalWrite(RELAY2_HORIZONTAL,HIGH);
  delay(DELAY_MOTOR);
}

void Jalan_Maju_Kanan(){
  stopper();
  digitalWrite(RELAY1_JALAN,HIGH);
  digitalWrite(RELAY2_JALAN,LOW);
  digitalWrite(RELAY1_HORIZONTAL,HIGH);
  digitalWrite(RELAY2_HORIZONTAL,LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Maju_Kiri(){
  stopper();
  digitalWrite(RELAY1_JALAN,HIGH);
  digitalWrite(RELAY2_JALAN,LOW);
  digitalWrite(RELAY1_HORIZONTAL,LOW);
  digitalWrite(RELAY2_HORIZONTAL,HIGH);
  delay(DELAY_MOTOR);
}

void Jalan_Mundur_Kanan(){
  stopper();
  digitalWrite(RELAY1_JALAN,LOW);
  digitalWrite(RELAY2_JALAN,HIGH);
  digitalWrite(RELAY1_HORIZONTAL,HIGH);
  digitalWrite(RELAY2_HORIZONTAL,LOW);
  delay(DELAY_MOTOR);
}

void Jalan_Mundur_Kiri(){
  stopper();
  digitalWrite(RELAY1_JALAN,LOW);
  digitalWrite(RELAY2_JALAN,HIGH);
  digitalWrite(RELAY1_HORIZONTAL,LOW);
  digitalWrite(RELAY2_HORIZONTAL,HIGH);
  delay(DELAY_MOTOR);
}

void Pneumatik_Bawah(){
  digitalWrite(RELAY1_VERTIKAL,HIGH);
  digitalWrite(RELAY2_VERTIKAL,LOW);
}

void Pneumatik_Atas(){
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,HIGH);
}

void Kalibrasi_Atas(){
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,HIGH);
  delay(DELAY_CALL);
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,LOW);
}

void Kalibrasi_Bawah(){
  digitalWrite(RELAY1_VERTIKAL,HIGH);
  digitalWrite(RELAY2_VERTIKAL,LOW);
  delay(DELAY_CALL);
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,LOW);
}

void Kalibrasi_Rotor(){
  while(1){
    Rotor_ON();
    if(digitalRead(B0) == 0){
      Rotor_OFF();
      break;
    }
  }
}

void Pneumatik_Stop(){
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,LOW);
}

void Rotor_ON(){
  digitalWrite(RELAY_ROTOR,HIGH);
}

void Rotor_OFF(){
  digitalWrite(RELAY_ROTOR,LOW);
}

void Pump_ON(){
  digitalWrite(RELAY_PUMP,HIGH);
  delay(DELAY_PUMP);
}

void Pump_OFF(){
  digitalWrite(RELAY_PUMP,LOW);
  delay(DELAY_PUMP);
}

void Bor_Clockwise(){
  digitalWrite(RELAY_BORA,HIGH);
  digitalWrite(RELAY_BORB,LOW);
}

void Bor_Stop(){
  digitalWrite(RELAY_BORA,LOW);
  digitalWrite(RELAY_BORB,LOW);
}

void Bor_CounterClockwise(){
  digitalWrite(RELAY_BORA,LOW);
  digitalWrite(RELAY_BORB,HIGH);
}

void Tanam_Bibit(){
  stopper();

  // Memastikan Lubang Rotor Sesuai
  while(1){
    Rotor_ON();
    if(digitalRead(B0) == 0){
      Rotor_OFF();
      break;
    }
  }
  
  // Penumatik Turun
  Pneumatik_Bawah();

  // delay untuk turun -> 20 detik
//  delay(19000);
    delay(3000);

  // Bor Menyala
  Bor_CounterClockwise();

  // delay untuk mengebor -> 8 detik
//  delay(8000);
    delay(800);

  // Bor Berhenti
  Bor_Stop();

  // Penumatik Naik
  Pneumatik_Atas();

  // delay untuk keluar lubang -> 8 detik
//  delay(8000);
    delay(800);

  // delay pneumatik ke atas -> 20 detik
//  delay(19000);
    delay(3000);

  // Pneumatik Mati
  Pneumatik_Stop();

  // Rotor Berputar
  Rotor_ON();

  // delay Rotor
  delay(600);

  // Looping pembacaan sensor magnet
  while(digitalRead(B0) == 1){
    Rotor_ON();
    if(digitalRead(B0) == 0){
      break;
    }
  }

  Rotor_OFF();
}

void IR_Read(){
  stopper();
  ir_sensor = digitalRead(IR_SENSOR);
  Serial.print("Sensor Stopper");
  Serial.println(ir_sensor);
}
