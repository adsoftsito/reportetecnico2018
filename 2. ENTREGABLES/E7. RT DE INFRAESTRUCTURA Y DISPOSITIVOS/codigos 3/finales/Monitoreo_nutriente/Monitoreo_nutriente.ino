#include <ESP8266WiFi.h>
 #include <Wire.h> 
//////////////////////////
#define PuertoAnalogico (A0)
int buzzer =10;
int Selec  =15;
int Rele   =16;
int  ESR   =0;
/////////////Sensor PH///////////////  
unsigned long int  avgValue;                         //Variable interna para asignar datos del codigo PH
int                buf[10],temp;                     //Variable interna para calcular PH
float              PH;                               //Variable de PH
///////////////// SENSOR MG11 //////////

#define         BOOL_PIN                     (2)
#define         DC_GAIN                      (8.5)   //define the DC gain of amplifier
#define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            (5)     //define the time interval(in milisecond) between each samples in 
#define         ZERO_POINT_VOLTAGE           (0.220) //define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define         REACTION_VOLTGAE             (0.020) //define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2
float volts;  int CO2A; float CO2Curve[3]  =  {2.602,ZERO_POINT_VOLTAGE,(REACTION_VOLTGAE/(2.602-3))};   
int CO2;                                             //Variable de CO2                   
///////////////// SENSOR CE //////////
byte DS18B20_Pin = 2; //DS18B20 signal, pin on digital 
float A,CE2;

#include <OneWire.h>
#define StartConvert 0
#define ReadTemperature 1
const byte numReadings = 20;                                                      // el número de veces de muestra
unsigned int AnalogSampleInterval=25,printInterval=700,tempSampleInterval=850;    // intervalo de muestreo analógico; intervalo de impresión en serie; intervalo de muestreo de temperatura
unsigned int readings[numReadings];                                               // las lecturas de la entrada analógica
byte indexA = 0;                                                                  // el índice de la lectura actual
unsigned long AnalogValueTotal = 0;                                               // el total acumulado
unsigned int AnalogAverage = 0,averageVoltage=0;                                  // la media
unsigned long AnalogSampleTime,printTime,tempSampleTime;
float Temp, CE; 
OneWire ds(DS18B20_Pin);
////////Libreria del LCD//////////////////////
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int B; 
///////////////// PINES DEL MULTIPLEXOR //////////
const int switch1= 14;
const int switch2= 12;
const int switch3= 13; 
// ------------Datos de la red para entrar como cliente----------
const char* ssid = "RED NODE";
const char* password = "RED12345";

IPAddress ip(192,168,0,11);   
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0); 
WiFiServer server(80);
void setup()
{
  Serial.begin(115200);
  
  for (byte thisReading = 0; thisReading < numReadings; thisReading++)   // inicialice todas las lecturas a 0: 
  readings[thisReading] = 0;
  TempProcess(StartConvert);  
  AnalogSampleTime=millis();
  printTime=millis();
  tempSampleTime=millis();
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
       pinMode(switch1, OUTPUT);
       pinMode(switch2, OUTPUT);
       pinMode(switch3, OUTPUT);
       pinMode(buzzer,  OUTPUT);
       pinMode(Rele,    OUTPUT);
       pinMode(Selec, INPUT);
  digitalWrite(switch1, LOW);
  digitalWrite(switch2, LOW);
  digitalWrite(switch3, LOW);
  digitalWrite(buzzer,  LOW);
  digitalWrite(Rele,    LOW);
}

