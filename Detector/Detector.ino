#define bit1  7
#define bit2  8
void setup() {
  // put your setup code here, to run once:
  pinMode(bit1,INPUT);
  pinMode(bit2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(bit1));
  Serial.println(digitalRead(bit2));
}
