#include <WiFi.h>
#include <PubSubClient.h>

const String SSID = "iPhone";
const String PSWD = "iot_sul_123";

const String brokerUrl = "test.mosquitto.org";  //URL do broker   (servidor)
const int port = 1883;                          //Porta do Broker (servidor)

WiFiClient espClient;                           //Criando Cliente WiFi
PubSubClient mqttClient(espClient);             //Criando Cliente MQTT

void connectToWifi();

void setup() {
  Serial.begin(115200);
  connectToWifi();
  Serial.println("Conectando ao broker...");
  mqttClient.setServer(brokerUrl.c_str(),port);
  String userId = "ESP-JOAO";
  userId += String(random(0xffff), HEX);
  mqttClient.connect(userId.c_str());
  while(!mqttClient.connected()){
    Serial.println("Erro de conexão");
    delay(500);
  }
  Serial.println("Conectado com sucesso!");
}

void loop() {
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Conexão perdida!");
    connectToWifi();
  }
  mqttClient.loop();
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