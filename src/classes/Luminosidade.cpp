#include "Luminosidade.h"

Luminosidade::Luminosidade(){
    init();
}

Luminosidade::Luminosidade(uint8_t p){
    pin = p;
    init();
}

void Luminosidade::init(){
    value = analogRead(pin);
    percent = map(value, 0, 4095, 0, 100);
}

int Luminosidade::getValue(){
    return value;
}

float Luminosidade::getPercent(){
    return percent;
}