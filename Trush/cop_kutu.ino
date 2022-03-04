#include <Servo.h>
#include <AFMotor.h>
/*Developed by Taha*/

Servo sg90;
/*servo sarı pin girişi turuncu güç hattı ve kahverengi toprak hattına bağlanır*/
int pos= 0;

AF_DCMotor sagOn(1),solOn()  // motor tanımlamaları yapıldı


int red_led = 5;
int bazer = 4;
int green_led = 10;
/*________________sürüş için hcr04_____________*/
int trigPin = 2;
int echoPin =7;
/*_______________________________________________*/

/*_______________kapak için hcr04__________________*/
int trigpinK = 11;
int echopinK = 12;
/*_________________________________________________*/

long zaman,zaman2;/* zamanı tutmak için bir degişken tanımladık*/
long mesafe,mesafe2;

void setup(){
  motor.setSpeed(255) // motora hız vermiş olduk.
  sg90.attach(9);
  pinMode(4,OUTPUT); /* bazer tanımlandı ve pin mode outpu olacağı temsil edildi.*/
  /*bazerin uzun bacak güç hattına kısa bacak pin girişlerine bağlandı*/
  pinMode(5,OUTPUT);/*kırmızı led tanımlandı*/
  /*ledlerin uzun bacak güç hattına kısa bacak ise pin girişlerini takılır*/
  pinMode(10,OUTPUT); /* led tanımlandı ve 10 pin outpu oldu.*/
  pinMode(trigPin, OUTPUT); /* trgipin elektrik sinyalini gönderdi output olarak*/
  pinMode(echoPin,INPUT);
  pinMode(trigpinK,OUTPUT);
  pinMode(echopinK,INPUT);
  Serial.begin(9600);
  }

void loop(){
  sagOn.run(FORWARD); // motorlara güç verildi.
  solOn.run(FORWARD);
  digitalWrite(trigPin,LOW);/*önce sıfırladık sinyal göndermesine izin verilmez*/
  digitalWrite(trigpinK,LOW);
  delayMicroseconds(5); /*5 mikro saniye bekledik*/
  digitalWrite(trigPin,HIGH);/* beklemeden sonra ses dalgası göndermesi için  trig pine güç verdik*/
  digitalWrite(trigpinK,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  digitalWrite(trigpinK,LOW);
  zaman = pulseIn(echoPin,HIGH);
  mesafe = zaman/29.1/2;
  zaman2 = pulseIn(echopinK,HIGH);
  mesafe2 = zaman2/29.1/2;
  digitalWrite(green_led,HIGH);
  // dc motorlar sürekli çalışır

  
  if(mesafe<40){ // eğer mesafe 40 mm den az olursa dc motorlar sönül yapacak
      }
    /*dc motorlar dönüş yapacak*/
  else
    if(mesafe2<10){
      digitalWrite(green_led,LOW);
      digitalWrite(red_led,HIGH);
      delay(100);
      for(pos = 0;pos<=180;pos+=5){
        sg90.write(pos);
        delay(15);
      }
     digitalWrite(red_led,LOW);
     digitalWrite(green_led,HIGH);
     
      /*dc motorlar duracak
      yeşil sönüp kırmızı yanacak
      2 saniye bekle
      servo ile kapak açılacak
      15 saniye bekle
      kapak kapat
      kırmızı sönüp yeşil yanacak
      dc motorlara güç ver*/
    /*dc motorlar tam yol devam*/
      }
}
