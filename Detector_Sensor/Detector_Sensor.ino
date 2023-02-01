#define echoPinA 2 
#define trigPinA 3 
#define echoPinB 4 
#define trigPinB 5 
#define echoPinC 7 
#define trigPinC 6 
#define data1  8
#define data2  9
#define led1  10
#define led2  11
#define led3  12
#define detect 13
#define lamp A0

// Modul Detektor 3 Sensor 2 Bit Output

// defines variables
long durationA, durationB, durationC; 
int distanceA, distanceB, distanceC; 

void setup() {
  pinMode(trigPinA, OUTPUT);
  pinMode(trigPinB, OUTPUT);
  pinMode(trigPinC, OUTPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(data2, OUTPUT);
  pinMode(data1, OUTPUT);
  pinMode(echoPinA, INPUT);
  pinMode(echoPinB, INPUT);
  pinMode(echoPinC, INPUT); 
  pinMode(detect, INPUT);
  pinMode(lamp, OUTPUT);
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
}
void loop() {
  digitalWrite(trigPinA, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinA, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinA, LOW);
  durationA = pulseIn(echoPinA, HIGH);

  digitalWrite(trigPinB, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinB, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinB, LOW);
  durationB = pulseIn(echoPinB, HIGH);

  digitalWrite(trigPinC, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinC, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinC, LOW);
  durationC = pulseIn(echoPinC, HIGH);
  
  distanceA = durationA * 0.034 / 2; 
  distanceB = durationB * 0.034 / 2; 
  distanceC = durationC * 0.034 / 2; 

  if((distanceA > 30) && (distanceB > 30) && (distanceC > 30)){
    digitalWrite(data1, LOW);
    digitalWrite(data2, LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    }
  if(distanceA < 40){
    digitalWrite(data1, LOW);
    digitalWrite(data2, HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  if(distanceB < 40){
    digitalWrite(data1, HIGH);
    digitalWrite(data2, LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
  }
  if(distanceC < 40){
    digitalWrite(data1, HIGH);
    digitalWrite(data2, HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }
  Serial.print("Distance: ");
  Serial.print(distanceA);
  Serial.print(" ");
  Serial.print(distanceB);
  Serial.print(" ");
  Serial.print(distanceC);
  Serial.println(" ");

  if(digitalRead(detect) == 0){
      digitalWrite(lamp,HIGH);
  }
  else{
    digitalWrite(lamp,LOW);
  }
}
