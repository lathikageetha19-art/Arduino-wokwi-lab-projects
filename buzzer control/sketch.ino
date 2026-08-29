int buzzer=2;
void setup()
{
  pinMode(buzzer,OUTPUT);
}
void loop()
{
  tone(buzzer,200);
  delay(2000);
  tone(buzzer,250);
  delay(2000);
}