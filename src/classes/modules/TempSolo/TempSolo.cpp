#include "TempSolo.h"

void TempSolo::init(){
    Serial.println("TempSolo::init()");
    oneWire = OneWire(oneWireBus);
    sensors = DallasTemperature(&oneWire);
    sensors.begin();
}

void TempSolo::update(){
    Serial.println("TempSolo::update()");
    sensors.requestTemperatures();
    temperatura = sensors.getTempCByIndex(0);
}

float TempSolo::getTemperatura(){
    //Serial.println("TempSolo::getTemperatura()");
    Serial.println("TempSolo::getTemperatura()->VALUE: " + String(temperatura));
    return temperatura;
}