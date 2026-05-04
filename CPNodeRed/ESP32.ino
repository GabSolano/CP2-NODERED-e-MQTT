#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"


const char* ssid = "SEU_WIFI_AQUI";
const char* password = "SUA_SENHA_AQUI";


const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;


const char* topico_temp = "estufa1/temperatura";
const char* topico_umid = "estufa1/umidade";
const char* topico_lumi = "estufa1/luminosidade";


#define DHTPIN 4
#define DHTTYPE DHT11
#define LDRPIN 34
DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    String clientId = "ESP32Client-Estufa-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Conectado ao broker!");
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  
  static unsigned long lastMsg = 0;
  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    float t = dht.readTemperature();
    float h = dht.readHumidity();
    int ldr_valor = analogRead(LDRPIN);

    if (!isnan(t) && !isnan(h)) {
      client.publish(topico_temp, String(t).c_str());
      client.publish(topico_umid, String(h).c_str());
      Serial.print("Temperatura: "); Serial.println(t);
    }
    
    client.publish(topico_lumi, String(ldr_valor).c_str());
    Serial.print("Luminosidade: "); Serial.println(ldr_valor);
  }
}