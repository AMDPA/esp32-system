#include "UmidSolo.h"

void UmidSolo::init(){
    pinMode(SensorPin, INPUT);
}

void UmidSolo::update(){
    soilMoistureValue = analogRead(SensorPin);
    percent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
}

int UmidSolo::getValue(){
    return percent;
}