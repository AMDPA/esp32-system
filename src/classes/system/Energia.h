#ifndef Energia_h
#define Energia_h

#include <Arduino.h>
#include "Server.h"
class Energia
{
public:
    esp_sleep_wakeup_cause_t wakeup_reason;
    void setDeepSleep(int segundos);
    void reestartSystemTokePin();
};

#endif
