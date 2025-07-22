#define BLYNK_TEMPLATE_ID "TMPL31WnRgX7v"
#define BLYNK_TEMPLATE_NAME "Weather monitering system"
#define BLYNK_AUTH_TOKEN "DAu_xNq0PH_j4Vv6VuERcGnmv4PMD_dh"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Sensor Pins
#define DHTPIN 5
#define DHTTYPE DHT11
#define RAINPIN 36
#define LDRPIN 4

// WiFi Credentials
char ssid[] = "Hum wifi nehi denge 4";
char pass[] = "betapassword123hai";

// Initialize LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT Sensor
DHT dht(DHTPIN, DHTTYPE);

// Blynk Timer
BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();

  dht.begin();
  pinMode(RAINPIN, INPUT);
  pinMode(LDRPIN, INPUT);
  analogReadResolution(12);  // ESP32: 0–4095 range

  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  lcd.clear();
  lcd.print("WiFi Connected!");
  delay(1000);
  
  lcd.clear();
  lcd.print("Connecting Blynk");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Timers
  timer.setInterval(2000L, sendToBlynk);
}
void sendToBlynk() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int rain = analogRead(RAINPIN);
  int light = digitalRead(LDRPIN);

  int rainPercent = map(rain, 0, 4095, 100, 0);

  // Send to Blynk
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
  Blynk.virtualWrite(V2, rainPercent);
  Blynk.virtualWrite(V3, light == LOW ? 1 : 0); // 1 = Light, 0 = Dark

  // Show on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C H:");
  lcd.print(hum);
  lcd.setCursor(0, 1);
  lcd.print("Rain:");
  lcd.print(rainPercent);
  lcd.print("% ");
  lcd.print(light == LOW ? "Light" : "Dark");
}
void loop() {
  Blynk.run();
  timer.run();
}
