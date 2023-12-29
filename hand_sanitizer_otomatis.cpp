#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = "Surya939";     // Nama WiFi Anda
const char *password = "Eli2a939"; // Kata sandi WiFi Anda

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *mqtt_topic = "AUTO";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

const int irSensorPin = D1; // Pin untuk sensor IR
const int relayPin = D1;    // Pin untuk relay (kontrol water pump)

WiFiClient espClient;
PubSubClient client(espClient);
char message[100];

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.println("Message arrived in topic:");
  Serial.print(topic);
  Serial.println();

  Serial.println("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  Serial.println("-----------------------");
}

void reconnect() {
  // Loop hingga terhubung ke MQTT broker
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    // Buat ID klien unik dari alamat MAC Wemos D1 Mini
    String clientId = "esp8266-";
    clientId += String(WiFi.macAddress());
    
    // Coba menghubungkan
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Connected to MQTT broker");
      
      // Langganan ke topik yang diinginkan
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" - Retry in 5 seconds");
      
      // Tunggu 5 detik sebelum mencoba kembali
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(irSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Mulai koneksi WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Tentukan server MQTT dan callback
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  // Membaca nilai sensor IR
  int irValue = digitalRead(irSensorPin);

  // Jika sensor IR mendeteksi tangan
  if (irValue == LOW) {
    // Mengaktifkan relay untuk menyalakan water pump
    digitalWrite(relayPin, HIGH);

    // Mengirim pesan ke broker MQTT
    snprintf(message, sizeof(message), "Hand Sanitizer Activated");
    client.publish(mqtt_topic, message);

    delay(5000); // Menunggu sebentar sebelum mematikan relay

    // Mematikan relay untuk mematikan water pump
    digitalWrite(relayPin, LOW);
  }

  // Periksa koneksi ke broker MQTT
  if (!client.connected()) {
    reconnect();
  }

  // Handle callback MQTT jika ada
  client.loop();

  delay(1000); // Menunda sebentar sebelum membaca sensor lagi
}
