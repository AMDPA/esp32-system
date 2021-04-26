/*#ifndef Energia_h
#define Energia_h

#include <Arduino.h>
#include <esp_deepsleep.h>

class Energia
{
private:
    
public:
    Energia() {}

    void setModoAtivo(){

    }

    void setDeepSleep(int segundos){    
        esp_sleep_enable_timer_wakeup (segundos * 1000000); 
        esp_deep_sleep_start ();
    }

};

#endif
*/