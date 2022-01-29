#include "UmidSolo.h"

void UmidSolo::init(){
    Serial.println("UmidSolo::init()");
    pinMode(SensorPin, INPUT);
}

void UmidSolo::update(){
    Serial.println("UmidSolo::update()");
    soilMoistureValue = analogRead(SensorPin);
    percent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
}

int UmidSolo::getValue(){
    //Serial.println("UmidSolo::getValue()");
    Serial.println("UmidSolo::getValue()->VALUE: " + percent);
    return percent;
}