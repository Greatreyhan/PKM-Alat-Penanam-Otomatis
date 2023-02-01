#include <L298N.h>
#define ENA 1
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENB 1

L298N driver(ENA,IN1,IN2,IN3,IN4,ENB);

uint32_t waktuTunda = 1000;
uint32_t kecepatan = 150;

void setup() {

  // Motor Maju
  driver.forward(kecepatan,waktuTunda);
  driver.full_stop(waktuTunda);

  // Motor Ke Kanan
  driver.turn_right(kecepatan,waktuTunda);
  driver.full_stop(waktuTunda);

  // Motor Ke Kiri
  driver.turn_left(kecepatan, waktuTunda);
  driver.full_stop(waktuTunda);

  // Motor Mundur
  driver.backward(kecepatan, waktuTunda);
  driver.full_stop(waktuTunda);
}

void loop() {
  // put your main code here, to run repeatedly:

}
