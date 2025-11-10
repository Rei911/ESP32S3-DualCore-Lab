# 07 — Dual Core Rotary Encoder Read (ESP32-S3)

## Description / Deskripsi

Eksperimen ini menunjukkan bahwa rotary encoder bisa dibaca dan hasilnya dikirim oleh **dua task** yang dijalankan pada **dua core berbeda** ESP32-S3 secara paralel menggunakan FreeRTOS.

Tujuan utama: membuktikan bahwa satu shared state encoder (via interrupt) bisa dikonsumsi oleh 2 konsumer task berbeda di 2 core secara bersamaan tanpa blocking.

- Task RotaryEncoder Core 0 → membaca ADC + print log di Core 0  
- Task RotaryEncoder Core 1 → membaca ADC + print log di Core 1

## Hardware Mapping

| Device        | Pin | Mode                          |
|---------------|-----|-------------------------------|
| Rotary CLK    | 18  | Input (Interrupt)             |
| Rotary DT     | 19  | Input                         |
| Task Reader 1 | —   | Output Serial (Task Core 0)   |
| Task Reader 2 | —   | Output Serial (Task Core 1)   |

## Test Procedure / Langkah Percobaan

| No | Step | Expected Result |
|----|------|-----------------|
| 1  | Upload program | Serial Monitor tampil log Core 0 & Core 1 |
| 2  | Putar rotary encoder CW/CCW | Nilai encoder berubah naik / turun |
| 3  | Observasi log Serial | Core 0 update lebih cepat (~200ms) |
| 4  | Observasi log Serial | Core 1 update lebih lambat (~700ms) |
| 5  | Validasi 2 Core | Ada teks “CORE 0” & “CORE 1” → bukti task berjalan di core berbeda |

## Image Evidence

### 1. Core 0 Berjalan
<img width="540" height="614" alt="Screenshot 2025-11-10 184433" src="https://github.com/user-attachments/assets/7447695f-75dc-4020-b4b6-d0c7e2f6f670" />


### 2. Core 1 Berjalan
<img width="536" height="603" alt="Screenshot 2025-11-10 184451" src="https://github.com/user-attachments/assets/062eb547-58c3-4bda-bde7-322be14babf5" />


### Video Evidence
Google Drive:
https://drive.google.com/file/d/1n_WfHYYSAVmYpUDJg4wfcl8oEv27upDG/view?usp=sharing 

