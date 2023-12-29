#include <Wire.h>
#include <ESP8266WiFi.h>
#include <Adafruit_MLX90614.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>

//WiFi
const char *ssid = "Surya939"; // Enter your WiFi name
const char *password = "Eli2a939";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "CLUSTER";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
uint32_t counter;
char str[80];


// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 column and 2 rows

// MLX90614 sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();


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


void setup() {
 Serial.begin(115200);

 // LCD setup
 lcd.begin(16,2);
 lcd.init();
 lcd.setContrast(3);
 lcd.backlight();
 

 // WiFi setup
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Connecting to WiFi..");
 }
 Serial.println("Connected to the WiFi network");

 // MQTT setup
 client.setServer(mqtt_broker, mqtt_port);
 client.setCallback(callback);
 while (!client.connected()) {
     String client_id = "esp32-client-";
     client_id += String(WiFi.macAddress());
     Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
     if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
         Serial.println("Public emqx mqtt broker connected");
     } else {
         Serial.print("failed with state ");
         Serial.print(client.state());
         delay(2000);
     }
 }
 

// MLX90614 setup
 mlx.begin();
}



void loop() {

 //Client.loop();

 // Read temperature from MLX90614 sensor
 float objectTempC = mlx.readObjectTempC();
 

 // Display temperature on LCD
 lcd.setCursor(0, 0);
 lcd.print("Temp: ");

 lcd.setCursor(0, 1);
 lcd.print(objectTempC);
 lcd.print(" C");


 // Publish temperature to MQTT
 sprintf(str, "%.2f", objectTempC);
 client.publish(topic, str);
 

 delay(1000);
}
