/*
 Cjmcu.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - SCL  ---> GPIO 22
  - SDA  ---> GPIO 21
  - WAK  ---> GPIO 13
*/

#ifndef Cjmcu_h
#define Cjmcu_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_CCS811.h>

class Cjmcu
{

private:
    uint16_t eco2 = 0;
    uint16_t etvoc = 0;
    Adafruit_CCS811 ccs;


public:
    void init();
    void update();
    uint16_t getEco2();
    uint16_t getEtvoc();
};

#endif