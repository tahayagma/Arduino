#include <AFMotor.h>
#include <Servo.h>

#define led A5
#define bazer A4
#define echoK A0
#define trigK A1

#define trig A2
#define echo A3

AF_DCMotor solOn(2),solArka(1),sagOn(3),sagArka(4);
Servo servo;
long distance, duration, mesafeK, mesafe;


void setup() {
  servo.attach(10);
  servo.write(0);
  solOn.setSpeed(200);
  sagOn.setSpeed(200);
  pinMode(trigK, OUTPUT);
  pinMode(echoK, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(bazer, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  //Sensor(trig,echo);
  mesafe = distance;
  //Sensor(trigK,echoK);
  mesafeK = distance;
  digitalWrite(led, LOW);
  digitalWrite(bazer, LOW);
  if (mesafe < 20) {
    Serial.print("mesafe motor: "); Serial.print(mesafe);
    Serial.print("kapak mesafe: "); Serial.print(mesafeK);
    sagOn.run(RELEASE);
    solOn.run(RELEASE);
    delay(1000);
    sagOn.run(BACKWARD);
    solOn.run(BACKWARD);
    delay(1000);
    solOn.run(RELEASE);
    sagOn.run(RELEASE);
    delay(1000);
    sagOn.run(BACKWARD);
    solOn.run(FORWARD);
    delay(1000);
  }
  else
  { if (mesafeK < 40) {
      solOn.run(RELEASE);
      sagOn.run(RELEASE);
      digitalWrite(led, HIGH); digitalWrite(bazer, HIGH);
      delay(1000);
      servo.write(180);
      digitalWrite(led, LOW); digitalWrite(bazer, LOW);
      delay(5000);
      servo.write(0);
    }
  }
  sagOn.run(FORWARD);
  solOn.run(FORWARD);
}

void Sensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 29.1 / 2;
}
