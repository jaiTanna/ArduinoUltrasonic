#define trigpin 05
#define echopin 07



float distance,duration;

void setup() 
{
  Serial.begin(9600); 
  // put your setup code here, to run once:
pinMode (trigpin,OUTPUT);
pinMode (echopin,INPUT);
Serial.println("CLEARDATA");
Serial.println("LABEL,current time,distance in cm");
}

void loop() 
{
  // put your main code here, to run repeatedly:
digitalWrite(trigpin,LOW);
delayMicroseconds(2);

digitalWrite(trigpin,HIGH);
delayMicroseconds(10);

digitalWrite(trigpin,LOW);

// Measure responce from echo pin:

  duration = pulseIn(echopin,HIGH);
distance=(duration/2)*0.0343;

// send data to serial monitor
  Serial.print("DATA,TIME,");
Serial.print(distance);
  Serial.println(" ");

delay(1000);
}

  
