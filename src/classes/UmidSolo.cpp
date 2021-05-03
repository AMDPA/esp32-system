#include "UmidSolo.h"

void UmidSolo::init(){
    
}

void UmidSolo::update(){
    soilMoistureValue = analogRead(SensorPin);
    percent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
}

int UmidSolo::getValue(){
    return percent;
}