#include "Ph.h"

void Ph::init(){
    Serial.println("Ph::init()");
    pinMode(pHSense, INPUT);
}

void Ph::update(){
    Serial.println("Ph::update()");
    pH_Value = analogRead(pHSense);
    voltage = 14 - (((pH_Value * (5.0 / 1023.0)))*0.526);
}

float Ph::getPh(){
    Serial.println("Ph::getPh()");
    Serial.println("Ph::getPh()->VALUE: " + String(voltage));
    return voltage;
}