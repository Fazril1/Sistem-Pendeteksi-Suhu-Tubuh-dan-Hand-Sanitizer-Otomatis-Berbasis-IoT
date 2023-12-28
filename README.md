# **Sistem-Pendeteksi-Suhu-Tubuh-dan-Hand-Sanitizer-Otomatis-Berbasis-IoT**

Project ini untuk memenuhi tugas akhir mata kuliah IoT

Anggota kelompok Kaget: Ibnu Fazril, Muhammad Sadam Erlangga, Gilman Muslih, Wildan Budi

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

*kabel jumper sudah dihubungkan pada komponen-komponen yang digunakan

# **Setup pada Komputer**

Hal pertama yang dilakukan yaitu menginstall vscode di link berikut https://code.visualstudio.com/ lalu menginstall ekstensi platfrom io yang berada di dalam vscode lalu bisa tambahin project dengan menulis nama project, board arduino yang dipakai. Setelah itu bisa menginstall library yang dibutuhkan yang pertama bisa menginstall library pubsubclient berfungsi untuk berkomunikasi dengan MQTT, yang kedua yaitulibrary adafruit dengan link https://github.com/adafruit/Adafruit-MLX90614-Library dan menginstall library lcd I2C dengan link https://github.com/johnrickman/LiquidCrystal_I2C (folder ekstrak zip ditempatkan dalam lib dalam folder project platform io) dan jika sudah maka bisa menginstall node js untuk membuat dashboard yang terintegrasi dengan broker dan komponen yang dipasang ke laptop dengan link https://nodejs.org/en/, dan juga tidak lupa untuk melihat port berapa arduino itu terdeteksi di laptop dengan membuka cmd dan mengetik mode dan lihat com berapa yang ditampilkan.

note: library adafruit dan liquidcrystal kami coba tidak bisa menginstall secara langsung di terminal dan harus mengunduh zip nya menggunakan perintah pio lib --global install <library name>.

# **Menyatukan komponen**

# **Platform yang Digunakan**

# **Kode**

# **Mengirim Data/Konektivitas**

# **Menampilkan Data**

# **Finalisasi**
**asd**
