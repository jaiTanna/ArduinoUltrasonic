#define trigpin1 05
#define echopin1 07

#define trigpin3 6
#define echopin3 8

#define trigpin2 10
#define echopin2 13

float distance,duration,sensor1,sensor2,sensor3;
 

void setup() 
{
  Serial.begin(9600); 
  // put your setup code here, to run once:
pinMode (trigpin1,OUTPUT);
pinMode (echopin1,INPUT);
pinMode (trigpin2,OUTPUT);
pinMode (echopin2,INPUT);
pinMode (trigpin3,OUTPUT);
pinMode (echopin3,INPUT);
Serial.println("CLEARDATA");
Serial.println("LABEL,current time,dis_sens_1,dis_sens_2,dis_sens_3");

}

void loop() 
{
  // put your main code here, to run repeatedly:
SonarSensor(trigpin1,echopin1);
sensor1=distance;
SonarSensor(trigpin2,echopin2);
sensor2=distance;
SonarSensor(trigpin3,echopin3);
sensor3=distance;

Serial.print("DATA,TIME,"); 
Serial.print(sensor1);
 Serial.print(" ,");
 Serial.print(sensor2);
 Serial.print(" ,");
 Serial.print(sensor3);
Serial.println(" ,");

delay(1000);
}

void SonarSensor (int trigpin, int echopin)
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin,LOW);
  duration=pulseIn(echopin,HIGH);
  distance=(duration/2)*0.0343;
}
