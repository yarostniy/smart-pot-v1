#include <Arduino.h>
#include "WiFi.h"
#include <Led.h>
#include <SensorSoilMoisture.h>

// Настройка устройства при запуске
// -------------------------------------------------------
// Файл настроек лежит в /lib/ConfigDevice/ConfigDevice.h
// -------------------------------------------------------

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  esp_log_level_set("*", ESP_LOG_VERBOSE);

  //Отключаем все радио модули, в этой версии прошивки они нам не пригодятся
  WiFi.mode(WIFI_OFF);
  btStop();

  // Настраиваем пин датчика влажности на чтение, таймер и агент проверки
  initSoilMoisture();

  // Настраиваем пины для диодов
  initLed();

  // Переводим устройсво в режим легкого сна для экономии заряда
  esp_light_sleep_start();
}

// Основной цикл приложения

void loop() { loopSensorSoilMosute(); }