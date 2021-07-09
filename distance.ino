#define trigpin 8
#define echopin 9
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long distance,duration;
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = (duration/2) / 29.1;

if(distance>=75|| distance<=0)
{
  Serial.println("Out of range");
}
else
{
  Serial.print("DISTANCE:");
  Serial.println(distance);
  digitalWrite(13, HIGH);  
  delay(20);                     
  digitalWrite(13, LOW);    
  delay(5); 
}
delay(500);
}
