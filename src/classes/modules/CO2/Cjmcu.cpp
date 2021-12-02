#include "Cjmcu.h"

void Cjmcu::init(){
    Serial.println("Cjmcu::init()");
    while (!ccs.begin() && !ccs.available());
}

void Cjmcu::update(){
    Serial.println("Cjmcu::update()");
    if(ccs.available()){
        if(!ccs.readData()){
            eco2 = ccs.geteCO2();
            etvoc = ccs.getTVOC();
        }
    }
}

uint16_t Cjmcu::getEco2(){
    Serial.println("Cjmcu::getEco2()");
    return eco2;
}

uint16_t Cjmcu::getEtvoc(){
    Serial.println("Cjmcu::getEtvoc()");
    return etvoc;
}