#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 13
#define BUZZER_PIN 8

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  //Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Obstacle Detect!");
}

void loop()
{
  long duration;
  int distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration=pulseIn(ECHO_PIN,HIGH);
  distance=duration*0.034/2;
  lcd.setCursor(0,1);
  lcd.print("Distance");
  lcd.print(distance);
  lcd.print(" cm ");
  
  if (distance < 40)
  {
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    tone(BUZZER_PIN,1000);
  }

  else{
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    noTone(BUZZER_PIN);
  }
  
  delay(500);
}