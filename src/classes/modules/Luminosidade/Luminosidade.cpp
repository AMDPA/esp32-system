#include "Luminosidade.h"

void Luminosidade::init(){
   
    pinMode(pin, INPUT);

}

void Luminosidade::update(){
    value = analogRead(pin);
    percent = map(value, 0, 4095, 0, 100);
}

int Luminosidade::getValue(){
    return value;
}

float Luminosidade::getPercent(){
    return percent;
}