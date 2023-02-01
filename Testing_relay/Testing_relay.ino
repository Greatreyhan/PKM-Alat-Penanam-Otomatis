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
#define IR_SENSOR          9
#define DELAY_MOTOR        100
#define DELAY_ROTOR        1000
#define DELAY_PUMP         2000
#define MY_ADDRESS         8

#define KANAN   1
#define TENGAH  2
#define KIRI    3

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
    Disable_Relay();
    Serial.begin(9600);         
}

// error relay jalan -> hardware
// error relay horizontal -> hardware/software
//

void loop() {

    digitalWrite(RELAY1_VERTIKAL, HIGH);
    digitalWrite(RELAY2_VERTIKAL, HIGH);
    digitalWrite(RELAY1_HORIZONTAL, HIGH);
    digitalWrite(RELAY2_HORIZONTAL, HIGH);
    digitalWrite(RELAY1_JALAN, HIGH);
    digitalWrite(RELAY2_JALAN, HIGH);
    digitalWrite(RELAY_ROTOR, HIGH);
    digitalWrite(RELAY_PUMP, HIGH);
    digitalWrite(RELAY_BORA, HIGH);
    digitalWrite(RELAY_BORB, HIGH);
    delay(1000);
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
    delay(1000);
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

void Jalan_Bawah(){
  digitalWrite(RELAY1_VERTIKAL,HIGH);
  digitalWrite(RELAY2_VERTIKAL,LOW);
  Bor_CounterClockwise();
  delay(DELAY_MOTOR);
}

void Jalan_Atas(){
  digitalWrite(RELAY1_VERTIKAL,LOW);
  digitalWrite(RELAY2_VERTIKAL,HIGH);
  Bor_Clockwise();
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

void Bor_Clockwise(){
  digitalWrite(RELAY_BORA,HIGH);
  digitalWrite(RELAY_BORB,LOW);
}

void Bor_CounterClockwise(){
  digitalWrite(RELAY_BORA,LOW);
  digitalWrite(RELAY_BORB,HIGH);
}

void IR_Read(){
  ir_sensor = digitalRead(IR_SENSOR);
  Serial.print("Sensor Stopper");
  Serial.println(ir_sensor);
}
