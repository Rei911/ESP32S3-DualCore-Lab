#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// ================= PIN DEFINISI =================
#define LED1 2
#define LED2 15
#define LED3 16

// ================= TASK (CORE 0) =================
void Task_LED_Core0(void *parameter) {
  for(;;) {
    digitalWrite(LED1, HIGH);
    Serial.println("LED1 ON | Core 0");
    vTaskDelay(300 / portTICK_PERIOD_MS);

    digitalWrite(LED1, LOW);
    Serial.println("LED1 OFF | Core 0");
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

// ================= TASK (CORE 1) =================
void Task_LED_Core1(void *parameter) {
  for(;;) {
    digitalWrite(LED2, HIGH);
    Serial.println("LED2 ON | Core 1");
    vTaskDelay(500 / portTICK_PERIOD_MS);

    digitalWrite(LED2, LOW);
    Serial.println("LED2 OFF | Core 1");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT); // LED3 nanti dipakai eksperimen gabungan

  // Buat Task
  xTaskCreatePinnedToCore(Task_LED_Core0, "LED_Core0", 2048, NULL, 1, NULL, 0);  // Core 0
  xTaskCreatePinnedToCore(Task_LED_Core1, "LED_Core1", 2048, NULL, 1, NULL, 1);  // Core 1
}

void loop() {
  // Tidak dipakai, semua berjalan di Task
}
