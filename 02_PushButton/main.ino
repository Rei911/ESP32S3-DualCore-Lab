#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// ================= PIN DEFINISI =================
#define BUTTON1 13
#define BUTTON2 12
#define LED3 16

// ================= TASK CORE 0 =================
void Task_Button_Core0(void *parameter) {
  for(;;){
    int state = digitalRead(BUTTON1);
    if (state == LOW) { // tombol ditekan
      digitalWrite(LED3, HIGH);
      Serial.println("BUTTON1 ditekan | Core 0");
    }
    vTaskDelay(50 / portTICK_PERIOD_MS); // debounce sederhana
  }
}

// ================= TASK CORE 1 =================
void Task_Button_Core1(void *parameter) {
  for(;;){
    int state = digitalRead(BUTTON2);
    if (state == LOW) { // tombol ditekan
      digitalWrite(LED3, LOW);
      Serial.println("BUTTON2 ditekan | Core 1");
    }
    vTaskDelay(50 / portTICK_PERIOD_MS); // debounce sederhana
  }
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED3, LOW);

  // Jalankan task pada core berbeda
  xTaskCreatePinnedToCore(Task_Button_Core0, "BTN_Core0", 2048, NULL, 1, NULL, 0); // CORE 0
  xTaskCreatePinnedToCore(Task_Button_Core1, "BTN_Core1", 2048, NULL, 1, NULL, 1); // CORE 1
}

void loop() {
  // Tidak digunakan karena semua berjalan dalam task
}
