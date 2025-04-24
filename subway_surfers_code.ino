
//Lauren Finnerty and Caden Clack
//Team Boston Tea
// Uses 4 servos to move the train, the character, a wall, and a barricade. Character servo is tracked
// by a button to simulate the actual game experience. 




int buttonVal;
int numPresses = 0;
int trainTimer = 0;
const int buttonPin = 6;
const int switchPin = 7;
const int ledPin = 5;
int i = 0;
bool isRight = true;
bool isRight2 = true;
#include <Servo.h>
Servo myservo2;
Servo myservo;
Servo myservo3; 
Servo myservo4;
void setup() {
  
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(10);
  myservo2.attach(11);
  myservo3.attach(12);
  myservo4.attach(13);
  myservo4.write(180);
  delay(3000);
  myservo.write(180);
  myservo2.write(180);
  myservo3.write(90);
  myservo4.write(180);
  Serial.begin(9600);

}

void loop() {
  buttonVal = digitalRead(buttonPin);
  

  //SWITCH - start of game, wall flips.
  if (digitalRead(switchPin) == HIGH){
    myservo2.write(0);
  } 
  
    
  
  //BUTTON - switches Tricky from left to right track and vice versa
  if(buttonVal == HIGH && isRight){
    if(numPresses == 0){
      myservo.write(0);
    }
    else if(numPresses == 2){
      myservo.write(0);
      delay(500);
      myservo4.write(0);
      myservo2.write(180);
    }
    isRight = false;
    numPresses += 1;
    
    delay(2000);
    
  }
  else if(buttonVal == HIGH && !isRight){
    if(numPresses == 1){
      myservo.write(180);
      
    }
    isRight = true;
    numPresses += 1; 

    
    delay(2000);

  }

// Tracks how many times the button has been pressed and moves objects accordingly.
  if(numPresses == 1 && trainTimer <= 600){
    myservo3.write(83);
    trainTimer += 1;
    Serial.println("a");
  }
  else if(numPresses == 2 && trainTimer <= 3100){
    myservo3.write(83);
    trainTimer += 1;
    Serial.println("b");
  }
  else{
    myservo3.write(90);
    //Serial.println("C");
  }
  
    
  
  

}
