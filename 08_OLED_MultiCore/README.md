# 08 — Multi-Core OLED Swap + Button Input (ESP32-S3)

## Description / Deskripsi

Eksperimen ini mendemonstrasikan penggunaan FreeRTOS pada ESP32-S3 untuk menjalankan dua task di dua core berbeda:

- **TaskButton (Core 0)** → membaca dua tombol, mendeteksi tombol terakhir yang ditekan, dan mendeteksi long-press kedua tombol untuk memicu perpindahan core.  
- **TaskOLED (Core 1 / Core 0)** → menampilkan status tombol dan core aktif di OLED, serta dapat berpindah core saat runtime.

Tujuan utama: membuktikan bahwa sebuah task OLED dapat dihentikan dan dibuat ulang pada **core berbeda secara aman**, menggunakan mutex + semaphore tanpa menyebabkan glitch pada layar.

## Hardware Mapping

| Device          | Pin | Mode                  |
|-----------------|-----|-----------------------|
| Button 1        | 13  | Input Pull-up         |
| Button 2        | 12  | Input Pull-up         |
| OLED SDA        | 8   | I2C SDA               |
| OLED SCL        | 9   | I2C SCL               |
| TaskButton      | —   | Task Core 0           |
| TaskOLED        | —   | Task Core 1 / Core 0  |

## Test Procedure / Langkah Percobaan

| No | Step | Expected Result |
|----|------|-----------------|
| 1  | Upload program | Serial Monitor menampilkan “OLED task created on core X” |
| 2  | Tekan Button 1 | OLED menampilkan teks “Button 1” |
| 3  | Tekan Button 2 | OLED menampilkan teks “Button 2” |
| 4  | Tekan kedua tombol >1 detik | OLED berpindah dari Core 0 → 1 atau 1 → 0 |
| 5  | Observasi Log Serial | Muncul log: “OLED exited cleanly” dan “OLED recreated on core X” |
| 6  | Validasi Multi-Core | OLED menampilkan: “OLED pinned core: X” |

## Image Evidence

### 1. OLED Berjalan pada Core 1  
<img width="1012" height="622" alt="Screenshot 2025-11-10 185757" src="https://github.com/user-attachments/assets/12146f01-3d3b-430a-bc29-89c34f7e0b09" />
<img width="1031" height="612" alt="Screenshot 2025-11-10 185826" src="https://github.com/user-attachments/assets/01279dda-87dc-4830-9522-2c42bd23f106" />



### 2. OLED Berjalan pada Core 0  
<img width="1041" height="612" alt="Screenshot 2025-11-10 185851" src="https://github.com/user-attachments/assets/6d050db2-0b01-4b0d-a7ec-4cb9b241afed" />
<img width="1049" height="622" alt="Screenshot 2025-11-10 185903" src="https://github.com/user-attachments/assets/1b0ca5b6-a34c-488b-94ce-3729f7905193" />



## Video Evidence
Google Drive:https://drive.google.com/file/d/1_e1mSIqiEM98Ct8Bl3cE5V4Qv6MqbrGw/view?usp=sharing
