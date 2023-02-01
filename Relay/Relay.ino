#define RELAY1_KANAN 2
#define RELAY2_KANAN 3
#define RELAY1_KIRI  4
#define RELAY2_KIRI  5
#define DELAY_MOTOR 100
void setup() {
  pinMode(RELAY1_KANAN, OUTPUT);
  pinMode(RELAY1_KIRI, OUTPUT);
  pinMode(RELAY2_KANAN, OUTPUT);
  pinMode(RELAY2_KIRI, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Jalan_Maju();
  delay(1000);
  Jalan_Mundur();
  delay(1000);
  Jalan_Kanan();
  delay(1000);
  Jalan_Kiri();
  delay(1000);
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
