
int buttonVal;

const int buttonPin = 2;
const int switchPin = 7;
const int ledPin = 5;
bool isRight = true;
bool isRight2 = true;
#include <Servo.h>
Servo myservo2;
Servo myservo;
Servo myservo3; 

// Comment for test merge 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(10);
  myservo2.attach(11);
  myservo3.attach(12);
  myservo.write(0);
  myservo2.write(0);
  //myservo3.write(0);


}

void loop() {
  
  if(digitalRead(switchPin) == HIGH){
    myservo2.write(180);
    
    
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  Serial.println();

  if (digitalRead(switchPin) == HIGH){
    myservo2.write(180);
  } 
  

  
    if(digitalRead(buttonPin) == HIGH){
      Serial.println("Ddwdw");
    }

  
  

}
