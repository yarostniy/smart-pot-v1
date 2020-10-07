#include "Led.h"

void initLed(void)
{
    pinMode(PORT_LED_BLUE, OUTPUT);
    digitalWrite(PORT_LED_BLUE, LOW);
}

void setLedBlue(uint8_t val) { digitalWrite(PORT_LED_BLUE, val); }