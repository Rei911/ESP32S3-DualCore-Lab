#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUZZER 14

// ================= TASK CORE 0 (Bunyi lambat) =================
void Task_Buzzer_Core0(void *parameter){
  for(;;){
    Serial.println("Buzzer Core 0");
    tone(BUZZER, 600);   // frekuensi 600 Hz
    vTaskDelay(500 / portTICK_PERIOD_MS);
    noTone(BUZZER);
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

// ================= TASK CORE 1 (Bunyi cepat) =================
void Task_Buzzer_Core1(void *parameter){
  for(;;){
    Serial.println("Buzzer Core 1");
    tone(BUZZER, 900);   // frekuensi 900 Hz
    vTaskDelay(200 / portTICK_PERIOD_MS);
    noTone(BUZZER);
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  pinMode(BUZZER, OUTPUT);

  // Buat 2 task pada core berbeda
  xTaskCreatePinnedToCore(Task_Buzzer_Core0, "BuzzCore0", 2048, NULL, 1, NULL, 0); // Core 0
  xTaskCreatePinnedToCore(Task_Buzzer_Core1, "BuzzCore1", 2048, NULL, 1, NULL, 1); // Core 1
}

void loop(){
  // Tidak dipakai — semua berjalan di task masing-masing
}
