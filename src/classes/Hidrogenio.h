#include <Arduino.h>
///Classe responsavel pela medição do gás Hidrogenio. 
///Código baseado em: https://randomnerdtutorials.com/esp32-ds18b20-temperature-arduino-ide/

///
///
///Configurations: 
/// - Pino: 35
/// - Voltagem: 5v
///
///

#ifndef Hidrogenio_h
#define Hidrogenio_h

class Hidrogenio
{
private:
    /* data */
public:
    Hidrogenio()
    {

    }

    void Update()
    {
        int valor = analogRead(35);
        Serial.println("HIDROGENIO");
        Serial.println(valor);
        Serial.print("\n\n");
    }
};

#endif