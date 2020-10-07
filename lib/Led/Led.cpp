#include "Led.h"

// Функция начальной настройки порта и светодиода при запуске устройства
void initLed(void)
{
    pinMode(PORT_LED_BLUE, OUTPUT);
    digitalWrite(PORT_LED_BLUE, LOW);
}

// Функция управления светодиодом.
void setLedBlue(uint8_t val) { digitalWrite(PORT_LED_BLUE, val); }