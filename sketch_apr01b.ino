#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);
int redPin = 6;
int greenPin = 5;
int bluePin = 7;
int sensPin = 0;
char curdata = 'n';
char Sdata = 'n';
bool atfirst = true;

void setup()
{
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("1");
  BTSerial.println("1");
}

void loop(){
  while (!BTSerial)
  {
    Serial.println("waiting for");
  }
  if (BTSerial&&atfirst==true)
  {
    BTSerial.println("one");
    Serial.println("conn");
    atfirst=false;
  }
    curdata = BTSerial.read();
    Sdata=Serial.read();
    if(curdata == 'z')
    {
      BTSerial.println("one");
      Serial.println("conn");
    }
    if(Sdata == 'z')
    {
      BTSerial.println("one");
      Serial.println("conn");
    }
    if(curdata == "z")
    {
      BTSerial.println("one");
      Serial.println("conn");
    }
    if(Sdata == "z")
    {
      BTSerial.println("one");
      Serial.println("conn");
    }
    if(curdata == '1')
    {
      setColor(0,195,255);
    }
    if(curdata == '2'){
      setColor(255,195,0);
    }
    if(curdata == '3'){
      setColor(195,0,255);
    }
    if(curdata == '4'){
      setColor(65,255,75);
    }
    if(curdata == 'n'){
      setColor(0,0,0);
    }
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
