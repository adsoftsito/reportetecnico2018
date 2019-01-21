
#include <OneWire.h>
#include <EEPROM.h>
#define EEPROM_write(address, p) {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) EEPROM.write(address+i, pp[i]);}
#define EEPROM_read(address, p)  {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) pp[i]=EEPROM.read(address+i);}
#define ReceivedBufferLength 20
char receivedBuffer[ReceivedBufferLength+1];  
byte receivedBufferIndex = 0;
#define ecSensorPin  A3  ///////pion del sensor conductividad
#define ds18b20Pin  12  ///////pion del sensor temperatura  
#define SCOUNT  100         
int analogBuffer[SCOUNT];   
int analogBufferIndex = 0; 
#define compensationFactorAddress 8    
float compensationFactor;
#define VREF 5000 
boolean enterCalibrationFlag = 0;
float temperature,ECvalue,ECvalueRaw;
OneWire ds(ds18b20Pin);

/////////////
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  
#include "DHT.h"  
#define HT1 4
#define HT2 7
#define HT3 8
//#define HT4 12
#define DHTTYPE DHT22    
DHT dht1 (HT1, DHTTYPE);  
DHT dht2 (HT2, DHTTYPE);   
DHT dht3 (HT3, DHTTYPE);  
//DHT dht4 (HT4, DHTTYPE);
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;

int a,b,c,d,e,g,valor1,valor2,valor3,valor4,valor5,valor6,x,i,j,k,b1,b2,Pr,l1,l2,l3,l4; 
float h1,h2,h3,h4,ht,t1,t2,t3,t4,tt,Al,TemT,lt;
int Lamp1 = 5;
int Lamp2 = 3; 
int Lamp3 = 6;        
int Lamp4 = 11; 
int Lamp5 = 9; 
int Lamp6 = 10; 

