#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 9);//(Rx TX) of arduino;  Tx of gsm should be connected to pin 9 of arduino and Rx should be at 10; 

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  mySerial.begin(9600);
  delay(1000);
  Serial.println(mySerial.println("ATD"));
  /*while(!Serial) {
    ;
  }*/
  /*mySerial.begin(2400);
  mySerial.write("AT+CMGF=1\r");
  delay(1500);
  mySerial.write("AT+CPMS=\"SM\"\r");         //Preferred SMS Message Storage
  delay(1000);
  mySerial.write("AT+CMGL=\"ALL\"\r");       //List SMS Messages from Preferred Storage
  while(1)  {
    if(mySerial.available())    {
      Serial.write(mySerial.read());  
    }   
  }*/
}

void loop() {
  //mySerial.begin(9600);
  mySerial.write("AT+CMGF=1\r");
  delay(1500);
  mySerial.write("AT+CPMS=\"SM\"\r");         //Preferred SMS Message Storage
  delay(1000);
  mySerial.write("AT+CMGL=\"ALL\"\r");       //List SMS Messages from Preferred Storage
  Serial.println("Checking SMSs...");
  while(1) {
    Serial.println("Inside while-loop...");
    Serial.println(mySerial.isListening());
    Serial.println(mySerial.available());
    if(mySerial.available()) {
      Serial.println("Inside if-loop...");
      Serial.println(mySerial.read());
    }
    delay(3000);
  }
  /*Serial.println("Waiting for SMS");
  mySerial.begin(9600);//setting baudrate at 9600;
  delay(1000);
  mySerial.println("AT+CNMI=2,2,0,0,0");
  //mySerial.println("ATD+917772881269;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
  //Serial.println("Called ATD+917772881269");
  //delay(20000);*/
} //end of void loop  
