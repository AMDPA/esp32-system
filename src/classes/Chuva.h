///
///
///Configurations: 
/// - Pino: 34
/// - Voltagem: 3.3v
///
///


#include <Arduino.h>

#ifndef Chuva_h
#define Chuva_h

#define PIN 34
class Chuva
{
private:
    /* data */
public:
    Chuva()
    {
        pinMode(PIN, INPUT);
    }

    void Update()
    {
        int leitura = analogRead(PIN);
        Serial.println("SENSOR DE CHUVA");
        Serial.println(leitura);
        Serial.print("\n\n");
    }
};

#endif