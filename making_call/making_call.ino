#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);//(Rx TX) of arduino;  Tx of gsm should be connected to pin 9 of arduino and Rx should be at 10; 

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  Serial.println("Calling through GSM Modem");
  //mySerial.begin(9600);//setting baudrate at 9600;
  delay(5000);
  Serial.println(mySerial.println("ATD+917772881269;")); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
  Serial.println("Called ATD+917772881269");
  delay(20000);
} //end of void loop  
