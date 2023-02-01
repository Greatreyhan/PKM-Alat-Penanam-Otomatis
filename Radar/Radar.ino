#include <Servo.h>

int trigPin = 11;    
int echoPin = 12;    
long duration, cm, inches;
 
Servo myservo; 
 
int pos = 0; 
 
void setup()
{
  Serial.begin (9600);
  myservo.attach(5); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop()
{
  for(pos = 0; pos <= 180; pos += 5) 
  { 
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration/2) / 29.1; 
    Serial.print(cm);
    Serial.print("cm");
    
    myservo.write(pos); 
    delay(15); 
  }
  for(pos = 180; pos>=0; pos-=5) 
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration/2) / 29.1; 
    Serial.print(cm);
    Serial.print("cm");
    
    myservo.write(pos); 
    delay(15); 
  }
}
