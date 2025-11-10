# 05 — Dual Core Servo Control with Mutex (ESP32-S3)

## Description / Deskripsi
Eksperimen ini menunjukkan penggunaan dual core ESP32-S3 dimana dua task berjalan paralel, masing-masing berada di core berbeda, dan mengontrol sebuah servo yang sama menggunakan mekanisme mutex agar tidak terjadi perebutan resource.

- Task Right (BTN_RIGHT) → berjalan pada Core 0 → menggerakkan servo ke kanan (menambah sudut)
- Task Left (BTN_LEFT) → berjalan pada Core 1 → menggerakkan servo ke kiri (mengurangi sudut)

Tujuan utama: membuktikan bahwa shared resource (servo) bisa stabil / smooth walaupun dikontrol dari dua core dengan semaphore mutex (tidak jitter / tidak fight over).

## Hardware Mapping

| Device | Pin | Mode / Core |
|--------|-----|-------------|
| Servo Signal | GPIO 10 | PWM Output |
| Button Right | GPIO 13 | Input Pullup → Task di Core 0 |
| Button Left  | GPIO 12 | Input Pullup → Task di Core 1 |


## Test Procedure / Langkah Percobaan
| No | Langkah | Hasil yang Diharapkan |
|----|---------|-----------------------|
| 1 | Upload program | Servo berada pada posisi tengah (90°) |
| 2 | Tekan Button1 (GPIO 13) | Servo bergerak ke kanan (bertambah sudut) |
| 3 | Tekan Button2 (GPIO 12) | Servo bergerak ke kiri (berkurang sudut) |
| 4 | Lihat Serial Monitor | Log menunjukkan gerakan dari Core 0 dan Core 1 berbeda |
| 5 | Tekan kedua tombol bergantian | Servo tetap bergerak halus & tidak bergetar (mutex sukses) |


## Evidence (Placeholder)
### Core 0 Berjalan
<img width="645" height="594" alt="Screenshot 2025-11-10 173813" src="https://github.com/user-attachments/assets/82d778bc-a119-4c11-ae13-502156b78b2f" />

### Core 1 Berjalan
<img width="654" height="580" alt="Screenshot 2025-11-10 173858" src="https://github.com/user-attachments/assets/813102c9-bfd8-475b-a342-6b9dae69af1a" />


## Video Evidence (Placeholder)
Google Drive:https://drive.google.com/file/d/1pOgJQmETN8knPwIxAzU4KUDGmsnf0fhF/view?usp=sharing
