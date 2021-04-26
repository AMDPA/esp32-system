#include "TempUmidAr.h"

TempUmidAr::TempUmidAr(){
   dht.setup(2, DHTesp::DHT11);
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