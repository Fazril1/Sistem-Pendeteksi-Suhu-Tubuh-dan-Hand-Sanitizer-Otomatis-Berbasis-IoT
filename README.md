# **Sistem Pendeteksi Suhu Tubuh dan Hand Sanitizer Otomatis Berbasis IoT**

Project ini untuk memenuhi tugas akhir mata kuliah IoT

Anggota kelompok Kaget: Ibnu Fazril, Muhammad Sadam Erlangga, Gilman Muslih, Wildan Budi Anggara

# **Gambaran Umum Proyek Tugas Besar**

Proyek ini bertujuan untuk membuat perangkat iot sederhana dengan 2 sensor, dengan sensor pertama yaitu Sensor Suhu MLX90614 yang digunakan untuk mendeteksi suhu tubuh untuk mengetahui apakah pengguna sedang sakit atau tidak dan sensor yang kedua yaitu sensor Infra Red yang digunakan dalam sistem Hand Sanitizer otomatis dengan tujuan untuk langkah awal pencegahan ketika sedang sakit.

**Perkiraan waktu pengerjaan tugas:**

1 bulan atau lebih

# **Tujuan**
**Alasan mengapa memilih proyek ini untuk memenuhi penilaian tugas besar:**
Proyek ini dibuat untuk meningkatkan keamanan dan kesehatan di sekitar. Lingkungan sekitar kita sering kali menjadi tempat penyebaran penyakit menular, terutama di era ini di mana wabah global menjadi perhatian utama.

**Tujuan dari proyek ini:**
Selain untuk memenuhi kebutuhan penilaian tugas besar mata kuliah Internet of Things, kami juga ingin mengetahui cara membuat perangkat IoT dan menghubungkannya ke internet untuk memvisualisasikan datanya di platform berbasis online. Kemudian, tujuan dari dibuatnya proyek ini untuk mengetahui keamanan dan kesehatan di lingkungan sekitar dengan cara mendapatkan informasi mengenai suhu rata-rata orang-orang di lingkungan sekitar dan memberikan langkah awal pencegahan terhadap penyakit-penyakit menyebar yang berbahaya secara otomatis.

**Insight yang diperoleh dengan mengerjakan proyek ini:**
Proyek ini mampu memberikan wawasan tentang konsep dasar IoT, pemrograman, dan rangkaian listrik.

# **Alat dan Bahan yang Digunakan**

| Komponen | Deskripsi | Tempat Membeli | Harga |
| --- | --- | --- | --- |
| Sensor Suhu MLX90614 | Sensor yang digunakan untuk mendeteksi suhu tubuh | shopee.co.id | Rp130.000 |
| Wemos D1 Mini | Mikrokontroler yang digunakan untuk menghubungkan dan mengontrol berbagai sensor dan perangkat eksternal serta memungkinkan untuk koneksi ke jaringan dan komunikasi nirkabel dengan perangkat lain | shopee.co.id | Rp26.900 |
| LCD 1602 I2C | Perangkat yang digunakan untuk menampilkan hasil pembacaan sensor suhu | shopee.co.id | Rp23.000 |
| Breadboard | Media yang digunakan untuk memasang komponen-komponen seperti Wemos D1 Mini, LCD, sensor atau komponen-komponen lain lalu dihubungkan menggunakan kabel jumper | shopee.co.id | Rp8.300 |
| 40 kabel jumper male/female | Digunakan untuk menghubungkan komponen-komponen seperti Wemos D1 Mini, LCD, sensor atau komponen-komponen lain yang memiliki pin female/male | shopee.co.id | Rp9.500 |
| 40 kabel jumper male/male | Digunakan untuk menghubungkan komponen-komponen seperti Wemos D1 Mini, LCD, sensor atau komponen-komponen lain yang memiliki pin female/female | shopee.co.id | Rp9.500 |
| 40 kabel jumper female/female | Digunakan untuk menghubungkan komponen-komponen seperti Wemos D1 Mini, LCD, sensor atau komponen-komponen lain yang memiliki pin male/male | shopee.co.id | Rp9.500 |
| Sensor Infra Red | Sensor yang digunakan untuk mendeteksi objek (tangan pengguna hand sanitizer) | shopee.co.id | Rp5.000 |
| Water pump | Aktuator yang digunakan untuk mengalirkan cairan hand sanitizer ke tangan pengguna | shopee.co.id | Rp11.500 |
| Kabel usb micro b | Digunakan untuk menghubungkan Wemos D1 Mini ke Laptop/PC | Sudah tersedia | Sudah tersedia |

