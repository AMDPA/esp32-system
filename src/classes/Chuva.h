/*
 Chuva.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - A0   ---> GPIO 34
  - D0   ---> 
*/

#ifndef Chuva_h
#define Chuva_h

#include <Arduino.h>

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