int Contr = A6;
int Selec = A7;
int Boton1 = 2;
int Boton2 = 13;
void setup()
{
 Serial.begin(115200);
 readCharacteristicValues();
 /////////////////////
  dht1.begin();  
  dht2.begin();
  dht3.begin();  
  //dht4.begin();
  if (!bmp.begin())
  {while (1) {}}
  lcd.begin();                      
  lcd.backlight();
 pinMode(3,  OUTPUT);
 pinMode(5,  OUTPUT);
 pinMode(6,  OUTPUT);
 pinMode(9,  OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(2,  INPUT);
 pinMode(13, INPUT);   
}

void loop()
{
{
  if(serialDataAvailable() > 0)
  {
      byte modeIndex = uartParse();
      ecCalibration(modeIndex);    
  }
   static unsigned long analogSampleTimepoint = millis();
   if(millis()-analogSampleTimepoint > 30U) 
   {
     analogSampleTimepoint = millis();
     analogBuffer[analogBufferIndex] = analogRead(ecSensorPin);   
     analogBufferIndex++;
     if(analogBufferIndex == SCOUNT) 
         analogBufferIndex = 0;
   }
   static unsigned long tempSampleTimepoint = millis();
   if(millis()-tempSampleTimepoint > 850U)  
   {
      tempSampleTimepoint=millis();
      temperature = readTemperature();  
   }
   
   static unsigned long printTimepoint = millis();
   if(millis()-printTimepoint > 1000U)
   {
      printTimepoint = millis();
      float AnalogAverage = getMedianNum(analogBuffer,SCOUNT); 
      float averageVoltage=AnalogAverage*(float)VREF/1024.0;
      if(temperature == -1000)
      {
          temperature = 25.0;     
         
      }else{
          Serial.print(temperature,1);   
          Serial.print(F("^C             EC:"));
      }
     float TempCoefficient=1.0+0.0185*(temperature-25.0);    
     float CoefficientVolatge=(float)averageVoltage/TempCoefficient;   
     if(CoefficientVolatge<150)Serial.println(F("No solution!"));   
     else if(CoefficientVolatge>3300)Serial.println(F("Out of the range!"));  
     else{ 
      if(CoefficientVolatge<=448)ECvalue=6.84*CoefficientVolatge-64.32;   
      else if(CoefficientVolatge<=1457)ECvalue=6.98*CoefficientVolatge-127;  
      else ECvalue=5.3*CoefficientVolatge+2278;                          
      ECvalueRaw = ECvalue/1000.0;
      ECvalue = ECvalue/compensationFactor/1000.0;   
      Serial.print(ECvalue,2);     //two decimal
      Serial.print(F("ms/cm"));
       if(enterCalibrationFlag)            
       {  
          Serial.print(F("            Factor:"));
          Serial.print(compensationFactor);   
       }
     Serial.println();
     }          
   }   
}
////////////////
  {
  SELECTOR ();
  SENSOR ();
  LCD ();
  //SERIAL_M ();
  }

}
void SELECTOR ()
{
 Boton1 = digitalRead(2);
 i = analogRead(Contr);
 j=map(i,0, 1023,100, 0);
////////////////////////// 
if (Boton1 == HIGH)
  {
 lcd.setCursor(7, 1);
 lcd.print("S ");
   a=i;b=i;c=i;d=i;e=i;g=i;
  }
/////////////////////////  
else   
  {
  x = analogRead (Selec);
  if (x> 100 && x< 170) 
     {
  g = analogRead(Contr);
     k = 6;
     }
  if (x> 60 && x< 99) 
     {
  e = analogRead(Contr);
     k= 5;
     }
  if (x> 30 && x < 59) 
     {
  d = analogRead(Contr);
     k= 4;
     }
  if (x> 18 && x< 29) 
     {
  c = analogRead(Contr);
     k= 3;
     }         
  if (x> 7 && x< 17.5) 
     {
  b = analogRead(Contr);
     k= 2;
     }
  if (x > 1000 && x< 1025) 
     {
  a = analogRead(Contr);
     k= 1;
     }
  }
//////////////////////////////  
   analogWrite(Lamp1, a / 4);
   analogWrite(Lamp2, b / 4);
   analogWrite(Lamp3, c / 4);
   analogWrite(Lamp4, d / 4);
   analogWrite(Lamp5, e / 4);
   analogWrite(Lamp6, g / 4); 
   delay(200); 
}

void LCD ()
{
  lcd.clear();
  Boton2 = digitalRead(13);
if (Boton2 == HIGH)
  {
 lcd.setCursor(0, 0);
 lcd.print("T=");
 lcd.setCursor(2, 0);
 lcd.print(tt);
 lcd.setCursor(8, 0);
 lcd.print("L=");
 lcd.setCursor(10, 0);
 lcd.print(lt);
 lcd.setCursor(0, 1);
 lcd.print("H=");
 lcd.setCursor(2, 1);
 lcd.print(ht);

 delay (2000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("AL=");
 lcd.setCursor(3, 0);
 lcd.print(Al);
 lcd.setCursor(0, 1);
 lcd.print("PR=");
 lcd.setCursor(3, 1);
 lcd.print(Pr);
 delay (2000);
  } 
else   
 {
 lcd.setCursor(0, 0);
 lcd.println("KUBEET-SA-DE-CV-");
 lcd.setCursor(12, 1);
 lcd.print(j);
 lcd.setCursor(15, 1);
 lcd.print("%");
 lcd.setCursor(0, 1);
 lcd.print("LAMPARA");
 lcd.setCursor(8, 1);
 lcd.print(k);
 lcd.setCursor(9, 1);
 lcd.print(" =");
 }
}

void SENSOR ()
{

///////////////////////////// ILUMINACIÒN 
 l1=analogRead(A0);
 l2=analogRead(A1);
 l3=analogRead(A2);
// l4=analogRead(A3);
/////////////////////////////
  h1 = dht1.readHumidity();  
  h2 = dht2.readHumidity(); 
  h3 = dht3.readHumidity();  
 // h4 = dht4.readHumidity();  
  t1 = dht1.readTemperature();  
  t2 = dht2.readTemperature();
  t3 = dht3.readTemperature();  
 // t4 = dht4.readTemperature();
////////////////////////////// 
  Pr = (bmp.readSealevelPressure());
  Al = (bmp.readAltitude(100305));/// Presion atmosperica en pascales,para mejor resolucion  
  TemT = (bmp.readTemperature());
////////////////////////////// 
  tt= (t1+t2+t3)/3;
  ht= (h1+h2+h3)/3;
  lt= (l1+l2+l3)/3;
}

void SERIAL_M ()
{
 Serial.print("#");
 Serial.print("ILU/");
 Serial.print(l1);
 Serial.print("/");
 Serial.print(l2);
 Serial.print("/");
 Serial.print(l3);
// Serial.print("/");
// Serial.print(l4);
 Serial.print("&TEMP/");
 Serial.print(t1);
 Serial.print("/");
 Serial.print(t2);
 Serial.print("/");
 Serial.print(t3);
 //Serial.print("/");
 //Serial.print(t4);
  Serial.print("&HUME/");
 Serial.print(h1);
 Serial.print("/");
 Serial.print(h2);
 Serial.print("/");
 Serial.print(h3);
// Serial.print("/");
// Serial.print(h4);
  Serial.print("&Pre/");
 Serial.print(Pr);
  Serial.print("&Alt/");
 Serial.print(Al);
  Serial.print("&TemIn/");
 Serial.print(TemT);
   Serial.println("#");
 //---------------#ILU/0/0/0/0&TEMP/24.60/24.60/24.40/26.10&HUME/53.00/53.60/55.70/61.80&Pre/22597&Alt/1078.03&TemIn/24.80#
}
///////////////////////////////////////////////////

boolean serialDataAvailable(void)
{
  char receivedChar;
  static unsigned long receivedTimeOut = millis();
  while (Serial.available()>0) 
  {   
    if (millis() - receivedTimeOut > 500U) 
    {
      receivedBufferIndex = 0;
      memset(receivedBuffer,0,(ReceivedBufferLength+1));
    }
    receivedTimeOut = millis();
    receivedChar = Serial.read();
    if (receivedChar == '\n' || receivedBufferIndex==ReceivedBufferLength){
    receivedBufferIndex = 0;
    strupr(receivedBuffer);
    return true;
    }else{
      receivedBuffer[receivedBufferIndex] = receivedChar;
      receivedBufferIndex++;
    }
  }
  return false;
}

byte uartParse()
{
  byte modeIndex = 0;
  if(strstr(receivedBuffer, "CALIBRATION") != NULL) 
      modeIndex = 1;
  else if(strstr(receivedBuffer, "EXIT") != NULL) 
      modeIndex = 3;
  else if(strstr(receivedBuffer, "CONFIRM") != NULL)   
      modeIndex = 2;
  return modeIndex;
}

void ecCalibration(byte mode)
{
    char *receivedBufferPtr;
    static boolean ecCalibrationFinish = 0;
    float factorTemp;
    switch(mode)
    {
      case 0:
      if(enterCalibrationFlag)
         Serial.println(F("Command Error"));
      break;
      case 1:
      enterCalibrationFlag = 1;
      ecCalibrationFinish = 0;
      Serial.println();
      Serial.println(F(">>>Enter Calibration Mode<<<"));
      Serial.println(F(">>>Please put the probe into the 12.88ms/cm buffer solution<<<"));
      Serial.println();
      break;
     case 2:
      if(enterCalibrationFlag)
      {
          factorTemp = ECvalueRaw / 12.88;
          if((factorTemp>0.85) && (factorTemp<1.15))
          {
              Serial.println();
              Serial.println(F(">>>Confrim Successful<<<"));
              Serial.println();
              compensationFactor =  factorTemp;
              ecCalibrationFinish = 1;
          }
          else{
            Serial.println();
            Serial.println(F(">>>Confirm Failed,Try Again<<<"));
            Serial.println();
            ecCalibrationFinish = 0;
          }        
      }
      break;
        case 3:
        if(enterCalibrationFlag)
        {
            Serial.println();
            if(ecCalibrationFinish)
            {
               EEPROM_write(compensationFactorAddress, compensationFactor);
               Serial.print(F(">>>Calibration Successful"));
            }
            else Serial.print(F(">>>Calibration Failed"));       
            Serial.println(F(",Exit Calibration Mode<<<"));
            Serial.println();
            ecCalibrationFinish = 0;
            enterCalibrationFlag = 0;
        }
        break;
    }
}

int getMedianNum(int bArray[], int iFilterLen) 
{
      int bTab[iFilterLen];
      for (byte i = 0; i<iFilterLen; i++)
      {
    bTab[i] = bArray[i];
      }
      int i, j, bTemp;
      for (j = 0; j < iFilterLen - 1; j++) 
      {
    for (i = 0; i < iFilterLen - j - 1; i++) 
          {
      if (bTab[i] > bTab[i + 1]) 
            {
    bTemp = bTab[i];
          bTab[i] = bTab[i + 1];
    bTab[i + 1] = bTemp;
       }
    }
      }
      if ((iFilterLen & 1) > 0)
  bTemp = bTab[(iFilterLen - 1) / 2];
      else
  bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
      return bTemp;
}

void readCharacteristicValues()
{
    EEPROM_read(compensationFactorAddress, compensationFactor);  
    if(EEPROM.read(compensationFactorAddress)==0xFF && EEPROM.read(compensationFactorAddress+1)==0xFF && EEPROM.read(compensationFactorAddress+2)==0xFF && EEPROM.read(compensationFactorAddress+3)==0xFF)
    {
      compensationFactor = 1.0;  
      EEPROM_write(compensationFactorAddress, compensationFactor);
    }
}

float readTemperature()
{
  static byte data[12],addr[8];
  static float TemperatureSum = 25;
  static boolean ch = 0;
  if(!ch){
          if ( !ds.search(addr)) {
              ds.reset_search();
              return -1000;
          }      
          if ( OneWire::crc8( addr, 7) != addr[7]) {
              return -1000;
          }        
          if ( addr[0] != 0x10 && addr[0] != 0x28) {
              return -1000;
          }      
          ds.reset();
          ds.select(addr);
          ds.write(0x44,1); 
  }else{  
          byte present = ds.reset();
          ds.select(addr);    
          ds.write(0xBE);    
          for (int i = 0; i < 9; i++) { 
            data[i] = ds.read();
          }         
          ds.reset_search();           
          byte MSB = data[1];
          byte LSB = data[0];        
          float tempRead = ((MSB << 8) | LSB); 
          TemperatureSum = tempRead / 16;
    }
          ch = !ch;
          return TemperatureSum;  
}
