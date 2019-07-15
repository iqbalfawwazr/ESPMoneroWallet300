#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

void setup()
{
  Serial.begin(9600);
  Serial.println("www.TheEngineeringProjects.com");

  mySerial.begin(9600);
  mySerial.println("www.TheEngineeringProjects.com");
}

void loop() 
{
  if (mySerial.available())
    Serial.println(mySerial.read() - 48);
  if (Serial.available())
    mySerial.println(Serial.read() - 48);
}
