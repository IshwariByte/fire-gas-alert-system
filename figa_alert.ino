#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "code1234";
const char* password = "code1234";

// Telegram details
String botToken = "8407961828:AAF3xZpqFgqnIcRibkAqAuPgzVoBL4Dnx8w";
String chatID = "6607156395";

#define flamePin D5
#define gasPin A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  pinMode(flamePin, INPUT);

  lcd.begin();
  lcd.backlight();

  lcd.print("Connecting WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  lcd.clear();
  lcd.print("Connected");
  delay(2000);
}

void loop() {

  int flame = digitalRead(flamePin);
  int gas = analogRead(gasPin);

  lcd.clear();

  if (flame == LOW) {
    lcd.print("FIRE ALERT!");
    sendTelegram("馃敟 Fire Detected!");
    delay(5000);
  }

  else if (gas > 400) {
    lcd.print("GAS LEAK!");
    sendTelegram("鈿狅笍 Gas Leak Detected!");
    delay(5000);
  }

  else {
    lcd.setCursor(0,0);
    lcd.print("SAFE");

    lcd.setCursor(0,1);
    lcd.print("Gas:");
    lcd.print(gas);
  }

  delay(1000);
}

void sendTelegram(String message) {

  WiFiClientSecure client;
  client.setInsecure();

  String url = "https://api.telegram.org/bot" + botToken +
               "/sendMessage?chat_id=" + chatID +
               "&text=" + message;

  HTTPClient https;
  https.begin(client, url);

  int httpCode = https.GET();
  Serial.println(httpCode);

  https.end();
}