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

CCS811 ccs811(13); 

class Cjmcu
{
  
public:

    // Construtor padrão
    Cjmcu()
    {
        Wire.begin(); 
        ccs811.set_i2cdelay(50); 
    }
    
    // Obter leitura atual de CO2
    int getCO2(){
       uint16_t eco2, etvoc, errstat, raw;
       ccs811.read(&eco2,&etvoc,&errstat,&raw); 

       return eco2;
    }

    // Obter leitura atual de TVOC  
    int getTVOC(){
        uint16_t eco2, etvoc, errstat, raw;
        ccs811.read(&eco2,&etvoc,&errstat,&raw); 
        
        return etvoc;
    }
};

#endif