/*
2 Sensores DTH22  12 y 14
1 Sensor DS18B20  2
1 rele            13
1 sensor de nivel 10 Y 16
1 Sensor TSL2561  5-4
1 Sensor BMP180   5-4
1 Rele1=          13 
*/

#include <ESP8266WiFi.h>
 #include <Wire.h> 
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
// ------------Datos de la red para entrar como cliente----------
const char* ssid = "RED NODE";
const char* password = "RED12345";

IPAddress ip(192,168,0,14);   
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0); 
WiFiServer server(80);


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
  
 //------Estatus de conecxiòn------ 
  Serial.println();
  Serial.print("Conectando a la red WIFI ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  WiFi.config(ip, gateway, subnet);
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  server.begin();
  Serial.println("Servidor web ejecutándose, Esperando IP...");
  delay(10000);
  Serial.println(WiFi.localIP());
 //-------Declaraciòn de pines digitales-------
  pinMode(Rele, OUTPUT); 
  digitalWrite(Rele, LOW);
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  }
void loop() 
{
{
  Desplegado_local();
}

{
     WiFiClient client = server.available();
     if (client) 
      {
       Serial.println("New client");boolean blank_line = true;String currentLine = "";
       while (client.connected())
          {
           if (client.available()) {
           char c = client.read();
           Serial.write(c);                      
             if (c == '\n') 
              {                       
              if (currentLine.length() == 0) 
               {  
                 client.println();
                 break;         
               }  
                 else 
                 { currentLine = ""; 
                 }                      
              }     
                 else if (c != '\r') 
                 {  currentLine += c;
                 } 
///////////////////////////////////////////////////////////////////////////  MEDICION DE VARIABLES  ////////////////////////////////////////////////////////////////////////////////////////////////                                               
                                                         //#IP=192.168.5.12/Ta=27.05*C/Hr=39.20%/Tl=27.37*C/I=6.00lx/Tin=27.70*C/Al=1097.85m/Pr=8791hPa/Re=0/#
    if (currentLine.endsWith("GET /MA-Valores")) {
                   float t1 = dht1.readTemperature();float t2 = dht2.readTemperature();float Tp=((t1+t2)*.5);
                   float h1 = dht1.readHumidity();float h2 = dht2.readHumidity();float Hp=((h1+h2)*0.5);
                   sensors.requestTemperatures();   
                   float Tl= sensors.getTempCByIndex(0);
                   sensors_event_t event;tsl.getEvent(&event); 
              
                                                client.print("#IP=");    client.print(WiFi.localIP());   client.print("/");
                                                client.print("Ta=");client.print(Tp);           client.print("*C");client.print("/");
                                                client.print("Hr=");client.print(Hp);            client.print("%");client.print("/");
                                                client.print("Tl=");client.print(Tl);           client.print("*C");client.print("/");
                                                client.print("I=");client.print((event.light));client.print("lx");client.print("/");
                                                client.print("Tin=");client.print((bmp.readTemperature()));          client.print("*C");client.print("/");
                                                client.print("Al=");client.print((bmp.readAltitude(100305)));        client.print("m");client.print("/");
                                                client.print("Pr=");client.print( (bmp.readSealevelPressure()/10));client.print("hPa");client.print("/");
                                                client.print("Re=");client.print(ESR);client.println("/#");
                                                 }

//////////////////////////////////////////////////////////////////////////////  Monitoreo nivel  ////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                         //#IP=192.168.5.12/N=57cm/#

    if (currentLine.endsWith("GET /MA-Nivel")) {
                                               delay (2000);
                                               digitalWrite(triger, LOW);delayMicroseconds(20);digitalWrite(triger, HIGH);delayMicroseconds(20);digitalWrite(triger, LOW);esp = (pulseIn(echo, HIGH)/2); d = int(esp * 0.0343);
                                           
                                               client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("N=");client.print(d); client.print("cm");
                                               client.println("/#");
                                               }   
                                               
//////////////////////////////////////////////////////////////////////////////  CONTROL ON  ////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                        //#IP=192.168.5.12/R1=1/#
    if (currentLine.endsWith("GET /MA-R1-ON")) {
       ESR=1; 
                                               digitalWrite(13, HIGH);client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print("1");
                                               client.println("/#");
                                               }   
////////////////////////////////////////////////////////////////////////////// CONTROL OFF ////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                        //#IP=192.168.5.12/R1=0/#
    if (currentLine.endsWith("GET /MA-R1-OFF")) {
       ESR=0;
                                                digitalWrite(13, LOW);client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print("0");
                                                client.println("/#");
                                                }                                      
      }
      }
////////  Se cierra la conexion:  //////////////////////////////////////////////////
        client.stop();
        Serial.println("cliente desconectado");
        }
        }
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
                   
  Selec=map(Pot,3,850,1,6);    
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
      lcd.print(WiFi.localIP());
     }    
     else 
     {
      lcd.clear();
     }
}

        



