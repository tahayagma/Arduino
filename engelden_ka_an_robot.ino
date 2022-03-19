#include <AFMotor.h>
#define trig A2
#define echo A3

#define red A0
#define yesil A1 

AF_DCMotor solArka(2),sagArka(3);+-
long distance,duration,mesafe;

void setup() {
  solArka.setSpeed(200);
  sagArka.setSpeed(200);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yesil,OUTPUT);
}

void loop() {
  digitalWrite(red,LOW);
  digitalWrite(yesil,HIGH);
  Sensor(trig,echo);
  mesafe =  distance;
  if (mesafe<10){
    digitalWrite(red,HIGH);
    digitalWrite(yesil,LOW);
    sagArka.run(RELEASE);
    solArka.run(RELEASE);
    delay(500);
    sagArka.run(BACKWARD);
    solArka.run(BACKWARD);
    delay(500);
    solArka.run(RELEASE);
    sagArka.run(RELEASE);
    delay(500);
    sagArka.run(BACKWARD);
    solArka.run(FORWARD);
    delay(500);
    }
  else{
    sagArka.run(FORWARD);
    solArka.run(FORWARD);
    }
}

void Sensor(int trigPin,int echoPin){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(7);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance= duration/29.1/2;
}
