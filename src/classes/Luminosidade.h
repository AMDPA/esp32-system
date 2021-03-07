/*
 Luminosidade.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - 1M   ---> 
  - OUT  ---> GPIO 26
  - -V   ---> 
  - COM  ---> GND
*/

#ifndef Luminosidade_h
#define Luminosidade_h

#include <Arduino.h>

uint8_t pin = 26;
class Luminosidade
{

public:
    // Construtor padrão, GPIO 26
    Luminosidade(){
        init();
    }

    // Construtor opcional, informar GPIO
    Luminosidade (uint8_t p){
        pin = p;
        init();
    }

private:
    void init(){
        pinMode(pin, INPUT);
    }

public:
    // Obter leitura analogica do sensor (0, 4095)
    int getAnalog(){
        int valor = analogRead(pin);
        
        return valor;
    }

    // Obter porcentagem de leitura
    int getPorcentagem(){
        int valor = analogRead(pin);
        double porcentagem = map(valor, 0, 4095, 0, 100);
        
        return porcentagem;
    }
};

#endif
