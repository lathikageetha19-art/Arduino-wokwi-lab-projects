#include <DHT.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#define DHTPIN 2 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 rtc;
Adafruit_SSD1306 display(128, 64, &Wire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  rtc.begin();
  lcd.begin(20, 4); 
  lcd.backlight();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  DateTime now = rtc.now();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(now.hour(),DEC);
  lcd.print(":");
  lcd.print(now.minute(),DEC);
  lcd.print(":");
  lcd.print(now.second(),DEC);

  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(now.day(),DEC);
  lcd.print("/");
  lcd.print(now.month(),DEC);
  lcd.print("/");
  lcd.print(now.year(),DEC);

  lcd.setCursor(0, 2);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

lcd.setCursor(0, 3);
  lcd.print("Temperature: ");
  lcd.print(temperature);
  lcd.print("C");
delay(500);

}
