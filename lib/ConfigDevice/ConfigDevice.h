#ifndef __CONFIG_DEVICE_H
#define __CONFIG_DEVICE_H

#include <Arduino.h>

/**
 * Основной файл настроек устройства
 **/

////////////////// Порты //////////////////////////////////////////

// Пин к которому подключен датчик влажноти почвы
const uint PORT_SOIL_MOSTURE = GPIO_NUM_36;
// Пин на котором подключен логубой светодиод
const uint PORT_LED_BLUE = GPIO_NUM_23;

///////////////// Настройки датчиков и др. систем ////////////////

// Значение 100% влажности
const uint MIN_ANALOG_VALUE_SOIL_MOISTURE = 1050;

// значение критической сухости
const uint MAX_ANALOG_VALUE_SOIL_MOISTURE = 2700;

// Интервал в секундах в котором будет производится проверка влажности
const uint64_t INTERVAL_SEC_CHECK_SOIL_MOSTURE = 3600;

// Минимальная влажность почвы при которой срабатывает тревога
const uint MIN_SOIL_MOISTURE_VALUE_PERCENT = 20;

#endif