#include <Servo.h>

#define led1 3
#define led2 4
#define axe_x A0
#define axe_y A1
#define bx A0
#define by A1
#define ms 2
#define pinsev 5
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(bx, INPUT);
  pinMode(by, INPUT);
  myservo.attach(pinsev);

  myservo.write(45);


  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (analogRead(axe_y) == 1023){
    myservo.write(-90);
    delay(100);
    myservo.write(45);
    }
    
  if (analogRead(by)== 0){
    myservo.write(90);
    delay(100);
    myservo.write(45);
    }

}
