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


## Image Evidence
### Core 0 Berjalan
<img width="725" height="705" alt="Screenshot 2025-11-10 192907" src="https://github.com/user-attachments/assets/4a123462-aa93-4afc-8e3d-d1d92d16f1b8" />


### Core 1 Berjalan
<img width="724" height="696" alt="Screenshot 2025-11-10 192937" src="https://github.com/user-attachments/assets/10512d3c-1bf7-4800-889c-99cbb31ff3c6" />



## Video Evidence
![Servo](https://github.com/user-attachments/assets/fdb642d8-2244-4012-b5fb-da75064291e1)

