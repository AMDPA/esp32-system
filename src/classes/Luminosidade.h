/*
 Luminosidade.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - 1M   ---> 
  - OUT  ---> GPIO 26
  - -V   ---> 
  - COM  ---> GND
*/

#ifndef Luminosidade_h
#define Luminosidade_h

#include <Arduino.h>


class Luminosidade
{
private: 
    uint8_t pin = 26;
    int value;
    float percent;

public:
    Luminosidade();
    Luminosidade (uint8_t p);
    int getValue();
    float getPercent();

private:
    void init();

};

#endif
