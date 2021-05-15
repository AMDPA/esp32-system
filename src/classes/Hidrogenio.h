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
#include <MQUnifiedsensor.h>

#define Board ("ESP-32") 
#define Pin (35) 

#define Type ("MQ-8") 
#define Voltage_Resolution (3.3) 
#define ADC_Bit_Resolution (12) 
#define RatioMQ8CleanAir (10) 

class Hidrogenio
{

private: 
    MQUnifiedsensor MQ8;
    uint8_t pin = 35;
    float ppm;

public:
    void init();
    void update();
    float getPpm();
    
};
#endif
