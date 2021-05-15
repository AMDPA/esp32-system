/*
 TempUmidAr.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - DAT  ---> GPIO 02
*/
#ifndef TempUmidAr_h
#define TempUmidAr_h

#include <Arduino.h>
#include <DHTesp.h>

class TempUmidAr
{
   
private:
    DHTesp dht;
    float humidity;
    float temperature;
    float heatIndex;
    
public:
    void init();
    void update();
    float getHumidity();
    float getTemperature();
    float  getHeatIndex();
};

#endif