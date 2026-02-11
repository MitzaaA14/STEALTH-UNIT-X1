#include <esp_now.h>
#include <WiFi.h>
#include <WebServer.h>

uint8_t slaveAddress[] = {0x3C, 0x8A, 0x1F, 0x0C, 0x29, 0xA8}; 

const int m1P1 = 27; const int m1P2 = 26; const int en1 = 14;
const int m2P1 = 33; const int m2P2 = 32; const int en2 = 25;

const int servoPin = 18;

const int PWM_FREQ = 1000;
const int PWM_RES = 8;
const int SERVO_FREQ = 50;
const int SERVO_RES = 16;

int vStanga = 150;  
int vDreapta = 255;

bool pozitie90 = false;

WebServer server(80);

void controlMers(int s1, int s2, int s3, int s4, int vitS, int vitD) {
  digitalWrite(m1P1, s1);
  digitalWrite(m1P2, s2);
  digitalWrite(m2P1, s3);
  digitalWrite(m2P2, s4);
  ledcWrite(en1, vitS);
  ledcWrite(en2, vitD);
}

void setServo(int unghi) {
  int duty = map(unghi, 0, 180, 1638, 8192);
  ledcWrite(servoPin, duty);
}

const char* html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name='viewport' content='width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=0'>
  <style>
    body { background: #0a0a0a; color: #00ffcc; font-family: sans-serif; text-align: center; margin: 0; }
    .header { padding: 15px; font-size: 22px; text-shadow: 0 0 10px #00ffcc; font-weight: bold; }
    .grid { display: grid; grid-template-columns: repeat(3, 85px); gap: 10px; justify-content: center; margin-top: 15px; }
    .btn { width: 85px; height: 85px; background: #1a1a1a; border: 2px solid #00ffcc; border-radius: 15px; color: #00ffcc; font-size: 25px; touch-action: none; }
    .btn:active { background: #00ffcc; color: #000; }
    .l-btn { width: 85%; height: 50px; margin-top: 15px; border-radius: 10px; border: none; font-weight: bold; color: white; font-size: 16px; cursor: pointer; }
    .fire-btn { background: #ff0044; box-shadow: 0 0 10px #ff0044; }
    .servo-btn { background: #ff9900; box-shadow: 0 0 10px #ff9900; }
    .off-btn { background: #444; margin-top: 10px; }
  </style>
</head>
<body>
  <div class='header'>STEALTH UNIT X1</div>
  
  <div class='grid'>
    <div style='grid-column: 2;'><button class='btn' ontouchstart="f('/up')" ontouchend="f('/stop')">Front</button></div>
    <button class='btn' ontouchstart="f('/left')" ontouchend="f('/stop')">Left</button>
    <div></div>
    <button class='btn' ontouchstart="f('/right')" ontouchend="f('/stop')">Right</button>
    <div style='grid-column: 2;'><button class='btn' ontouchstart="f('/down')" ontouchend="f('/stop')">Down</button></div>
  </div>
  
  <button class='l-btn fire-btn' onclick="f('/fire')">ENGAGE CANNON</button>
  <button class='l-btn servo-btn' onclick="f('/servo')">TOGGLE SERVO (90&deg;)</button>
  <button class='l-btn off-btn' onclick="f('/off')">DISARM / STOP FIRE</button>
  
  <script> function f(u) { fetch(u); } </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  
  pinMode(m1P1, OUTPUT); pinMode(m1P2, OUTPUT);
  pinMode(m2P1, OUTPUT); pinMode(m2P2, OUTPUT);
  ledcAttach(en1, PWM_FREQ, PWM_RES);
  ledcAttach(en2, PWM_FREQ, PWM_RES);
  
  ledcAttach(servoPin, SERVO_FREQ, SERVO_RES);
  setServo(0);

  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("STEALTH_UNIT_X1", "12345678", 1);
  
  if (esp_now_init() == ESP_OK) {
    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, slaveAddress, 6);
    peerInfo.channel = 1;
    peerInfo.encrypt = false;
    esp_now_add_peer(&peerInfo);
  }

  server.on("/", []() { server.send(200, "text/html", html); });
  server.on("/up", []() { controlMers(LOW, HIGH, HIGH, LOW, 255, 180); server.send(204); });
  server.on("/down", []() { controlMers(HIGH, LOW, LOW, HIGH, 255, 210); server.send(204); });
  server.on("/left", []() { controlMers(LOW, HIGH, LOW, HIGH, 200, 200); server.send(204); });
  server.on("/right", []() { controlMers(HIGH, LOW, HIGH, LOW, 200, 200); server.send(204); });
  server.on("/stop", []() { controlMers(0, 0, 0, 0, 0, 0); server.send(204); });
  
  server.on("/servo", []() { 
    pozitie90 = !pozitie90;
    setServo(pozitie90 ? 90 : 0);
    server.send(204); 
  });

  server.on("/fire", []() { 
    uint8_t v = 1; 
    esp_now_send(slaveAddress, &v, 1); 
    server.send(204); 
  });

  server.on("/off", []() { 
    uint8_t v = 0; 
    esp_now_send(slaveAddress, &v, 1); 
    server.send(204); 
  });

  server.begin();
  Serial.println("Sistem pornit!");
}

void loop() { server.handleClient(); }