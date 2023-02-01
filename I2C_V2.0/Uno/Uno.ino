#include <Wire.h>
#include <I2C_Anything.h>

struct
{
 byte maju;
 byte mundur;
 byte kanan;
 byte kiri;
 byte turun;
 byte bor;
 byte rotate;
 int delayTime;
} response;



void setup()
{
  Serial.begin (115200);
  Wire.begin(D1, D2);                
  Wire.onRequest(requestEvent); 

}

void loop()
{

  Serial.println();

  response.maju = 0x01;
  Serial.print("Maju = ");
  Serial.print(response.maju, 2);

  response.mundur = 1;
  Serial.print("Mundur = ");
  Serial.println(response.mundur, 2);

  response.kanan = 1;
  Serial.print("Kanan = ");
  Serial.println(response.kanan, 2);

  response.kiri = 1;
  Serial.print("Kiri = ");
  Serial.println(response.kiri, 2);

  response.turun = 1;
  Serial.print("Turun = ");
  Serial.println(response.turun, 2);

  response.bor = 1;
  Serial.print("Bor = ");
  Serial.println(response.bor, 2);

  response.rotate = 1;
  Serial.print("Rotate = ");
  Serial.println(response.rotate, 2);

  response.delayTime = 100;
  Serial.print("Delay Time = ");
  Serial.println(response.delayTime, 2);

  delay(1000);
}

void requestEvent ()
{
  I2C_writeAnything(response);
} 
