#include "TempSolo.h"

void TempSolo::init(){
    oneWire = OneWire(oneWireBus);
    sensors = DallasTemperature(&oneWire);
    sensors.begin();
}

void TempSolo::update(){
    sensors.requestTemperatures();
    temperatura = sensors.getTempCByIndex(0);
}

float TempSolo::getTemperatura(){
    return temperatura;
}