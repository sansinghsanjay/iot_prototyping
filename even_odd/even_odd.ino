
long randNumber;
int result;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  randNumber = random(300);
  if(randNumber % 2 == 0)
    result = 1;
  else
    result = 0;
  Serial.println(randNumber);
  if(result)
    Serial.println("Even");
  else
    Serial.println("Odd");
  delay(5000);
}
