#ifndef Hora_h
#define Hora_h

#include <Arduino.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_system.h>
#include <time.h>
#include <sys/time.h>

class Hora
{
private:
    struct tm data;

public:
    Hora();

    //Setar valor de data atraves de int UnixTime
    void setData(int unixTimeStamp)
    {
        timeval tv;

        tv.tv_sec = unixTimeStamp;
        settimeofday(&tv, NULL);
    }

    // Obter data em formato unix
    int getData(void)
    {
        time_t tt = time(NULL);
        return tt;
    }

    // Obter data em formato DateTime
    String getData(bool ptBr)
    {
        if(ptBr){
            time_t tt = time(NULL);
            data = *gmtime(&tt);
        
            char data_formatada[64];
            strftime(data_formatada, 64, "%Y-%m-%d %H:%M:%S", &data);
            return data_formatada;
        }
    
        return  "null";
    }   
};

#endif