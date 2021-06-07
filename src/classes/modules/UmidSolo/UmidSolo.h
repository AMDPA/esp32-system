/*
 UmidSolo.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - AUOT ---> GPIO 15  
*/

#ifndef UmidSolo_h
#define UmidSolo_h

//Bibliotecas
#include <Arduino.h>

class UmidSolo
{
private: 
    //variaveis de calibração do sensor
    /**
     * Para calibrar o sensor deve-se:
     * - Colocar o valor do Analog Read com o sensor no ar;
     * - Colocar o valor do Analog Read com o Sensor na agua;
     * em suas respectivas variaveis. 
    */
    int AirValue = 3665;   //valor obtido no ar
    int WaterValue = 1634;  //valor obtido na agua
    int SensorPin = 15;
    int soilMoistureValue = 0;

    int percent;

public:
    void init();
    void update();
    int getValue();
};

#endif