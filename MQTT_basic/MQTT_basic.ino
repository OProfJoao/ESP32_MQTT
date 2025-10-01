#include <WiFi.h>

const String SSID = "iPhone";
const String PSWD = "iot_sul_123";

void connectToWifi();

void setup() {
  Serial.begin(115200);
  connectToWifi();
}

void loop() {
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Conexão perdida!");
    connectToWifi();
  }
}

void connectToWifi(){
  Serial.println("Iniciando conexão com rede WiFi");
  WiFi.begin(SSID,PSWD);
    while(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(200);
    }
    Serial.println("\nConectado!");
}