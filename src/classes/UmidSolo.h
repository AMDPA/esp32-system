///Classe responsavel pela medição da umidade do solo. 
///Código baseado em: https://how2electronics.com/capacitive-soil-moisture-sensor-esp8266-esp32-oled-display/
///
///
///Configurations: 
/// - Pino: 15
/// - Voltagem: 3.3v
///
///
#ifndef UmidSolo_h
#define UmidSolo_h

//Bibliotecas
#include <Arduino.h>

class UmidSolo
{
    private: 
    //variaveis de calibração do sensor
    /**
     * Para calibrar o sensor deve-se:
     * - Colocar o valor do Analog Read com o sensor no ar;
     * - Colocar o valor do Analog Read com o Sensor na agua;
     * em suas respectivas variaveis. 
    */
    int AirValue = 3665;   //valor obtido no ar
    int WaterValue = 1755;  //valor obtido na agua
    int SensorPin = 15;
    int soilMoistureValue = 0;
    int soilmoisturepercent = 0;

    public:
    UmidSolo(){}
    UmidSolo(int pinoGPIO)
    {
        SensorPin = pinoGPIO;
    }

    void Update()
    {
        Serial.println("CAPACITATIVE SOIL MOISTURE SENSOR V2.0");
    //Obter valor de medição
    soilMoistureValue = analogRead(SensorPin);

    //passar valor para % considerando os valores de calibração
    soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

    //Exibir umidade 
    Serial.print("Analog read: " + String(soilMoistureValue) + "\n");
    Serial.print("Percent: " + String(soilmoisturepercent) + "\n");
Serial.print("\n\n");
    }
};

#endif