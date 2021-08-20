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
    void setUnixTimeStamp(int unixTimeStamp);
    int getUnixTimeStamp();
    String getData();
};

#endif