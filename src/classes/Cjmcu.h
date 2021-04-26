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
#include <ccs811.h>



class Cjmcu
{

private: 
    uint16_t eco2; 
    uint16_t etvoc; 
    uint16_t errstat; 
    uint16_t raw;
    CCS811 ccs811; 
  
public:
    Cjmcu();
    uint16_t getEco2();
    uint16_t getEtvoc();
    uint16_t getErrstat();
    uint16_t getRaw();
};

#endif