01 — Dual Core LED Blinking (ESP32-S3)
Description / Deskripsi

This experiment demonstrates dual-core execution on ESP32-S3 using FreeRTOS.
2 LED blink tasks berjalan paralel pada core berbeda.

LED1 berjalan pada Core 0

LED2 berjalan pada Core 1

Goal utama: membuktikan secara visual melalui kedipan LED + Serial Monitor bahwa kedua core berjalan independent.

Hardware Mapping
Device	Pin	Mode
LED1	GPIO 2	Output (Task Core 0)
LED2	GPIO 15	Output (Task Core 1)
Test Procedure (Langkah Percobaan)
No	Step	Expected Result
1	Upload program	Serial Monitor tampil log Core 0 & Core 1
2	Amati LED1	LED1 berkedip lebih cepat (delay ~300ms)
3	Amati LED2	LED2 berkedip lebih lambat (delay ~500ms)
4	Amati Serial Output	Terdapat tulisan “Core 0” dan “Core 1” → berarti task benar-benar berjalan pada core berbeda

Evidence / Bukti Capture
Core 0 berjalan 
<img width="711" height="591" alt="Screenshot 2025-11-10 145803" src="https://github.com/user-attachments/assets/ee035afc-bf1b-4ce3-9b87-3a9967abbab9" />
Core 1 Berjalan
<img width="700" height="706" alt="Screenshot 2025-11-10 145819" src="https://github.com/user-attachments/assets/3f4b40fa-627a-4cd8-8a78-38c845a53fb5" />

Video Evidence (Google Drive Link)
https://drive.google.com/file/d/1HoRDTLnAkrKF1bCPkEXxot8ThCFlIGAO/view?usp=sharing
