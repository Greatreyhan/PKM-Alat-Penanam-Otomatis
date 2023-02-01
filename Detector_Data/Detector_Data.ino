#define D1 2
#define D2 3
#define D3 4
#define D4 5
#define DP 6

void setup() {
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(DP, INPUT);
  Serial.begin(9600);
}

void loop() {
    if(digitalRead(DP) == 1){
      Serial.print(digitalRead(D1));
      Serial.print(digitalRead(D2));
      Serial.print(digitalRead(D3));
      Serial.println(digitalRead(D4));
    }
}
