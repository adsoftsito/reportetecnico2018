
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//--------Sensor de humedad y temperatura (DTH22)
#include <DHT.h>
#define HT1 12
#define HT2 14
#define DHTTYPE DHT22
DHT dht1 (HT1, DHTTYPE,11);
DHT dht2 (HT2, DHTTYPE,11); 
//--------Sensor de iluminaciòn (TSL2561)
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>  
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
//--------Sensor de presion admosferica (BMP180)
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
//--------Sensor de temperatura (DS18B20)
#include <OneWire.h>                
#include <DallasTemperature.h>
OneWire ourWire(2);                
DallasTemperature sensors(&ourWire);

//--------Sensor de nivel (HC-SR04)
const int triger = 10;  
const int echo = 16;
//-------------Control ON/OFF----------------------
const int Rele= 13; 
int ESR=0;
//------------Selector del display ----------
const int Pot= A0;
//----------Variables internas--------------
float t1,t2,Tp,h1,h2,Hp,Selec;
int d;
long esp;
void setup() 
{
  
  Serial.begin(9600);
  delay(10);
  dht1.begin();
  dht2.begin();
  bmp.begin();
  sensors.begin();
  lcd.begin();                      
  lcd.backlight();
}

void loop()

{
 Desplegado_local();
  Serial.println(analogRead (A0)); 
  Serial.println(Selec); 
}


void Desplegado_local()
{ 
                   float t1 = dht1.readTemperature();float t2 = dht2.readTemperature();float Tp=((t1+t2)*.5);
                   float h1 = dht1.readHumidity();float h2 = dht2.readHumidity();float Hp=((h1+h2)*0.5);
                   sensors.requestTemperatures();   
                   float Tl= sensors.getTempCByIndex(0);
                   sensors_event_t event;tsl.getEvent(&event);
                   digitalWrite(triger, LOW);delayMicroseconds(20);digitalWrite(triger, HIGH);delayMicroseconds(20);digitalWrite(triger, LOW);esp = (pulseIn(echo, HIGH)/2); d = int(esp * 0.0343);
                   int Pot = analogRead (A0); 
Selec=map(Pot,3,930,1,6);
  if (Selec == 1) 
     {
  lcd.clear();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("-----KUBEET-----");
      lcd.setCursor(0,1);
      lcd.print("MODULO--AMBIENTE");
     }
  else if (Selec == 2) 
     {
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("HUMEDAD R=");
      lcd.setCursor(10,0);
      lcd.print(Hp);
      lcd.setCursor(15,0);
      lcd.print("%");
      lcd.setCursor(0,1);
      lcd.print("TEMPE AM=");
      lcd.setCursor(9,1);
      lcd.print(Tp);
      lcd.setCursor(14,1);
      lcd.print("*C");
     }
  else if (Selec == 3) 
     {
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TEMPE LI=");
      lcd.setCursor(10,0);
      lcd.print(Tl);
      lcd.setCursor(14,0);
      lcd.print("*C");
      lcd.setCursor(0,1);
      lcd.print("CLARIDAD=");
      lcd.setCursor(9,1);
      lcd.print((event.light));
      lcd.setCursor(14,1);
      lcd.print("LM");
     }
  else if (Selec == 4) 
     {
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ALTITUD=");
      lcd.setCursor(8,0);
      lcd.print((bmp.readAltitude(100305)));
      lcd.setCursor(15,0);
      lcd.print("M");
      lcd.setCursor(0,1);
      lcd.print("PRESION=");
      lcd.setCursor(8,1);
      lcd.print((bmp.readSealevelPressure()/10));
      lcd.setCursor(13,1);
      lcd.print("hPa");
     }
  else if (Selec == 5) 
     {
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("---NIVEL=");
      lcd.setCursor(9,0);
      lcd.print(d);
      lcd.setCursor(12,0);
      lcd.print("CM---");
      lcd.setCursor(0,1);
      lcd.print("---CONTROL =");
      lcd.setCursor(12,1);
      lcd.print(ESR);
      lcd.setCursor(13,1);
      lcd.print("---");
     } 
  else if (Selec == 6) 
     {
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TEMPE IN=");
      lcd.setCursor(10,0);
      lcd.print((bmp.readTemperature()));
      lcd.setCursor(14,0);
      lcd.print("*C");
      lcd.setCursor(0,1);
      lcd.print("IP =");
      lcd.setCursor(4,1);
     // lcd.print(WiFi.localIP());
     }  
     else 
      {
      lcd.clear();
      } 
}
