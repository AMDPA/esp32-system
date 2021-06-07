#include "Cjmcu.h"

void Cjmcu::init(){
    
    if(!ccs.begin()){
        while(1);
    }

    while (!ccs.available());
}

void Cjmcu::update(){
    if(ccs.available()){
        if(!ccs.readData()){
            eco2 = ccs.geteCO2();
            etvoc = ccs.getTVOC();
        }
    }
}

uint16_t Cjmcu::getEco2(){
    return eco2;
}

uint16_t Cjmcu::getEtvoc(){
    return etvoc;
}