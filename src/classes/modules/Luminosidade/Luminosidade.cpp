#include "Luminosidade.h"

void Luminosidade::init(){
   Serial.println("Luminosidade::init()");
    pinMode(pin, INPUT);

}

void Luminosidade::update(){
    Serial.println("Luminosidade::uodate()");
    value = analogRead(pin);
    percent = map(value, 0, 4095, 0, 100);
}

int Luminosidade::getValue(){
    Serial.println("Luminosidade::getValue()");
    return value;
}

float Luminosidade::getPercent(){
    Serial.println("Luminosidade::getPercent()");
    return percent;
}