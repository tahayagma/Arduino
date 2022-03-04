#include <Servo.h>

Servo sg90;
/*servo sarı pin girişi kahvrengi güç hattı ve turuncu toprak hattına bağlanır*/
int pos= 0;


int trigPin = 2;
int echoPin =7;

long zaman;/* zamanı tutmak için bir degişken tanımladık*/
long mesafe;

void setup(){
  sg90.attach(9);
  pinMode(4,OUTPUT); /* bazer tanımlandı ve pin mode outpu olacağı temsil edildi.*/
  /*bazerin kısa bacak güç hattına uzun bacak pin girişlerine bağlandı*/
  pinMode(5,OUTPUT);/*kırmızı led tanımlandı*/
  /*ledlerin kısa bacak güç hattına uzun bacak ise pin girişlerini takılır*/
  pinMode(10,OUTPUT); /* led tanımlandı ve 10 pin outpu oldu.*/
  pinMode(trigPin, OUTPUT); /* trgipin elektrik sinyalini gönderdi output olarak*/
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  }

void loop(){

  digitalWrite(trigPin,LOW);/*önce sıfırladık sinyal göndermesine izin verilmez*/
  delayMicroseconds(5); /*5 mikro saniye bekledik*/
  digitalWrite(trigPin,HIGH);/* beklemeden sonra ses dalgası göndermesi için  trig pine güç verdik*/
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  zaman = pulseIn(echoPin,HIGH);
  mesafe = zaman/29.1/2;
  if(mesafe<10){
    for(pos = 0;pos<=180;pos +=5){
      digitalWrite(5,LOW); /*kırmız led sönecek*/
      digitalWrite(10,HIGH);/*yesil led yanacak*/
      digitalWrite(4,HIGH);/*bazere güç verdik*/
      sg90.write(pos); /* servo posizyonu değişti*/
      delay(15);
      }
    digitalWrite(10,LOW);/*yesil sönecek*/
    digitalWrite(4,LOW);/*bazer güç bağlantısı kesildi*/
    digitalWrite(5,HIGH);/*kırmızı yanacak*/
    Serial.print("uzaklik:");
    Serial.print(mesafe);
    delay(100);
    
  }
}
