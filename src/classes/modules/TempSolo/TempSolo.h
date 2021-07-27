///Classe responsavel pela medição da temperatura do solo. 
///Código baseado em: https://randomnerdtutorials.com/esp32-ds18b20-temperature-arduino-ide/

#ifndef TempSolo_h
#define TempSolo_h

//Bibliotecas
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class TempSolo
{
    private:
    int oneWireBus = 12; //Pino GPIO onde tá conectado o DS18B20
    OneWire oneWire; //Instancia OneWire
    DallasTemperature sensors; //Informando referencia ao DallasTemperature
    float temperatura;

    public:
    void init();
    void update();
    float getTemperatura();
};

#endif