void loop()
{
  {
  multiplexor();
  Desplegado_local();
  }
  {
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
                                                         //#IP=192.168.5.11/CO2=400PPM/PH=4.03-/CE=1.38mS/cm/TemLiq=25.81*C/Re=0/#
    if (currentLine.endsWith("GET /MMN-Valores")) {
                                                client.print("#IP=");    client.print(WiFi.localIP());   client.print("/");
                                                client.print("CO2=");client.print(CO2);           client.print("PPM");client.print("/");
                                                client.print("PH=");client.print(PH);            client.print("-");client.print("/");
                                                client.print("CE=");client.print(CE);           client.print("mS/cm");client.print("/");
                                                client.print("TemLiq=");client.print(Temp);client.print("*C");client.print("/");
                                                client.print("Re=");client.print(ESR);client.println("/#");
                                                 }
//////////////////////////////////////////////////////////////////////////////  CONTROL ON  ////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                        //#IP=192.168.5.12/R1=1/#
    if (currentLine.endsWith("GET /MMN-R1-ON")) {
       ESR=1; 
                                               digitalWrite(Rele, HIGH);client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print("1");
                                               client.println("/#");
                                               }   
////////////////////////////////////////////////////////////////////////////// CONTROL OFF ////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                        //#IP=192.168.5.12/R1=0/#
    if (currentLine.endsWith("GET /MMN-R1-OFF")) {
       ESR=0;
                                                digitalWrite(Rele, LOW);client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print("0");
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
}

void multiplexor()
{
  digitalWrite(switch1, HIGH);
  sensorMQ();
  digitalWrite(switch1, LOW);
  delay(1000);
  
  digitalWrite(switch2, HIGH);
  sensorCE();
  digitalWrite(switch2, LOW);
  delay(1000);

  digitalWrite(switch3, HIGH);
  sensorPH();
  //PH = (((analogRead(A0)*3.3)/1024)*2);
  digitalWrite(switch3, LOW);
  delay(1000);
}
//////////////////////DESPLEGADO LOCAL //////////////////////////
void Desplegado_local()
{ 
  B= digitalRead(Selec);
  
  if (B == LOW) 
     {
  lcd.clear();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MODULO-NUTRIENTE");
      lcd.setCursor(0,1);
      lcd.print("CO2=    -PH=");
      lcd.setCursor(4,1);
      lcd.print(CO2);
      lcd.setCursor(13,1);
      lcd.print(PH);
     }
  else 
     {
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("CONDUTIV=     mS");
      lcd.setCursor(9,0);
      lcd.print(CE);
      lcd.setCursor(0,1);
      lcd.print("TEMP LIQ=     *C");
      lcd.setCursor(9,1);
      lcd.print(Temp);
     }

}

///////////// Funcion SENSOR PH/////////////////
void sensorPH()
{
  for(int i=0;i<10;i++)       
  {
    buf[i]=(analogRead(PuertoAnalogico)*2);
    delay(10);
  }
  for(int i=0;i<9;i++)        
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i]; buf[i]=buf[j]; buf[j]=temp;
      }
    }
  }
  avgValue=0; for(int i=2;i<8;i++) avgValue+=buf[i];
  float phValue=(float)avgValue*3.3/1024/6; //Ecuaciòn para convertir la señal leida en milivoltios
  PH= -5.70 * phValue + 21.34;              //Ecuaciòn para calcular PH en fucnion de la señal recibida en milivoltios
}

///////////// Funcion SENSOR MG11/////////////////
void sensorMQ()
{
    volts = MGRead((PuertoAnalogico)*2);
    CO2A = MGGetPercentage(volts,CO2Curve);
    if (CO2A == -1) 
    {
      CO2=400;
    } else 
    {
     CO2=CO2A;
    }
}

float MGRead(int mg_pin)
{
    int i;
    float v=0;
    for (i=0;i<READ_SAMPLE_TIMES;i++) 
    {
        v += (analogRead(PuertoAnalogico)*2);              ////////////POR DOS
        delay(READ_SAMPLE_INTERVAL);
    }
    v = (v/READ_SAMPLE_TIMES) *3.3/1024 ;
    return v;  
}
 
