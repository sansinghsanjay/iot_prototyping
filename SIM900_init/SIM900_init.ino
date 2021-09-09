
#include <SoftwareSerial.h>

SoftwareSerial SIM900(7, 8);

void setup() {
  // put your setup code here, to run once:
  SIM900.begin(19200);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
