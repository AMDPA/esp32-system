///Classe responsavel pela medição da temperatura e umidade do AR. 
///Código baseado em: https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/
///
///
///Configurations: 
/// - Pino: 2
/// - Voltagem: 3.3v
///
///
#ifndef TempUmidAr_h
#define TempUmidAr_h

//Bibliotecas
#include <Arduino.h>
#include <DHT.h>

//Definindo GPIO e Tipo
#define DHTPIN 2
#define DHTTYPE DHT11

//Instanciando o DHT
DHT dht(DHTPIN, DHTTYPE);

class TempUmidAr
{
    private:
    float h;
    float t;
    float hic;

    public:
    TempUmidAr()
    {
        //Inicializando DHT
        dht.begin();
    }

    void Update()
    {
        Serial.println("DTH11");
        //Lendo Humidade
        h = dht.readHumidity();

        //Lendo temperatura
        t = dht.readTemperature();

        //Calculando Indice de calor
        hic = dht.computeHeatIndex(t, h, false);

        //Exibir resultados
        Serial.print("Umidade: " + String(h) + "\n");
        Serial.print("Temperatura: " + String(t) + "\n");
        Serial.print("Indice de Calor: " + String(hic) + "\n");
        Serial.print("\n\n");
    }
};

#endif