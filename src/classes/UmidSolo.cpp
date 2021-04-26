#include "UmidSolo.h"

UmidSolo::UmidSolo(){
    soilMoistureValue = analogRead(SensorPin);
    percent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
}

UmidSolo::UmidSolo(int pin){
    SensorPin = pin;
    soilMoistureValue = analogRead(SensorPin);
    percent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
}

int UmidSolo::getValue(){
    return percent;
}