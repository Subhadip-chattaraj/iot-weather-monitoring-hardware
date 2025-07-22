# 🌦️ IoT-Based Weather Monitoring System (Hardware Only)

This project is a hardware-only IoT-based weather monitoring system using an ESP32 microcontroller and various environmental sensors. It displays real-time weather parameters on a 16x2 LCD via I2C.

---

## 🔧 Components Used

| Component                       | Purpose                                  |
|--------------------------------|------------------------------------------|
| **ESP32**                      | Main microcontroller for data processing |
| **DHT11**                      | Temperature and humidity sensor          |
| **BMP280**                     | Barometric pressure & altitude sensor    |
| **Rain Sensor**                | Detects rainfall                         |
| **LDR (Light Dependent Resistor)** | Measures ambient light intensity   |
| **16x2 LCD with I2C Module**   | Displays sensor data in real-time        |
| **12V Adapter**                | Powers the system                        |
| **7805 Voltage Regulator**     | Converts 12V to 5V stable output         |

---

## ⚙️ Working Principle

- Sensors are connected to the ESP32 which continuously reads:
  - Temperature & Humidity from DHT11
  - Pressure & Altitude from BMP280
  - Light intensity from LDR
  - Rain status from rain sensor
- The data is processed and shown on a 16x2 LCD using the I2C interface.
- A 12V adapter powers the system, regulated to 5V using the 7805 voltage regulator.

---

## 🧪 Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/Subhadip-chattaraj/iot-weather-monitoring-hardware.git
