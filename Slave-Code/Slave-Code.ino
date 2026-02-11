#include <esp_now.h>
#include <WiFi.h>

const int IN1 = 27; const int IN2 = 26; const int ENA = 14;
const int IN3 = 33; const int IN4 = 32; const int ENB = 25;

void onDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len) {
  uint8_t val = data[0];
  if (val == 1) {
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); analogWrite(ENA, 255);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); analogWrite(ENB, 255);
  } else {
    digitalWrite(ENA, 0); digitalWrite(ENB, 0);
    digitalWrite(IN1, 0); digitalWrite(IN2, 0);
    digitalWrite(IN3, 0); digitalWrite(IN4, 0);
  }
}

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);
  WiFi.disconnect();
  
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);
  
  if (esp_now_init() == ESP_OK) {
    esp_now_register_recv_cb(onDataRecv);
  }
}
void loop() {}