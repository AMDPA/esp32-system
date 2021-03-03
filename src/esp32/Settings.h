#ifndef Hora_h
#define Hora_h

#include <Arduino.h>

RTC_DATA_ATTR bool acesso;

class Settings
{
private:
    
public:
    Settings();

    bool getAcesso(){
        if(!acesso){
            
        }

        return acesso;
    }
};


#endif