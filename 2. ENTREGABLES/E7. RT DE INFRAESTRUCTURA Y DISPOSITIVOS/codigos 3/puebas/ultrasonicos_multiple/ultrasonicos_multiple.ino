#define trigPin1 15
#define echoPin1 10
#define trigPin2 4
#define echoPin2 5
#define trigPin3 14
#define echoPin3 12
long duration, distance;
long Distancia1,Distancia2,Distancia3;
 
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
}
 
void loop() 
{
SonarSensor(trigPin1, echoPin1);
Distancia1 = distance;
SonarSensor(trigPin2, echoPin2);
Distancia2 = distance;
SonarSensor(trigPin3, echoPin3);
Distancia3 = distance;
Serial.print(Distancia1);
Serial.print(" - ");
Serial.print(Distancia2);
Serial.print(" - ");
Serial.println(Distancia3);
}
 
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
 
}
