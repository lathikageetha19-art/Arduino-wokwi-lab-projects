#include <Servo.h>

Servo myServo;

const int relayPin = 7;       
const int servoPin = 9;       
const int buttonPin = 8;      

int currentAngle = 0;        
bool pressed = false;         
bool lastButtonState = HIGH;  

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  myServo.attach(servoPin);
  myServo.write(currentAngle);
  digitalWrite(relayPin, LOW);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
  
    digitalWrite(relayPin, HIGH);

    currentAngle += 30;

    if (currentAngle > 180)
    {
      currentAngle = 0; 
    }

    myServo.write(currentAngle);  
    delay(300);  
  }

  digitalWrite(relayPin, LOW);

  lastButtonState = buttonState;

  delay(100); 
}