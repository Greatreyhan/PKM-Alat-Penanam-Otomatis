// Self defined Pin
#define SensorProximity    8
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
#define DELAY_ROTOR        1000
#define DELAY_PUMP         2000
#define MY_ADDRESS         8

#define D1 2
#define D2 3
#define D3 4
#define D4 5
#define DP 6

#define C0 7 // Data HC-SR04
#define C1 8

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

    // Bagian Sensor Magnet
    pinMode(B0, INPUT);
    
    Disable_Relay();
}


void loop() {
//    Jalan_Maju();    
//    delay(1000);
//    Jalan_Mundur();
//    delay(1000);
//    Jalan_Kanan();
//    delay(1000);
//    Jalan_Kiri();
//    delay(1000);
//    Jalan_Maju_Kanan();
//    delay(1000);
//    Jalan_Maju_Kiri();
//    delay(1000);
//    Jalan_Mundur_Kanan();
//    delay(1000);
//    Jalan_Mundur_Kiri();
//    delay(1000);
//    Pneumatik_Atas();
//    delay(1000);
//    Pneumatik_Bawah();
//    delay(1000);
//    Rotor_ON();
//    delay(1000);
//    Rotor_OFF();
//    delay(1000);
//  Bor_Clockwise();
//  Pump_ON();

//    digitalWrite(RELAY1_VERTIKAL, HIGH);
//    delay(1000);
//    digitalWrite(RELAY1_VERTIKAL, LOW);
//    delay(1000);
//    digitalWrite(RELAY2_VERTIKAL, HIGH);
//    delay(1000);
//    digitalWrite(RELAY2_VERTIKAL, LOW);
//    delay(1000);
//    digitalWrite(RELAY1_HORIZONTAL, HIGH);
//    delay(1000);
//    digitalWrite(RELAY1_HORIZONTAL, LOW);
//    delay(1000);
//    digitalWrite(RELAY2_HORIZONTAL, HIGH);
//    delay(1000);
//    digitalWrite(RELAY2_HORIZONTAL, LOW);
//    delay(1000);
//    digitalWrite(RELAY1_JALAN, HIGH);
//    delay(1000);
//    digitalWrite(RELAY1_JALAN, LOW);
//    delay(1000);
//    digitalWrite(RELAY2_JALAN, HIGH);
//    delay(1000);
//    digitalWrite(RELAY2_JALAN, LOW);
//    delay(1000);
//    digitalWrite(RELAY_ROTOR, HIGH);
//    delay(1000);
//    digitalWrite(RELAY_ROTOR, LOW);
//    delay(1000);
//    digitalWrite(RELAY_PUMP, HIGH);
//    delay(1000);
//    digitalWrite(RELAY_PUMP, LOW);
//    delay(1000);
//    digitalWrite(RELAY_BORA, HIGH);
//    delay(1000);
//    digitalWrite(RELAY_BORA, LOW);
//    delay(1000);
//    digitalWrite(RELAY_BORB, HIGH);
//    delay(1000);
//    digitalWrite(RELAY_BORB, LOW);
//    delay(1000);

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
  delay(20000);

  // Bor Menyala
  Bor_CounterClockwise();

  // delay untuk mengebor -> 8 detik
  delay(8000);

  // Bor Dibalik
  Bor_Clockwise();

  // Penumatik Naik
  Pneumatik_Atas();

  // delay untuk keluar lubang -> 8 detik
  delay(8000);

  // Bor Berhenti
  Bor_Stop();

  // delay pneumatik ke atas -> 20 detik
  delay(20000);

  // Pneumatik Mati
  Pneumatik_Stop();

  // Rotor Berputar
  Rotor_ON();

  // delay Rotor
  delay(100);

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
