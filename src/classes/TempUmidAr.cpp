#include "TempUmidAr.h"

void TempUmidAr::init(){
   dht.setup(2, DHTesp::DHT11);
}

void TempUmidAr::update(){
    humidity = dht.getHumidity();
    temperature = dht.getTemperature();
    heatIndex = dht.computeHeatIndex(temperature, humidity);
}
float TempUmidAr::getHumidity(){
    return humidity;
}

float TempUmidAr::getTemperature(){
    return temperature;
}

float TempUmidAr::getHeatIndex(){
    return heatIndex;
}