#ifndef Hora_h
#define Hora_h

#include <Arduino.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_system.h>
#include <time.h>
#include <sys/time.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

class Hora
{
private:
    struct tm data;

public:
    void setUnixTimeStamp(int unixTimeStamp);
    void updateHoraRede();
    int getUnixTimeStamp();
    String getDataFull();
    String getData();
};

#endif