

/* www.nyebarilmu.com */

//mendefinisikan pin yang digunakan untuk control pin
int IN_1 = 4;
int IN_2 = 5;
int IN_3 = 6;
int IN_4 = 7;
 
void setup()
{
  //mendefinisikan control pin sebagai output
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT);
}
 
void loop()
{
 //Putar Mesin searah jarum jam
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, LOW);
 delay(1500);
 //Untuk mesin A
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, HIGH);
 delay(1000);
 //Putar Motor B searah jarum jam
 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, LOW);
 delay(1500);
 //Untuk mesin B
 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, HIGH);
 delay(1000);

 //Putar Motor a berlawan arah jarum jam
 digitalWrite(IN_1, LOW);
 digitalWrite(IN_2, HIGH);
 delay(1500);
 //Untuk mesin A
 digitalWrite(IN_1, HIGH);
 digitalWrite(IN_2, HIGH);
 delay(1000);
 //Putar Motor B berlawan arah jarum jam
 digitalWrite(IN_3, LOW);
 digitalWrite(IN_4, HIGH);
 delay(1500);
 //Untuk mesin B
 digitalWrite(IN_3, HIGH);
 digitalWrite(IN_4, HIGH);
 delay(1000);
}
