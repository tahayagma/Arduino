#include <Servo.h>
#include <AFMotor.h>
/*Developed by Taha*/

Servo sg90;
/*servo sarı pin girişi turuncu güç hattı ve kahverengi toprak hattına bağlanır*/
int pos= 0;

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

long zaman;/* zamanı tutmak için bir degişken tanımladık*/
long mesafe;

void setup(){
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

  digitalWrite(trigPin,LOW);/*önce sıfırladık sinyal göndermesine izin verilmez*/
  digitalWrite(trigpinK,LOW);
  delayMicroseconds(5); /*5 mikro saniye bekledik*/
  digitalWrite(trigPin,HIGH);/* beklemeden sonra ses dalgası göndermesi için  trig pine güç verdik*/
  digitalWrite(trigpinK,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  digitalWrite(trigpinK,LOW);
  zaman = pulseIn(echoPin,HIGH);
  zaman2 = pulseIn(echopinK,HIGH);
  mesafe = zaman/29.1/2;
  mesafe2 = zaman2/29.1/2;
  
  /*___________________sürüş için loop_____________
  yeşik led sürekli aktfi ve mesafe 50 altına düştüğü zaman sağa dönüş yapacak değilse devam edecek
  */
  if(mesafe<40){
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
    /*______________________kapak için led*/
    if(mesafe2<10)
  }
}
