#define detect 13
#define lamp A0

void setup() {
  // put your setup code here, to run once:
  pinMode(detect, INPUT);
  pinMode(lamp, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(detect));
  if(digitalRead(detect) == 0){
      digitalWrite(lamp,HIGH);
  }
  else{
    digitalWrite(lamp,LOW);
  }
  delay(100);
}