int  MGGetPercentage(float volts, float *pcurve)
{
   if ((volts/DC_GAIN )>=ZERO_POINT_VOLTAGE) {
      return -1;
   } else { 
      return pow(10, ((volts/DC_GAIN)-pcurve[1])/pcurve[2]+pcurve[0]);
   }
}
///////////// Funcion SENSOSOR CONDUCTIVIDAD/////////////////
void sensorCE()
{
  /*
   De vez en cuando, muestree el valor analógico y calcule el promedio.
  */

  CE2= CE*10;
   A= ((PuertoAnalogico)*2.84);
  
  if(millis()-AnalogSampleTime>=AnalogSampleInterval)  
  {
    AnalogSampleTime=millis();                                           // restar la última lectura:
    AnalogValueTotal = AnalogValueTotal - readings[indexA];               // leer desde el sensor:
    readings[indexA] = A;                           // agregue la lectura al total y lo mulriplica por dos:   
    AnalogValueTotal = AnalogValueTotal + readings[indexA];               // avanzar a la siguiente posición en la matriz:
    indexA = indexA + 1;                                                   // si estamos al final de la matriz ...
    if (indexA >= numReadings)                                            // ... envuelve el comienzo:
    indexA = 0;                                                           // calcule el promedio:
    AnalogAverage = AnalogValueTotal / numReadings;
  }
  /*
    De vez en cuando, MCU lee la temperatura del DS18B20 y luego deja que el DS18B20 inicie el convert.
    Atención: ¡El intervalo entre comenzar la conversión y leer la temperatura debe ser mayor a 750 milisegundos, o la temperatura no es precisa!
  */
   if(millis()-tempSampleTime>=tempSampleInterval) 
  {
    tempSampleTime=millis();
    Temp = TempProcess(ReadTemperature);   // lea la temperatura actual del DS18B20
    TempProcess(StartConvert);                    // después de la lectura, inicie la conversión para la próxima lectura
  }
   /*
   De vez en cuando, imprima la información en el monitor de serie.
  */
  if(millis()-printTime>=printInterval)
  {
    printTime=millis();
    averageVoltage=AnalogAverage*(float)5000/1024;                           //ajuste del convertidor
    float TempCoefficient=1.0+0.0185*(Temp-25.0);                     //fórmula de compensación de temperatura: fFinalResult (25 ^ C) = fFinalResult (actual) / (1.0 + 0.0185 * (fTP-25.0));
    float CoefficientVolatge=(float)averageVoltage/TempCoefficient;   
    if(CoefficientVolatge<150)               // 25 ^ C 1413us / cm <-> aproximadamente 216mv si el voltaje (compensación) <150, es decir <1ms / cm, fuera del rango
    CE=0;
    //Serial.println("No solution!"); 
    else if(CoefficientVolatge>3300)     //>20ms/cm,fuera del rango
    CE=-1;
    //Serial.println("Out of the range!");
    else
    { 
      if(CoefficientVolatge<=448)CE=6.84*CoefficientVolatge-64.32;       //1ms/cm<EC<=3ms/cm
      else if(CoefficientVolatge<=1457)CE=6.98*CoefficientVolatge-127;  //3ms/cm<EC<=10ms/cm
      else CE=5.3*CoefficientVolatge+2278;                             //10ms/cm<EC<20ms/cm
      CE/=1000;    //convert us/cm to ms/cm
    }
  }

}
/*
ch = 0, deje que el DS18B20 inicie la conversión; ch = 1, MCU lea la temperatura actual del DS18B20.
*/
float TempProcess(bool ch)
{
  //returns the temperature from one DS18B20 in DEG Celsius
  static byte data[12];
  static byte addr[8];
  static float TemperatureSum;
  if(!ch){
          if ( !ds.search(addr)) {
              //Serial.println("no more sensors on chain, reset search!");
              ds.reset_search();
              return 0;
          }      
          if ( OneWire::crc8( addr, 7) != addr[7]) {
              //Serial.println("CRC is not valid!");
              return 0;
          }        
          if ( addr[0] != 0x10 && addr[0] != 0x28) {
              //Serial.print("Device is not recognized!");
              return 0;
          }      
          ds.reset();
          ds.select(addr);
          ds.write(0x44,1);                    // iniciar la conversión, con el parásito encendido al final
  }
  else{  
          byte present = ds.reset();
          ds.select(addr);    
          ds.write(0xBE); // Read Scratchpad            
          for (int i = 0; i < 9; i++) {        // necesitamos 9 bytes
            data[i] = ds.read();
          }         
          ds.reset_search();           
          byte MSB = data[1];
          byte LSB = data[0];        
          float tempRead = ((MSB << 8) | LSB);  //usando complemento de dos
          TemperatureSum = tempRead / 16;
    }
         return TemperatureSum;  

}
