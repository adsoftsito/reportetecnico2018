

#include <DHT.h>
#define HT1 12
#define HT2 14
#define DHTTYPE DHT22
DHT dht1 (HT1, DHTTYPE,11);
DHT dht2 (HT2, DHTTYPE,11); 
float t1,t2,Tp,h1,h2,Hp,Tl;

#include <OneWire.h>                
#include <DallasTemperature.h>
OneWire ourWire(2);                
DallasTemperature sensors(&ourWire);


const int triger1 = 10;
const int echo1   = 16;

int d1;
long esp1;
void setup() 
{
  Serial.begin(9600); //Se inicia la comunicación serial 
  dht1.begin();
  dht2.begin();
  sensors.begin(); 
  pinMode(triger1, OUTPUT); 
  pinMode(echo1,    INPUT);
}
void loop() {
 float t1 = dht1.readTemperature();float t2 = dht2.readTemperature();float Tp=((t1+t2)*0.5);
 float h1 = dht1.readHumidity();   float h2 = dht2.readHumidity();   float Hp= ((h1+h2)*0.5);
 sensors.requestTemperatures();   
 float Tl= sensors.getTempCByIndex(0);
 delay (2000);
 digitalWrite(triger1, LOW);delayMicroseconds(20);digitalWrite(triger1, HIGH);delayMicroseconds(20);digitalWrite(triger1, LOW);esp1 = (pulseIn(echo1, HIGH)/2); d1 = int(esp1 * 0.0343);
 
  Serial.println("Humedad: "); 
  Serial.println(Hp);
  Serial.println("Temperatura: ");
  Serial.println(Tp);
  Serial.println("Nivel: ");
  Serial.println(d1);

  Serial.println("Temperatura LIQUIDO= ");
  Serial.println(Tl);

  
  delay(1000); 
  
}
