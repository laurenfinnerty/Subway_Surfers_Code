
int buttonVal;
const int buttonPin = 9;
const int switchPin = 8;
bool isRight = true;
#include <Servo.h>
Servo myservo2;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);
  myservo.attach(10);
  myservo2.attach(11);
  myservo.write(0);
  myservo2.write(0);

}

void loop() {
  buttonVal = digitalRead(buttonPin);
  if(digitalRead(switchPin) == HIGH){
      myservo2.write(180);
  }
  Serial.println(switchPin);

  
  if(buttonVal == HIGH && isRight){
    myservo.write(180);
    isRight = false;
    delay(1000);
  }
  else if(buttonVal == HIGH && !isRight){
    myservo.write(0);
    isRight = true;
    delay(1000);
  }
  
  

}
