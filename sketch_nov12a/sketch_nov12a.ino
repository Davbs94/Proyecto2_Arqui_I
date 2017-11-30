#include <Servo.h>  //add '<' and '>' before and after servo.h
#include <Wire.h>
#include <SPI.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP280 bme;

int servoPin = 9;
Servo servo;  
int light_value;
float light;
int cont = 0;
int maxlight = 0;
int angle = 0;
String dir[] = {"N","NE","E","SE","S","SO","O","NO"};
String cdir = "N";
int idir = 0;
 
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  dht.begin();
  bme.begin();
}
 
 
void loop()
{




if (cont == 60 || cont == 72 || cont == 84 || cont == 96 || cont == 108 || cont == 120 || cont == 132 || cont == 144){
  if (cont == 60){
    maxlight = 0;
    cdir = "N";
    idir = 0;
  }
servo.write(15);
delay(1000);
light_value = analogRead(A0);
light = light_value * 0.0976;
if (light> maxlight){
  maxlight = light;
  angle = 15;
  cdir = dir[idir];
}
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" + String(0)+"@" + String(0) + "@" + "Searching");
delay(1000);
cont = cont = cont + 2;
}


else if (cont == 62 || cont == 74 || cont == 86 || cont == 98 || cont == 110 || cont == 122 || cont == 134 || cont == 146){
servo.write(30);
delay(1000);
light_value = analogRead(A0);
light = light_value * 0.0976;
if (light> maxlight){
  maxlight = light;
  angle = 30;
  cdir = dir[idir];
}
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" + String(0)+"@" + String(0) + "@" + "Searching");
delay(1000);
cont= cont + 2;   
}


else if (cont == 64 || cont == 76 || cont == 88 || cont == 100 || cont == 112 || cont == 124 || cont == 136 || cont == 148){
servo.write(45);
delay(1000);
light_value = analogRead(A0);
light = light_value * 0.0976;
if (light> maxlight){
  maxlight = light;
  angle = 45;
  cdir = dir[idir];
}
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" + String(0)+"@" + String(0) + "@" + "Searching");
delay(1000);
cont= cont + 2;   
}


else if (cont == 66 || cont == 78 || cont == 90 || cont == 102 || cont == 114 || cont == 126 || cont == 138 || cont == 150){
servo.write(60);
delay(1000);
light_value = analogRead(A0);
light = light_value * 0.0976;
if (light> maxlight){
  maxlight = light;
  angle = 60;
  cdir = dir[idir];
}
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" + String(0)+"@" + String(0) + "@" + "Searching");
delay(1000);
cont= cont + 2;  
}


else if (cont == 68 || cont == 80 || cont == 92 || cont == 104 || cont == 116 || cont == 128 || cont == 140 || cont == 152){
servo.write(75);
delay(1000);
light_value = analogRead(A0);
light = light_value * 0.0976;
if (light> maxlight){
  maxlight = light;
  angle = 75;
  cdir = dir[idir];
}
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" + String(0)+"@" + String(0) + "@" + "Searching");
delay(1000);
cont= cont + 2;  
}


else if (cont == 70 || cont == 82 || cont == 94 || cont == 106 || cont == 118 || cont == 130 || cont == 142 || cont == 154){
servo.write(90);
delay(1000);
light_value = analogRead(A0);
light = light_value * 0.0976;
if (light> maxlight){
  maxlight = light;
  angle = 90;
  cdir = dir[idir];
}
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" +  String(0)+"@" + String(0) + "@" + "Searching");
idir++;
moveright();
delay(940);
cont= cont + 2;  
}
else if (cont == 156){
delay(1000);
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@"  + String(maxlight)+"@" + String(angle) + "@" + cdir);
moveback();
delay(520);
cont= cont + 2;  
}
else if (cont == 598){
delay(1000);
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" + String(maxlight)+"@" + String(angle) + "@" + cdir);
delay(1000);
cont= 0; 
}
else{
delay(1000);
Serial.print(String(bme.readTemperature())+ "@" + String(bme.readPressure()) + "@" +String(bme.readAltitude())+"@"+String(dht.readHumidity())+"@" + String(maxlight)+"@" + String(angle) + "@" + cdir);
delay(1000);
cont= cont + 2; 
}


 
}


void moveright(){

    digitalWrite(5, LOW); 
    digitalWrite(4, LOW);
    for (int i = 0; i<400; i++){
      digitalWrite(3, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(3, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(150);
    } 
    digitalWrite(5,HIGH); 
}

void moveback(){

    digitalWrite(5, LOW); 
    digitalWrite(4, HIGH);
    for (int i = 0; i<3200; i++){
      digitalWrite(3, LOW);  // This LOW to HIGH change is what creates the
      digitalWrite(3, HIGH); // "Rising Edge" so the easydriver knows to when to step.
      delayMicroseconds(150);
    } 
    digitalWrite(5,HIGH); 
}
