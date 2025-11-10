# 02 — Dual Core Button Control LED (ESP32-S3)

## Description / Deskripsi
Percobaan ini menunjukkan pemrosesan input button secara paralel pada dua core berbeda di ESP32-S3 menggunakan FreeRTOS Task.

- BUTTON1 dibaca oleh Task yang berjalan pada Core 0
- BUTTON2 dibaca oleh Task yang berjalan pada Core 1
- Kedua task mengontrol LED3 yang sama
- Tidak menggunakan loop() (seluruh logic berjalan pada task)

Tujuan utama: membuktikan bahwa kedua core memproses event berbeda tanpa saling blocking dan tetap stabil.

## Hardware Mapping

| Device  | Pin     | Mode                          |
|---------|---------|--------------------------------|
| BUTTON1 | GPIO 13 | Input Pullup (Task Core 0)     |
| BUTTON2 | GPIO 12 | Input Pullup (Task Core 1)     |
| LED3    | GPIO 16 | Output Shared untuk kedua Task |

## Test Procedure / Langkah Percobaan

| No | Aksi | Hasil Yang Diharapkan |
|----|------|------------------------|
| 1  | Buka Serial Monitor | Muncul teks “BTN_Core0” & “BTN_Core1” saat tombol ditekan |
| 2  | Tekan BUTTON1 (GPIO 13) | LED3 MENYALA |
| 3  | Tekan BUTTON2 (GPIO 12) | LED3 MATI |
| 4  | Tekan cepat berkali-kali | Tidak terjadi bouncing berlebih |
| 5  | Perhatikan log per-core | “Core 0” log BUTTON1, “Core 1” log BUTTON2 |

## Image Evidence 

### Core 0 berjalan → <img width="759" height="756" alt="Screenshot 2025-11-10 153758" src="https://github.com/user-attachments/assets/5fca37cb-7780-4094-a55d-eda307e98efe" />


### Core 1 berjalan → *<img width="754" height="747" alt="Screenshot 2025-11-10 153837" src="https://github.com/user-attachments/assets/b37cf0c4-5d9c-4751-b23d-96a18d1a4217" />


## Video Evidence

Google Drive:
https://drive.google.com/file/d/1-XxH-NLUAm_1-87Xlxk12dqir5M4JGrs/view?usp=sharing
