#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM900
SoftwareSerial mySerial(10, 9); //SIM900 Tx & Rx is connected to Arduino #7 & #8

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM900
  mySerial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);
  Serial.println("Handshaking with SIM900A");
  Serial.println(mySerial.println("AT")); //Handshaking with SIM900
  updateSerial();
  Serial.println("Signal Quality Test:");
  Serial.println(mySerial.println("AT+CSQ")); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  Serial.println("Reading SIM information:");
  Serial.println(mySerial.println("AT+CCID")); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  Serial.println("Checking if SIM has registered on the network:");
  Serial.println(mySerial.println("AT+CREG?")); //Check whether it has registered in the network
  updateSerial();
}

void loop()
{
  updateSerial();
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
