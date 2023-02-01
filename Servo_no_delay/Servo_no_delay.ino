#include <Servo.h>
 
Servo myservo;  // create servo object to control a servo, max = 8 servos
int myservo_pin = 9; // pin that controls the servo
int myservo_speed = 5; // how fast the servo moves, 1 = very fast, 10 = very slow
long myservo_movetime = 0; // next time in millis servo next moves
int myservo_gPos = 0; // target position to move towards
int myservo_cPos = 0; // current postion of servo
 
int pos = 0;    // variable to store the servo position
int cPos;       // current position
int gPos;       // goal position
int tDelay = 5; // delay between moves, gives appearance of smooth motion
 
void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  Serial.println("setup complete : smooth servo movment without delay v1");
} 
 
void loop() {
  cPos = myservo.read();
  if (cPos == 0) gPos = 180;
  if (cPos == 180) gPos = 0;
  if (cPos != gPos && millis() >= myservo_movetime) {
    moveServo();
  }
  if (Serial.available() > 0) { GetCommand(); }
} 

void moveServo() {
  if (cPos < gPos) myservo.write(cPos+1);
  if (cPos > gPos) myservo.write(cPos-1);
  //if (cPos == gPos) // nothing
  myservo_movetime = millis() + tDelay;
}

void GetCommand() {
  int command = Serial.read() - '0';
  int mVal = command;
  if (mVal == 'x') {
    tDelay = tDelay * 10;
  } else {
    tDelay = mVal;
  }
  Serial.print("Pauses changed to : "); Serial.print(tDelay); Serial.println(" mSeconds");
  Serial.flush();
}
