#include <SoftwareSerial.h>
SoftwareSerial HM10(0, 1);
char appData;  
String inData = "";

void setup()
{
  Serial.begin(9600);
  HM10.begin(9600);
  pinMode(8, OUTPUT);
}

void loop()
{
  HM10.listen();
  while (HM10.available() > 0) {
    appData = HM10.read();
    inData = String(appData);
    //Serial.print(appData);
    Serial.write(appData);
  }
  if (Serial.available()) {
    delay(10);
    HM10.write(Serial.read());
  }
  if ( inData == "A") {
    //Serial.println("LAMP ON");
    digitalWrite(8, HIGH);
    delay(100);
  }
  if ( inData == "B") {
    //Serial.println("LAMP OFF");
    digitalWrite(8, LOW);
    delay(100);
  }
}
