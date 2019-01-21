
float PH, CE, MQ;

const int switch1= 14;
const int switch2= 12;
const int switch3= 13; 
int buzzer =10;

void setup()
{
  Serial.begin(9600);
  pinMode(switch1, OUTPUT);
  pinMode(switch2, OUTPUT);
  pinMode(switch3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(switch1, LOW);
  digitalWrite(switch2, LOW);
  digitalWrite(switch3, LOW);
  digitalWrite(buzzer, LOW);
}

void loop()
{
  multiplexor();
  monitor_serial();
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
  digitalWrite(switch3, LOW);
  delay(1000);
}
/////////// monitor serial//////
void monitor_serial()
{
  Serial.print("PH: ");
  Serial.print(PH);
  Serial.print("   CE: ");
  Serial.print(CE);
  Serial.print("   MQ: ");
  Serial.println(MQ);
}

///////////// Funcion PH/////////////////
void sensorPH()
{
  
  PH = (((analogRead(A0)*3.3)/1024)*2);
}

///////////// Funcion PH/////////////////
void sensorCE()
{
  
  CE = (((analogRead(A0)*3.3)/1024)*2);
 
}

///////////// Funcion PH/////////////////
void sensorMQ()
{
  MQ = (((analogRead(A0)*3.3)/1024)*2);
}
