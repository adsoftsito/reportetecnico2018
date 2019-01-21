#include <SFE_BMP180.h>
#include <Wire.h>
//Se declara una instancia de la librería
SFE_BMP180 pressure;
//Se declaran las variables. Es necesario tomar en cuenta una presión inicial
//esta será la presión que se tome en cuenta en el cálculo de la diferencia de altura
double PresionBase;
//Leeremos presión y temperatura. Calcularemos la diferencia de altura
double Presion = 0;
double Altura = 0;
double Temperatura = 0;
char status;
void setup() {
Serial.begin(9600);
//Se inicia el sensor y se hace una lectura inicial
SensorStart();
}
void loop() {
//Se hace lectura del sensor
ReadSensor();
//Se imprimen las variables
Serial.println(" ////// ");
Serial.print("Temperatura: ");
Serial.print(Temperatura);
Serial.println(" grados C");
Serial.print("Presion: ");
Serial.print(Presion);
Serial.println(" milibares");
Serial.print("Altura relativa: ");
Serial.print(Altura);
Serial.println(" metros");
delay(10000);
//Cada 10 segundos hará una nueva lectura
}
void SensorStart() {
//Secuencia de inicio del sensor
if (pressure.begin())
Serial.println("BMP180 init success");
else
{
Serial.println("BMP180 init fail (disconnected?)\n\n");
while (1);
}
//Se inicia la lectura de temperatura
status = pressure.startTemperature();
if (status != 0)  {
delay(status);
//Se lee una temperatura inicial
status = pressure.getTemperature(Temperatura);
if (status != 0)    {
//Se inicia la lectura de presiones
status = pressure.startPressure(3);
if (status != 0)     
{
delay(status);
//Se lee la presión inicial incidente sobre el sensor en la primera ejecución
status = pressure.getPressure(PresionBase, Temperatura);
}
}
}
}
void ReadSensor() {
//En este método se hacen las lecturas de presión y temperatura y se calcula la altura
//Se inicia la lectura de temperatura
status = pressure.startTemperature();
if (status != 0)
{
delay(status);
//Se realiza la lectura de temperatura
status = pressure.getTemperature(Temperatura);
if (status != 0)
{
//Se inicia la lectura de presión
status = pressure.startPressure(3);
if (status != 0)
{
delay(status);
//Se lleva a cabo la lectura de presión,</span>
//considerando la temperatura que afecta el desempeño del sensor</span>
status = pressure.getPressure(Presion, Temperatura);
if (status != 0)
{
//Cálculo de la altura en base a la presión leída en el Setup
Altura = pressure.altitude(Presion, PresionBase);
}
else Serial.println("Error en la lectura de presion\n");
}
else Serial.println("Error iniciando la lectura de presion\n");
}
else Serial.println("Error en la lectura de temperatura\n");
}
else Serial.println("Error iniciando la lectura de temperatura\n");
}
