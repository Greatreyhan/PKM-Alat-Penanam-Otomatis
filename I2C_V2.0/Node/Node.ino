#include <Wire.h>
#include <I2C_Anything.h>

 volatile byte maju;
 volatile byte mundur;
 volatile byte kanan;
 volatile byte kiri;
 volatile byte turun;
 volatile byte bor;
 volatile byte rotate;
 volatile int delayTime;

void setup()
{
  Serial.begin(115200);
  Wire.begin(8); 
}

void loop()
{
  Wire.requestFrom(42, 11); // reqeust 6 bytes from salve Uno #8
  I2C_readAnything (maju);
  I2C_readAnything (mundur);
  I2C_readAnything (kanan);
  I2C_readAnything (kiri);
  I2C_readAnything (turun);
  I2C_readAnything (bor);
  I2C_readAnything (rotate);
  I2C_readAnything (delayTime);

  Serial.print("Maju = ");
  Serial.println(maju);

  Serial.print("Mundur = ");
  Serial.println(mundur);

  Serial.print("Kanan = ");
  Serial.println(kanan);

  Serial.print("Kiri = ");
  Serial.println(kiri);

  Serial.print("Turun = ");
  Serial.println(turun);

  Serial.print("Bor = ");
  Serial.println(bor);

  Serial.print("Rotate = ");
  Serial.println(rotate);

  Serial.print("Delay Time = ");
  Serial.println(delayTime);
  delay(5000);
}
