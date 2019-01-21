#include <ESP8266WiFi.h>
 #include <Wire.h> 
const char* ssid = "RED NODE";
const char* password = "RED12345";

IPAddress ip(192,168,0,10);   
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0); 
WiFiServer server(80);

const int Rele1= 13; 
const int Rele2= 0; 
const int Rele3= 16; 

int Estado1,Estado2,Estado3=0;

const int triger1 = 2;
const int echo1   = 10;
const int triger2 = 4;
const int echo2   = 5; 
const int triger3 = 14;
const int echo3   = 12;
  
int d1,d2,d3;
long esp1,esp2,esp3;
void setup() 
{
  Serial.begin(9600);
  delay(10);
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
 

  pinMode(Rele1, OUTPUT); // Luces
  pinMode(Rele2, OUTPUT); // Luces
  pinMode(Rele3, OUTPUT); // Luces
  digitalWrite(Rele1, LOW);
  digitalWrite(Rele2, LOW);
  digitalWrite(Rele3, LOW);
  
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

  WiFiClient client = server.available();
  
  if (client) 
  {
    Serial.println("New client");
    boolean blank_line = true;
     String currentLine = "";
    while (client.connected()) {
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
                                 

///////////////////////////////////////////////////////////////////////////  Monitoreo de nivel  ////////////////////////////////////////////////////////////////////////////////////////////////                                               
                                                                //  #IP=192.168.5.10/N1=14cm/N2=14cm/N3=14cm/#
    if (currentLine.endsWith("GET /CN-Valores"))  { 
       digitalWrite(triger1, LOW);delayMicroseconds(10);digitalWrite(triger1, HIGH);delayMicroseconds(10);digitalWrite(triger1, LOW);esp1 = (pulseIn(echo1, HIGH)/2); d1 = int(esp1 * 0.0343);
       delay (1000);
       digitalWrite(triger2, LOW);delayMicroseconds(10);digitalWrite(triger2, HIGH);delayMicroseconds(10);digitalWrite(triger2, LOW);esp2 = (pulseIn(echo2, HIGH)/2); d2 = int(esp2 * 0.0343);
       delay (1000);
       digitalWrite(triger3, LOW);delayMicroseconds(10);digitalWrite(triger3, HIGH);delayMicroseconds(10);digitalWrite(triger3, LOW);esp3 = (pulseIn(echo3, HIGH)/2); d3 = int(esp3 * 0.0343);         
       delay (1000);
                                                 client.print("#IP=");client.print(WiFi.localIP());client.print("/");
                                                 client.print("N1=");client.print(d1);client.print("cm");client.print("/");client.print("N2=");client.print(d2);client.print("cm");client.print("/");client.print("N3=");client.print(d3);client.print("cm");
                                                 client.println("/#");}
                                               
//////////////////////////////////////////////////////////////////////////////  CONTROL ON/OFF RELE 1////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                      //#IP=192.168.5.10/R1=1/R2=0/R3=0#
    if (currentLine.endsWith("GET /CN-R1-ON")) { digitalWrite(Rele1, HIGH);Estado1=1;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                                client.println("/#");}   
    if (currentLine.endsWith("GET /CN-R1-OFF")) { digitalWrite(Rele1,LOW);Estado1=0;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                                client.println("/#");}   
 //////////////////////////////////////////////////////////////////////////////  CONTROL ON/OFF RELE 2 ////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                          //#IP=192.168.5.10/R1=1/R2=1/R3=0#
    if (currentLine.endsWith("GET /CN-R2-ON")) { digitalWrite(Rele2, HIGH);Estado2=1;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                               client.println("/#");}   
    if (currentLine.endsWith("GET /CN-R2-OFF")) { digitalWrite(Rele2,LOW);Estado2=0;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                               client.println("/#");}   
//////////////////////////////////////////////////////////////////////////////  CONTROL ON/OFF RELE 3 ////////////////////////////////////////////////////////////////////////////////////////////////// 
                                                                         //#IP=192.168.5.10/R1=1/R2=1/R3=1#
    if (currentLine.endsWith("GET /CN-R3-ON")) { digitalWrite(Rele3, HIGH);Estado3=1;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                               client.println("/#");}   
    if (currentLine.endsWith("GET /CN-R3-OFF")) { digitalWrite(Rele3,LOW);Estado3=0;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                               client.println("/#");}  
                                    
//////////////////////////////////////////////////////////////////////////////  CONTROL ON/OFF RELES /////////////////////////////////////////////////////////////////////////////////////////////////
                                            
 if (currentLine.endsWith("GET /CN-RT-ON")) { digitalWrite(Rele1,HIGH);digitalWrite(Rele2,HIGH);digitalWrite(Rele3,HIGH);Estado1=1,Estado2=1,Estado3=1;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                              client.println("/#");} 
 if (currentLine.endsWith("GET /CN-RT-OFF")) { digitalWrite(Rele1,LOW);digitalWrite(Rele2,LOW);digitalWrite(Rele3,LOW);Estado1=0,Estado2=0,Estado3=0;client.print("#IP=");client.print(WiFi.localIP());client.print("/");client.print("R1=");client.print(Estado1);client.print("/");client.print("R2=");client.print(Estado2);client.print("/");client.print("R3=");client.print(Estado3);
                                              client.println("/#");} 
                                           
                                                                                                                        
    }
    }
////////  Se cierra la conexion:  //////////////////////////////////////////////////
    client.stop();
    Serial.println("cliente desconectado");
  }
}
        



