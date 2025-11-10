# 01 — Dual Core Stepper Control + Mutex (ESP32-S3)

## Description / Deskripsi

Eksperimen ini menunjukkan eksekusi dua task paralel pada dua core ESP32-S3 yang sama-sama mengontrol stepper motor, namun tetap stabil menggunakan mekanisme Mutex di FreeRTOS agar tidak terjadi data racing pada arah putaran (DIR pin).

- BTN_RIGHT → menjalankan perintah putar kanan pada **Core 0**
- BTN_LEFT → menjalankan perintah putar kiri pada **Core 1**

Tujuan utama: membuktikan bahwa dua core dapat mengakses hardware yang sama secara aman tanpa jitter / konflik arah.

## Hardware Mapping

| Device | Pin | Mode / Core |
|--------|-----|-------------|
| STEP Motor | GPIO 6 | Output Step |
| DIR Motor  | GPIO 7 | Output Direction |
| Button Right | GPIO 13 | Input Pullup → Task di Core 0 |
| Button Left  | GPIO 12 | Input Pullup → Task di Core 1 |


## Test Procedure / Langkah Percobaan

| No | Langkah | Hasil yang Diharapkan |
|----|---------|-----------------------|
| 1 | Upload program ke Wokwi | Tidak error, Serial Monitor mulai berjalan |
| 2 | Tekan BTN_RIGHT (klik tombol) | Serial menampilkan: **"Stepper Kanan - Core 0"** |
| 3 | Tekan BTN_LEFT | Serial menampilkan: **"Stepper Kiri - Core 1"** |
| 4 | Perhatikan log core | Baris log menunjukkan perbedaan Core 0 dan Core 1 |
| 5 | Tekan kedua tombol bergantian | Log tetap teratur, tidak tabrakan mutex (arah tetap benar) |


## Evidence / Catatan Bukti

### Core 0 Berjalan
<img width="1024" height="755" alt="Screenshot 2025-11-10 181022" src="https://github.com/user-attachments/assets/b1bc5c44-a813-4ca1-80e7-0e7184ca0e60" />


### Core 1 Berjalan
<img width="1028" height="737" alt="Screenshot 2025-11-10 181039" src="https://github.com/user-attachments/assets/b2893e12-f64c-4f85-9582-6620a7b345bb" />



## Video Evidence
Google Drive:https://drive.google.com/file/d/1XfipWjuTFF7m_CiqFttfeVyyAULJF5o0/view?usp=sharing  

