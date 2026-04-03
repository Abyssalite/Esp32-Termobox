#include <U8g2lib.h>
#include <DHT11.h>      

// OLED constructor
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);

DHT11 dht11(20);

void setup(void) {
  Serial.begin(115200);
  delay(300);
  Serial.println("\nESP32-C3 0.42 OLED + DHT11");

  u8g2.begin();
  u8g2.enableUTF8Print();

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(4, 12);
  u8g2.print("Starting...");
  u8g2.sendBuffer();
}

void loop(void) {
  int t, h = 0;
  int err = dht11.readTemperatureHumidity(t, h);   // reads both at once

  if (err != 0) {
    Serial.print("DHT11 error: ");
    Serial.println(err);
    showError();
    return;
  }

  // Draw on OLED
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_5x8_tf);
  u8g2.setCursor(4, 8);
  u8g2.print("Temp / Humidity");

  u8g2.setFont(u8g2_font_7x14_tf);
  u8g2.setCursor(6, 22);
  u8g2.print(t, 1);
  u8g2.print(" ");
  u8g2.print((char)176);   // ° symbol
  u8g2.print("C");

  u8g2.setCursor(6, 38);
  u8g2.print(h, 1);
  u8g2.print(" %  RH");

  u8g2.sendBuffer();
  delay(1000);
}

void showError() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(4, 16);
  u8g2.print("Sensor Error");
  u8g2.setCursor(4, 30);
  u8g2.print("Check DHT11");
  u8g2.sendBuffer();
}