//15-10
//4-5
//14-2
const int triger1 = 2;
const int echo1   = 10;
const int triger2 = 4;
const int echo2   = 5; 
const int triger3 = 14;
const int echo3   = 12;

int d1,d2,d3;
long esp1,esp2,esp3;
 
void setup() {
  Serial.begin(9600);
  pinMode(triger1, OUTPUT); 
  pinMode(echo1,    INPUT);  
  pinMode(triger2, OUTPUT); 
  pinMode(echo2,    INPUT);  
  pinMode(triger3, OUTPUT); 
  pinMode(echo3,    INPUT);
  digitalWrite(triger1, LOW);
  digitalWrite(triger2, LOW);
  digitalWrite(triger3, LOW);
}

void loop()
{

  digitalWrite(triger1, LOW);delayMicroseconds(10);digitalWrite(triger1, HIGH);delayMicroseconds(10);digitalWrite(triger1, LOW);esp1 = (pulseIn(echo1, HIGH)/2); d1 = int(esp1 * 0.0343);
  delay (1000);
  digitalWrite(triger2, LOW);delayMicroseconds(10);digitalWrite(triger2, HIGH);delayMicroseconds(10);digitalWrite(triger2, LOW);esp2 = (pulseIn(echo2, HIGH)/2); d2 = int(esp2 * 0.0343);
  delay (1000);
  digitalWrite(triger3, LOW);delayMicroseconds(10);digitalWrite(triger3, HIGH);delayMicroseconds(10);digitalWrite(triger3, LOW);esp3 = (pulseIn(echo3, HIGH)/2); d3 = int(esp3 * 0.0343);         
  delay (1000);
  
  Serial.print("Distancia 1: ");
  Serial.print(d1);      
  Serial.print("cm");
  Serial.println();         
  Serial.print("Distancia 2: ");
  Serial.print(d2);      
  Serial.print("cm");
  Serial.println();
  Serial.print("Distancia 3: ");
  Serial.print(d3);      
  Serial.print("cm");
  Serial.println();
  delay(2000);         
}

