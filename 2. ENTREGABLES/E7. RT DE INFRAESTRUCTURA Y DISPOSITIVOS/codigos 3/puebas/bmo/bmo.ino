#include <Wire.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
  
void setup() 
{
  Serial.begin(9600);
  bmp.begin();
  Serial.println("Sensor BMP180");
}
  
void loop() 
{
    Serial.print("Temperatura = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    Serial.print("Presion = ");
    Serial.print(bmp.readPressure()/10);
    Serial.println(" hPas");
    Serial.print("Altitud = ");
    Serial.print(bmp.readAltitude(100305));
    Serial.println(" metros");

    Serial.println();
    delay(3000); //5000
}


