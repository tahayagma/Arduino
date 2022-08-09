#include <AFMotor.h>
#include <Servo.h>

//#define trigK A1
//#define echoK A0
#define trig A2
#define echo A3

AF_DCMotor solOn(1),solArka(2),sagOn(3),sagArka(4); // motorları hangi bölümde tanımladığımızı bildirdik
//Servo servo;

int mesafe,zaman;//,mesafeK,zamanK;


void setup() {

  solOn.setSpeed(200); 
  solArka.setSpeed(200);
  sagOn.setSpeed(200);
  sagArka.setSpeed(200);
  
  //servo.attach(10);
  //servo.write(0);

  //pinMode(trigK,OUTPUT);
  //pinMode(echoK,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(trig,LOW);//digitalWrite(trigK,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);//digitalWrite(trigK,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);//digitalWrite(trigK,LOW);
  zaman = pulseIn(echo,HIGH);
  //zamanK = pulseIn(echoK,HIGH);
  //mesafeK =  zamanK/58.2;
  mesafe = zaman/58.2;
  // eger mesafe 20 den küçükse sürüş motorlar geriye gelecek ve duracaklar
  // sonra 2 saniye bekleyip sag ön teker hareket edip yön değiştirmiş olacak
  if(mesafe<20){
    Serial.print("mesafe motor: ");Serial.print(mesafe);
    sagArka.run(RELEASE);
    sagOn.run(RELEASE);
    solOn.run(RELEASE);
    solArka.run(RELEASE);
    delay(2000);
    
    // sağa dönmek için sağdaki ön ve arka tekerleri geriye sürdük soldaki tekerlekleri ise ileri sürdük
    sagOn.run(BACKWARD);
    sagArka.run(BACKWARD);
    solOn.run(FORWARD);
    solArka.run(FORWARD);
  }
  // eger 20 den küçük değilse kapak mesafe kontrol edilecek. eger 30 den küçükse tüm motorlar duracak ve 3 saniye bekleyecek
   // bazer ve led yanacak ardından servo 180 derece açılacak ve 10 saniye bekleyecek ve kapak kapanacak
 else{
  /*if(mesafeK<30){
    Serial.print("mesafe Kapak:");Serial.print(mesafeK);
    sagArka.run(RELEASE);
    sagOn.run(RELEASE);
    solOn.run(RELEASE);
    solArka.run(RELEASE);
    delay(3000);
    servo.write(180);
    delay(3000); // 10 saniye bekle
    }
  servo.write(0);*/
  solOn.run(FORWARD);
  solArka.run(FORWARD);
  sagArka.run(FORWARD);
  sagOn.run(FORWARD);
 }
}
