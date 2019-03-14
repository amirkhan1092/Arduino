
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

Serial.begin(9600);
}
int red,green,blue;
String data;
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
data=Serial.readString();

red=255-data.substring(0,3).toInt();
green=255-data.substring(4,7).toInt();
blue=255-data.substring(8,11).toInt();
  

analogWrite(3,red);

analogWrite(5,green);
analogWrite(6,blue);





}




  
//digitalWrite(3,0);
//digitalWrite(5,1);
//digitalWrite(6,1);
//delay(1000);
//digitalWrite(3,1);
//digitalWrite(5,0);
//digitalWrite(6,1);
//delay(1000);
//
//digitalWrite(3,1);
//digitalWrite(5,1);
//digitalWrite(6,0);
//delay(1000);
//
//digitalWrite(3,0);
//digitalWrite(5,0);
//digitalWrite(6,0);
//delay(1000);
//
//digitalWrite(3,1);
//digitalWrite(5,1);
//digitalWrite(6,1);
//delay(1000);
//
//digitalWrite(3,0);
//digitalWrite(5,1);
//digitalWrite(6,0);
//delay(1000);
//
//digitalWrite(3,1);
//digitalWrite(5,0);
//digitalWrite(6,0);
//delay(1000);
}
