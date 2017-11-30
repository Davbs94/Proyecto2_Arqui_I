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


// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP280 bme; // I2C
//Adafruit_BMP280 bme(BMP_CS); // hardware SPI
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);

  dht.begin();
  bme.begin();  

}

void loop() {


    // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)

  // Comprobamos si ha habido algún error en la lectura
 
   
  


  Serial.print("Temperature: "+ String(bme.readTemperature())+ " *C@"
  +"Pressure: "+ String(bme.readPressure()) + " Pa@"+ "Approx altitude: "+String(bme.readAltitude())+" m@"
  +"Humity: "+String(dht.readHumidity())+" %@");
  delay(2000);
}

