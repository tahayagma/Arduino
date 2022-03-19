#include <Servo.h>
#define trig 8
#define echo 9
#define bazer 5
#define led 4

long distance,duration,mesafe;
Servo s1;
void setup() {
  s1.attach(3);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(bazer,OUTPUT);
}

void loop() {
  digitalWrite(bazer,LOW);
  digitalWrite(led,LOW);
  Sensor(trig,echo);
  mesafe =  distance;
  if (mesafe<60){
    digitalWrite(bazer,HIGH);
    digitalWrite(led,HIGH);
    delay(500);digitalWrite(bazer,LOW);
    s1.write(180);
    }
    delay(2000);
   s1.write(0);
 }

void Sensor(int trigPin,int echoPin){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance= duration/29.1/2;
}
