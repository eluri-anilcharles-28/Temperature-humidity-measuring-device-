# Temperature-humidity-measuring-device-
// By using arduino uno r3 , JHD 162A lcd display and DHT11 sensor i built a temperature and humidity measuring  device 
// By E.ANIL CHARLES

#include<LiquidCrystal_I2C.h>
#include<DHT.h>

#define DHT_PIN 2
#define DHTTYPE DHT11

DHT dht(DHT_PIN,DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);

  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("DHT IS READY!");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("INITIALIZING...");
  delay(2000);

  lcd.clear();
  lcd.print("READING....");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000);
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
  } else 
  {
   lcd.setCursor(0, 0);
   lcd.print("HUMIDITY: ");
   lcd.print(h, 1);
   lcd.print(" %");
   lcd.setCursor(0, 1);
   lcd.print("TEMP: ");
   lcd.print(t, 1);
   lcd.print(" C");
   delay(10000);
   lcd.clear();
  }
} 



