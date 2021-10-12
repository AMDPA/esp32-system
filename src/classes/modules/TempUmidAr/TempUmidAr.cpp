#include "TempUmidAr.h"

void TempUmidAr::init(){
    Serial.println("TempUmidAr::init()");
   pinMode(2, INPUT);
   dht.setup(2, DHTesp::DHT11);
}

void TempUmidAr::update(){
    Serial.println("TempUmidAr::update()");
    humidity = dht.getHumidity();
    temperature = dht.getTemperature();
    heatIndex = dht.computeHeatIndex(temperature, humidity);
}
float TempUmidAr::getHumidity(){
    Serial.println("TempUmidAr::getHumidity()");
    return humidity;
}

float TempUmidAr::getTemperature(){
    Serial.println("TempUmidAr::getTemperature()");
    return temperature;
}

float TempUmidAr::getHeatIndex(){
    Serial.println("TempUmidAr::getHeatIndex()");
    return heatIndex;
}