
#define PuertoAnalogico (A0)
byte DS18B20_Pin = 2; //DS18B20 signal, pin on digital 
int buzzer =10;

/////////////////////////////////////////////////////////////////
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
float Temp, CE,A; 
OneWire ds(DS18B20_Pin);  

///////////////// PINES DEL MULTIPLEXOR //////////
const int switch1= 14;
const int switch2= 12;
const int switch3= 13; 
void setup()
{
  Serial.begin(115200);
  for (byte thisReading = 0; thisReading < numReadings; thisReading++)   // inicialice todas las lecturas a 0: 
  readings[thisReading] = 0;
  TempProcess(StartConvert);  
  AnalogSampleTime=millis();
  printTime=millis();
  tempSampleTime=millis();
       pinMode(switch1, OUTPUT);
       pinMode(switch2, OUTPUT);
       pinMode(switch3, OUTPUT);
       pinMode(buzzer, OUTPUT);
  digitalWrite(switch1, LOW);
  digitalWrite(switch2, HIGH);
  digitalWrite(switch3, LOW);
  digitalWrite(buzzer, LOW);
  
}

void loop() 
{
  sensorCE();
  Monitor_serial();
}
void sensorCE()
{
  /*
   De vez en cuando, muestree el valor analógico y calcule el promedio.
  */
   A= ((PuertoAnalogico)*2.6);
  
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


void Monitor_serial()
{
    Serial.print("Analog value:");
    Serial.print(AnalogAverage);   //analog average,from 0 to 1023
    Serial.print("    Voltage:");
    Serial.print(averageVoltage);  //millivolt average,from 0mv to 4995mV
    Serial.print("mV    ");
    Serial.print("temp:");
    Serial.print(Temp);    //current temperature
    Serial.print("^C     EC:");
    Serial.print(CE);  //two decimal
    Serial.println("ms/cm");
    delay (1000);
}

