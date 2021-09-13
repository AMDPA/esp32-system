/*
 TempSolo.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND 
  - DD   ---> GPIO 12 aterrado com resistor 4.7
*/


#ifndef TempSolo_h
#define TempSolo_h

//Bibliotecas
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class TempSolo
{
    private:
    int oneWireBus = 12; //Pino GPIO onde tá conectado o DS18B20
    OneWire oneWire; //Instancia OneWire
    DallasTemperature sensors; //Informando referencia ao DallasTemperature
    float temperatura;

    public:
    void init();
    void update();
    float getTemperatura();
};

#endif