/*
 Chuva.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - VCC  ---> 3V3
  - GND  ---> GND
  - A0   ---> GPIO 34
  - D0   ---> GPIO 33
*/

#ifndef Chuva_h
#define Chuva_h

#include <Arduino.h>

uint8_t digital = 34;
uint8_t analogico = 33;

class Chuva
{

public:
    // Construtor padrao, GPIO's 34 e 35
    Chuva()
    {
        init();
    }

    // Construtor opcional, informar GPIO's
    Chuva(uint8_t AO, uint8_t D0){
        init(A0, D0);
    }

private:
    void init(uint8_t a = analogico, uint8_t b = digital){
        analogico = a;
        digital = b;
       
        pinMode(a, INPUT);
        pinMode(b, INPUT);
    }

public:

    // Obter leitura atual do pino analogico
    int getAnalogico(){
        return analogRead(analogico);
    }

    // Obter leitura atual do pino digital
    int getDigital(){
        return digitalRead(digital);
    }

    // True/false, retorna se o sensor está em contato com água
    bool getTouch(){
        int a = touchRead(digital);
       
       if(a == 0){
           return true;
       }
       else{
           return false;
       }
    }

    // Retorna o status atual da chuva
    String getStatus(){
        int medicao = getAnalogico();
        int mapp = map(medicao, 0, 4095, 0, 3);
  
        switch (mapp) {
            case 0:    
                return "Chuva forte";
                break;
            case 1:    
                return "Chuva fraca ou sereno";
                break;
            case 2:    
                return "Não está chovendo";
                break;
        }
    }

    // Retorna o status atual da chuva em formato inteiro
    int getStatus(bool numeric = true){
        int medicao = getAnalogico();
        return map(medicao, 0, 4095, 0, 3);
    }
};

#endif