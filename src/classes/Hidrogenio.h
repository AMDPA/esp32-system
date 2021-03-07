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

uint8_t pin = 35;

class Hidrogenio
{
public:
    Hidrogenio(){
        init();
    }

    Hidrogenio(uint8_t p){
        pin = p;
    }

private:
    void init(){
        pinMode(pin, INPUT);
    }

public:
    int getHidrogenio(){
        return analogRead(pin);
    }
};

#endif