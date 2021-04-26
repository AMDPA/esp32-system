#include "Cjmcu.h"

Cjmcu::Cjmcu(){
    Wire.begin(); 
    ccs811.set_i2cdelay(50); 
    ccs811.read(&eco2,&etvoc,&errstat,&raw); 
}

uint16_t Cjmcu::getEco2(){
    return eco2;
}

uint16_t Cjmcu::getEtvoc(){
    return etvoc;
}

uint16_t Cjmcu::getErrstat(){
    return errstat;
}

uint16_t Cjmcu::getRaw(){
    return raw;
}