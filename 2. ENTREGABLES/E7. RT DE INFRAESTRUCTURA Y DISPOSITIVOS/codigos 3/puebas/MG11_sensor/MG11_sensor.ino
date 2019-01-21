
#define         PuertoAnalogico              (0)     //define which analog input channel you are going to use

#define         BOOL_PIN                     (2)
#define         DC_GAIN                      (8.5)   //define the DC gain of amplifier
#define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            (5)     //define the time interval(in milisecond) between each samples in 
#define         ZERO_POINT_VOLTAGE           (0.220) //define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define         REACTION_VOLTGAE             (0.020) //define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2
float           CO2Curve[3]  =  {2.602,ZERO_POINT_VOLTAGE,(REACTION_VOLTGAE/(2.602-3))};   
float volts;  int CO2,CO2A;
                                         
 
void setup()
{
    Serial.begin(9600);                              //UART setup, baudrate = 9600bps         
}
 
void loop()

{
  sensorMQ();
  monitor_serial();
}

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

void monitor_serial()
{
    Serial.print(volts); 
    Serial.print( "         " );
    Serial.print("CO2:");
    Serial.print(CO2);
    Serial.print( "ppm" );  
    Serial.print("\n");
    delay(500);
}

