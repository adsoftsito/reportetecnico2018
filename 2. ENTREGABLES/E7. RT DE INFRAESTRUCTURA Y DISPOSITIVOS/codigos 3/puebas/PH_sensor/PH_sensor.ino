#define PuertoAnalogico (A0)
int buzzer =10;

unsigned long int avgValue;  //Variable interna para asignar datos del codigo PH
int buf[10],temp;            //Variable interna para calcular PH
float PH;                    //Variable de PH

///////////////// PINES DEL MULTIPLEXOR //////////
const int switch1= 14;
const int switch2= 12;
const int switch3= 13; 

void setup()
{ 
  Serial.begin(115200);
       pinMode(switch1, OUTPUT);
       pinMode(switch2, OUTPUT);
       pinMode(switch3, OUTPUT);
       pinMode(buzzer, OUTPUT);
  digitalWrite(switch1, LOW);
  digitalWrite(switch2, LOW);
  digitalWrite(switch3,HIGH);
  digitalWrite(buzzer,  LOW);
}

void loop()
{
  delay(1000);
  sensorPH();
  monitor_serial();
}

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

void monitor_serial()
{
  Serial.print("Voltaje: ");  
  Serial.print(((analogRead(PuertoAnalogico)*2)*3.3)/1024);
  Serial.print("-----pH: ");  
  Serial.println(PH);
  delay(1000);
}

