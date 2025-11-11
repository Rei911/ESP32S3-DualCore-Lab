# 04 — Dual Core Potentiometer Reading (ESP32-S3)

## Description / Deskripsi
Eksperimen ini membaca satu potensiometer yang sama tetapi diproses oleh dua task berbeda yang berjalan di core berbeda pada ESP32-S3.  
Tujuan percobaan ini adalah membuktikan bahwa pembacaan ADC dapat dilakukan paralel dan output log menunjukkan dua core menjalankan task independen.

- Task Potentiometer Core 0 → membaca ADC + print log di Core 0  
- Task Potentiometer Core 1 → membaca ADC + print log di Core 1

## Hardware Mapping
| Device | Pin | Mode | Keterangan |
|--------|-----|-------|------------|
| Potentiometer Middle Pin | GPIO 4 | ADC Input | ADC1_CH3 |

## Test Procedure / Langkah Percobaan
| No | Langkah Percobaan | Hasil yang Diharapkan |
|----|-------------------|-----------------------|
| 1 | Upload program pembacaan potensiometer yang menjalankan dua task di Core 0 dan Core 1 | Serial Monitor menampilkan log pembacaan potensiometer dari Core 0 dan Core 1 |
| 2 | Putar knob potensiometer perlahan | Nilai Raw ADC dan Voltage berubah mengikuti putaran |
| 3 | Perhatikan bahwa terdapat dua baris output yang muncul bergantian | Menunjukkan dua task berjalan secara paralel |
| 4 | Pastikan ada tulisan `Running on CORE 0` dan `Running on CORE 1` di Serial Monitor | Membuktikan bahwa pembacaan potensiometer dilakukan dari dua core yang berbeda |

## Image Evidence
### Core 0 Berjalan
<img width="645" height="594" alt="Screenshot 2025-11-10 173813" src="https://github.com/user-attachments/assets/16ac6b1c-014b-41d7-9023-50d32b49e495" />


### Core 1 Berjalan
<img width="654" height="580" alt="Screenshot 2025-11-10 173858" src="https://github.com/user-attachments/assets/c5a9605b-bf0f-4dfc-ac09-225999dfc227" />


## Video Evidence
![Potenti](https://github.com/user-attachments/assets/c625fb0a-7c75-4bc0-a373-e6118cee06bf)

