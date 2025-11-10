#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// Encoder Pins
#define CLK 18
#define DT  19
#define SW  21

// Task Handles
TaskHandle_t HandleTaskEncoderCore0;
TaskHandle_t HandleTaskButtonCore1;

volatile int encoderValue = 0;
int lastCLKState;

void IRAM_ATTR readEncoder() {
  int currentCLK = digitalRead(CLK);
  int currentDT  = digitalRead(DT);

  if (currentCLK != lastCLKState) { 
    if (currentDT != currentCLK) encoderValue++;
    else encoderValue--;
  }
  lastCLKState = currentCLK;
}

// Task di Core 0 → Monitor nilai encoder
void TaskEncoderCore0(void *pvParameters) {
  for(;;){
    Serial.printf("[Core %d] Encoder Value: %d\n",
                  xPortGetCoreID(), encoderValue);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

// Task di Core 1 → Deteksi tombol SW
void TaskButtonCore1(void *pvParameters) {
  for(;;){
    if (digitalRead(SW) == LOW) {
      Serial.printf("[Core %d] BUTTON PRESSED\n", xPortGetCoreID());
      vTaskDelay(300 / portTICK_PERIOD_MS); // debounce
    }
    vTaskDelay(1);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  lastCLKState = digitalRead(CLK);

  attachInterrupt(digitalPinToInterrupt(CLK), readEncoder, CHANGE);

  xTaskCreatePinnedToCore(
    TaskEncoderCore0,
    "EncoderCore0",
    2048,
    NULL,
    1,
    &HandleTaskEncoderCore0,
    0
  );

  xTaskCreatePinnedToCore(
    TaskButtonCore1,
    "ButtonCore1",
    2048,
    NULL,
    1,
    &HandleTaskButtonCore1,
    1
  );

  Serial.println("Dual-Core Encoder Ready!");
}

void loop() {
  // kosong
}
