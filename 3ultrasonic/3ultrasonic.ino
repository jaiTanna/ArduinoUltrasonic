#include "NewPing.h"
#define trigpin1  10
#define echopin1  13

#define trigpin2  5
#define echopin2  7

#define trigpin3  6
#define echopin3  8

float distance,duration,sensor1,sensor2,sensor3;

void setup() 
{Serial.begin(9600);

pinMode (trigpin1,OUTPUT);
pinMode (echopin1,INPUT);

pinMode (trigpin2,OUTPUT);
pinMode (echopin2,INPUT);

pinMode (trigpin3,OUTPUT);
pinMode (echopin3,INPUT);

Serial.println("CLEARDATA");
Serial.println("LABEL,current time,dis_sen_1 in cm,dis_sen_2 in cm,dis_sen_3 in cm");
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  SonarSensor(trigpin1, echopin1);
sensor1=distance;
SonarSensor(trigPin2, echopin2);
sensor2=distance;
SonarSensor(trigPin3, echopin3);
sensor3=distance;

// Measure responce from echo pin:

  Serial.print("S1 :");Serial.println(sensor1);delayMicroseconds(10);
  Serial.print("S2 :");Serial.println(sensor2);delayMicroseconds(10);
  Serial.print("S3 :");Serial.println(sensor3);delayMicroseconds(10);
  

  Serial.println(" ");

delay(1000);
}
