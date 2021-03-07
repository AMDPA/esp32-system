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
    int oneWireBus; //Pino GPIO onde tá conectado o DS18B20
    OneWire oneWire; //Instancia OneWire
    DallasTemperature sensors; //Informando referencia ao DallasTemperature

    public:
    TempSolo(){}

    TempSolo(int pinoGPIO)
    {
        //Informando pino onde tá conectado DS18B20
        oneWireBus = pinoGPIO;
        
        //Instancindo o OneWire
        oneWire = OneWire(oneWireBus);

        //Instanciando DallasTenperature
        sensors = DallasTemperature(&oneWire);
        
        //Inicializando sensor
        sensors.begin();
    }

    void Update()
    {
        //Obtendo temperaturas    
        sensors.requestTemperatures();

        //Obtendo Temperatura de determinado sensor
        float temperatura = sensors.getTempCByIndex(0);

        //Exibindo
        Serial.println(temperatura);
        Serial.println("°C");
        Serial.print("\n\n");
    }
};

#endif