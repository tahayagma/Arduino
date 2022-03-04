
#define echo A3
#define trig A2
#define led A0
int zaman, mesafe;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  zaman = pulseIn(echo, HIGH);
  mesafe = zaman / 58.2;
  if (mesafe < 50) {
    Serial.print(mesafe);
  }

}
