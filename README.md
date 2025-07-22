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

🌐 Applications of IoT-Based Weather Monitoring System
🌾 Agriculture Monitoring: Helps farmers monitor real-time environmental conditions to improve crop yield and irrigation scheduling.

🏠 Home Weather Station: Allows individuals to track local weather from their home using a low-cost and reliable setup.

⚠️ Disaster Preparedness: Provides early warnings for rainfall, pressure drops, and temperature spikes that may signal floods or storms.

🔬 Environmental Research: Useful for researchers collecting long-term weather and climate data in remote or experimental locations.

🏙️ Smart City Infrastructure: Enables integration into urban IoT networks for city-level data collection and analysis, aiding traffic, pollution, and emergency services.

---

## 🧪 Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/Subhadip-chattaraj/iot-weather-monitoring-hardware.git
