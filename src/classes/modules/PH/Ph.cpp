#include "Ph.h"

void Ph::init(){
    Serial.println("Ph::init()");
    pinMode(pHSense, INPUT);
}

void Ph::update(){
    Serial.println("Ph::update()");
    pH_Value = analogRead(pHSense);
}

float Ph::getPh(){
    Serial.println("Ph::getPh()");
    float voltage = 14 - (((pH_Value * (5.0 / 1023.0)))*0.526);
    return voltage;
}