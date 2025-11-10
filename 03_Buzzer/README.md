# 03 — Dual Core Buzzer Frequencies (ESP32-S3)

## Description / Deskripsi

Percobaan ini menunjukan pemanfaatan dual-core ESP32-S3 dengan FreeRTOS untuk menghasilkan **2 pola bunyi buzzer yang berbeda** secara paralel.  
Setiap core menghasilkan frekuensi dan tempo yang berbeda:

- Core 0 → tone buzzer lambat (600 Hz)
- Core 1 → tone buzzer cepat (900 Hz)

Tujuan: membuktikan bahwa eksekusi task audio dapat berjalan independen pada masing-masing core.



## Hardware Mapping

| Device | Pin     | Mode                 |
|--------|---------|----------------------|
| Buzzer | GPIO 14 | Output (Core 0 & Core 1 task) |


## Test Procedure / Langkah Percobaan

| No | Aksi | Hasil Yang Diharapkan |
|----|------|------------------------|
| 1 | Upload program | Serial Monitor menampilkan log “Buzzer Core 0” dan “Buzzer Core 1” |
| 2 | Dengarkan suara buzzer | Terdapat 2 pola berbeda: lambat (Core 0) & cepat (Core 1) |
| 3 | Tutup salah satu task sementara (optional) | Perbedaan ritme semakin jelas |
| 4 | Ubah frekuensi di kode | Suara langsung berubah realtime saat compile ulang |


## Image Evidence


### Core 0 Berjalan
<img width="865" height="697" alt="Screenshot 2025-11-10 163440" src="https://github.com/user-attachments/assets/285463e4-6a52-4624-bf60-875f9a9d52ab" />


### Core 1 Berjalan
<img width="871" height="683" alt="Screenshot 2025-11-10 163451" src="https://github.com/user-attachments/assets/ae169787-bae9-4e95-807e-d35e6e9b171d" />



## Video Evidence
Google Drive:
https://drive.google.com/file/d/1O3b9X_cQ2tMYb1RA_qBvV-9hCD8CBsBN/view?usp=sharing
