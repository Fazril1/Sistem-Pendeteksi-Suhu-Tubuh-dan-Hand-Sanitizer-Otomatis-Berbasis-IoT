#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = "Ibnu"; // Enter your WiFi name
const char *password = "12345678";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "IR";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

const int irpin = D5;

WiFiClient espClient;
PubSubClient client(espClient);
uint32_t counter;
char str[80];

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message: ");
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void connectToMQTT() {
    while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Public emqx mqtt broker connected");
        } else {
            Serial.print("Failed to connect with state ");
            Serial.print(client.state());
            delay(200);
        }
    }
}

void setup() {
    Serial.begin(115200);
    
    pinMode(irpin, INPUT);

    // WiFi setup
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(200);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");

    // MQTT setup
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    connectToMQTT();

}

void loop() {
    if (!client.connected()) {
        connectToMQTT();  // Reconnect if MQTT connection is lost
    }

    client.loop();

    int nilaiirpin = digitalRead(irpin);

    // Prepare message to publish: "object detected" or "not object detected"
    const char *message = nilaiirpin == HIGH ? "Objek Tidak Terdeteksi" : "Objek Terdeteksi";

    // Publish message to MQTT broker
    client.publish(topic, message);

    delay(200);
}
