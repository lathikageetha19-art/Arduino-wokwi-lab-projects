int Sw1=4;
int Sw2=5;
int LED=8;
int Buzz=7;
void setup()
{
  pinMode(Buzz, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(Sw1, INPUT_PULLUP);
  pinMode(Sw2, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop()
{
  int S_1,S_2;
  S_1=digitalRead(Sw1);
  S_2=digitalRead(Sw2);
  if(S_1==LOW)
  {
    tone(Buzz,262,250);
    digitalWrite(LED,HIGH);
    Serial.println("Switch 1 is pressed");
  }
  else
  {
    digitalWrite(LED,LOW);
    Serial.println("Switch 1 is not pressed");
  }
   if(S_2==LOW)
  {
    tone(Buzz,262,250);
    Serial.println("Switch 1 is pressed");
    delay(250);
  }
  else
  {
    noTone(Buzz);
    Serial.println("Switch 2 is not pressed");
  } 
    delay(1000);
}