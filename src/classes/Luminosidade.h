///
///
///Configurations: 
/// - Pino: 26
/// - Voltagem: 3.3v
/// - COM negativo
///
///


#ifndef Luminosidade_h
#define Luminosidade_h

#include <Arduino.h>
class Luminosidade
{
private:
    /* data */
public:
    Luminosidade()
    {

    }

    void Update()
    {
        int value = 0;
        value = analogRead(26);
        Serial.println(value);
        double soilmoisturepercent = map(value, 0, 4095, 0, 100);
        Serial.print(soilmoisturepercent);
        Serial.println("%");
    }
};

#endif
