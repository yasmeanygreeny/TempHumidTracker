#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal.h>

constexpr uint8_t DHT_PIN = 7;
constexpr uint8_t DHT_TYPE = DHT11;

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  dht.begin();

  lcd.print("Starting...");
  delay(2000);
}

void loop() {
  const float humidity = dht.readHumidity();
  const float temperature = dht.readTemperature(true);

  lcd.clear();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor error");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(static_cast<int>(temperature));
    lcd.write(byte(223));  // LCD degree symbol
    lcd.print("F");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(static_cast<int>(humidity));
    lcd.print("%");
  }

  delay(2000);
}