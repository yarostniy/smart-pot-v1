#include "SensorSoilMoisture.h"

volatile bool readyForReadSensorSoilMosture = false;

Ticker timerCheckSoilMosture;
Ticker timerLedBlink;

// Инициализация пина
void initSoilMoisture()
{
  // Задаем таймер пробуждения равный интервалу проверки минус 1 секунду
  esp_sleep_enable_timer_wakeup(INTERVAL_SEC_CHECK_SOIL_MOSTURE - 1 * uS_TO_S_FACTOR);
  pinMode(PORT_SOIL_MOSTURE, INPUT);
  timerCheckSoilMosture.once(15, []() {
    readyForReadSensorSoilMosture = true;
    timerCheckSoilMosture.attach(INTERVAL_SEC_CHECK_SOIL_MOSTURE,
                                 []() { readyForReadSensorSoilMosture = true; });
  });
}

/**
 * Возращает текущий уровень влажноти почвы
 */
float getSoilMoisture()
{
  portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
  portENTER_CRITICAL(&mux);
  int avalue = analogRead(PORT_SOIL_MOSTURE);
  portEXIT_CRITICAL(&mux);
  // масштабируем значение в проценты
  avalue = constrain(avalue, MIN_ANALOG_VALUE_SOIL_MOISTURE, MAX_ANALOG_VALUE_SOIL_MOISTURE);
  int moisture =
      map(avalue, MIN_ANALOG_VALUE_SOIL_MOISTURE, MAX_ANALOG_VALUE_SOIL_MOISTURE, 100, 0);
  return (float)moisture;
}

// Агент проверки влажности почвы по расписанию

void agentCheckSoilMosture(int minSoilMostureValue = 20)
{
  int soilMosuture = getSoilMoisture();
  Serial.println(String(soilMosuture) + "%");
  // Влажность почвы ниже минимально возможной для растения
  if (soilMosuture < minSoilMostureValue)
  {
    timerLedBlink.detach();
    timerLedBlink.attach(1,
                         []() {
                           setLedBlue(HIGH);
                           delay(300);
                           setLedBlue(LOW);
                         });
    esp_light_sleep_start();
  }
  else
  {
    // Влажность в норме и мы выключаем диод и уходим в сон
    timerLedBlink.detach();
    setLedBlue(LOW);
    // Отключаемся, устройство проснется в нужное время само для проверки показаний
    esp_deep_sleep_start();
  }
}

// Функция инициализации. Вызывается в setup

void loopSensorSoilMosute()
{
  // Переменная изменяется в таймере. Обрабатка идет
  // с большими задержками для экономии заряда.

  if (readyForReadSensorSoilMosture)
  {
    readyForReadSensorSoilMosture = false;
    agentCheckSoilMosture(MIN_SOIL_MOISTURE_VALUE_PERCENT);
    yield();
  }
}