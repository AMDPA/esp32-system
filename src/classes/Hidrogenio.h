/*
 Hidrogenio.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 5V
  - GND  ---> GND
  - D0   --->
  - A0   ---> 35
*/

#ifndef Hidrogenio_h
#define Hidrogenio_h

#include <Arduino.h>

class Hidrogenio
{

private: 
    uint8_t pin = 35;
    int value;

public:
    Hidrogenio();
    Hidrogenio(uint8_t p);
    int getValue();
    
};
#endif