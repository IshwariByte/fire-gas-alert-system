# 🔥 Fire & Gas Alert System (ESP8266)

 About the Project

This project is a **Fire and Gas Alert System** built using NodeMCU (ESP8266).
It detects **fire and gas leakage** and sends alerts using **Telegram**, while also displaying the status on an LCD.

---
Purpose

This system is designed to improve safety in homes, labs, and industries by giving **instant alerts** when fire or gas is detected.

---

 ⚙️ How It Works

* The **flame sensor** detects fire
* The **gas sensor** detects gas leakage
* ESP8266 reads sensor values continuously
* If danger is detected:

  * Message is sent to Telegram 📲
  * Alert is shown on LCD

---

 Components Used

* ESP8266 (NodeMCU)
* Flame Sensor
* Gas Sensor (MQ series)
* 16x2 LCD (I2C)
* Jumper wires
* Power supply

---

 Connections

* Flame Sensor → D5
* Gas Sensor → A0
* LCD SDA → D2
* LCD SCL → D1

 Features

* Real-time monitoring
* Telegram alert system
* LCD display output
* Easy to build and low cost

---

 How to Run

1. Upload code using Arduino IDE
2. Enter your WiFi name and password
3. Add your Telegram Bot Token and Chat ID
4. Power the ESP8266

---

 Output

* SAFE condition shown on LCD
* Gas value displayed
* Alerts:

  * 🔥 Fire Detected
  * ⚠️ Gas Leak Detected

---

 Future Improvements

* Add buzzer alarm
* Add mobile app control
* Automatic gas shut-off using relay

---

Author
Ishwari And Mushraf

