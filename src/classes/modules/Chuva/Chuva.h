/*
 Chuva.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - A0   ---> GPIO 34
  - D0   ---> GPIO 33
*/


#ifndef Chuva_h
#define Chuva_h

#include <Arduino.h>

class Chuva
{
    
private: 
    uint8_t digitalPin = 34;
    uint8_t analogicoPin = 33;
    bool active;
    int analogico;
    int digital;
    String status;

public:
    Chuva();
    Chuva(uint8_t dPin, uint8_t aPin);
    bool getActive();
    int getAnalogico();
    int getDigital();
    String getStatus();

private: 
    void atDados();
};

#endif