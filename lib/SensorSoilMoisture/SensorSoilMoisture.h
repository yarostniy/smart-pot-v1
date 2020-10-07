

#ifndef __SOIL_MOISTURE_DEVICE_H
#define __SOIL_MOISTURE_DEVICE_H

#include <Arduino.h>
#include <Ticker.h>
#include <Led.h>
#include <ConfigDevice.h>

// коэффициент пересчета  микросекунд в секунды
#define uS_TO_S_FACTOR 1000000

// Объект таймера для переодического опроса датчика
extern Ticker timerCheckSoilMosture;
// Объект таймера для моргания диодом при тревоге
extern Ticker timerLedBlink;

// Готовность к чтению датчика влажности почвы,
extern volatile bool readyForReadSensorSoilMosture;

// Инициализация пина датчика влажности

void initSoilMoisture();

// Функция проверяет показания и мигает диодом

void agentCheckSoilMosture(int agentCheckSoilMosture);

// Метод возращает текущий уровень влажноти почвы

float getSoilMoisture();

// Метод для запуска в главном цикле программы main.cpp

void loopSensorSoilMosute();

#endif