![WhatsApp Image 2023-12-28 at 17 02 43_adca8301](https://github.com/Codeginner/Sistem-Pendeteksi-Suhu-Tubuh-dan-Hand-Sanitizer-Otomatis-Berbasis-IoT/assets/91475506/5c96edcf-5c2b-4264-b762-1ff3e127e722)

Gambar 1: Komponen-komponen yang digunakan dalam rangkaian **pendeteksi suhu tubuh**

(dari kiri ke kanan)

1. Breadboard
2. Sensor Suhu MLX90614
3. Wemos D1 Mini
4. LCD 1602 I2C
5. USB micro B

note: kabel jumper sudah dihubungkan pada komponen-komponen yang digunakan

# **Setup pada Komputer**

Hal pertama yang dilakukan yaitu menginstall vscode di link berikut https://code.visualstudio.com/ lalu menginstall ekstensi platfrom io yang berada di dalam vscode lalu bisa tambahin project dengan menulis nama project, board arduino yang dipakai. Setelah itu bisa menginstall library yang dibutuhkan yang pertama bisa menginstall library pubsubclient berfungsi untuk berkomunikasi dengan MQTT, yang kedua yaitulibrary adafruit dengan link https://github.com/adafruit/Adafruit-MLX90614-Library dan menginstall library lcd I2C dengan link https://github.com/johnrickman/LiquidCrystal_I2C (folder ekstrak zip ditempatkan dalam lib dalam folder project platform io) dan jika sudah maka bisa menginstall node js untuk membuat dashboard yang terintegrasi dengan broker dan komponen yang dipasang ke laptop dengan link https://nodejs.org/en/, dan juga tidak lupa untuk melihat port berapa arduino itu terdeteksi di laptop dengan membuka cmd dan mengetik mode dan lihat com berapa yang ditampilkan.

note: library adafruit dan liquidcrystal kami coba tidak bisa menginstall secara langsung di terminal dan harus mengunduh zip nya menggunakan perintah pio lib --global install <library name>.

# **Menyatukan komponen**

Setelah melakukan setup pada komputer, selanjutnya menyatukan komponen-komponen yang diperlukan dalam membuat pendeteksi suhu tubuh

![WhatsApp Image 2023-12-28 at 19 35 33_09968c19](https://github.com/Codeginner/Sistem-Pendeteksi-Suhu-Tubuh-dan-Hand-Sanitizer-Otomatis-Berbasis-IoT/assets/91475506/739e0ef9-b12f-4112-89a3-c6f78b0c6a2c)

Gambar 2: menyatukan komponen


# **Platform yang Digunakan**

Platform yang digunakan untuk menampilkan visualisasi data secara real-time adalah Node-RED Dashboard. Node-RED adalah alat pemrograman untuk menghubungkan perangkat keras, API, dan layanan online dengan cara yang baru dan menarik. Alat ini menyediakan editor berbasis browser yang memudahkan untuk menyambungkan serangkaian node yang diatur dalam editor berbasis browser untuk membentuk suatu logika atau proses tertentu menggunakan berbagai macam node dalam palet yang dapat digunakan pada saat runtime.

![WhatsApp Image 2023-12-28 at 19 00 31_10bcd6ab](https://github.com/Codeginner/Sistem-Pendeteksi-Suhu-Tubuh-dan-Hand-Sanitizer-Otomatis-Berbasis-IoT/assets/91475506/754f51e8-0c95-4e42-af81-72b4ea739fd7)

Gambar 3: Tampilan dashboard Node-RED

# **Kode**

## **Kode untuk pendeteksi suhu tubuh**

**Bagian pertama: library**

#include <Wire.h>

#include <ESP8266WiFi.h>

#include <Adafruit_MLX90614.h>

#include <PubSubClient.h>

#include <SPI.h>

#include <LiquidCrystal_I2C.h>

Penjelasan bagian pertama kode: Library-library yang diperlukan dalam membuat sistem pendeteksi tubuh, yaitu Wire.h untuk komunikasi I2C, ESP8266WiFi dukungan WiFi untuk ESP8266, Adafruit_MLX90614 untuk berkomunikasi dengan sensor suhu MLX90614, PubSubClient untuk komunikasi MQTT, SPI Interface Periferal Serial untuk berkomunikasi dengan perangkat SPI, dan LiquidCrystal_I2C untuk berkomunikasi dengan LCD I2C.

**Bagian kedua: Konfigurasi WiFi dan MQTT**

//WiFi

const char *ssid = "Surya939"; // Enter your WiFi name

const char *password = "Eli2a939";  // Enter WiFi password


// MQTT Broker

const char *mqtt_broker = "broker.emqx.io";

const char *topic = "CLUSTER";

const char *mqtt_username = "emqx";

const char *mqtt_password = "public";

const int mqtt_port = 1883;

Penjelasan bagian kedua kode: Menetapkan kredensial Wi-Fi (ssid dan password) dan detail broker MQTT (mqtt_broker, mqtt_port, mqtt_username, mqtt_password, dan topic).

**Bagian ketiga kode: Inisialisasi WiFi, MQTT, dan LCD**

WiFiClient espClient;

PubSubClient client(espClient);

uint32_t counter;

char str[80];

Penjelasan bagian ketiga kode: Buat _instance_ untuk WiFi, MQTT, dan LCD I2C.

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 column and 2 rows

// MLX90614 sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

**Bagian kelima kode: Fungsi Callback MQTT**

void callback(char *topic, byte *payload, unsigned int length) 
{

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

# **Mengirim Data/Konektivitas**

# **Menampilkan Data**

# **Finalisasi**
**asd assddsdsd**
{

    asd
    sdsd
    sdsd

}
