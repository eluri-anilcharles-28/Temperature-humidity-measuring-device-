/*
 * Copyright 2025 Eluri Anil Charles
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
