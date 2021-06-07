#include "Chuva.h"

Chuva::Chuva(){
    atDados();
}

Chuva::Chuva(uint8_t dPin, uint8_t aPin){
    digitalPin = dPin;
    analogicoPin = aPin;
    atDados();
}

bool Chuva::getActive(){
    return active;
}
int Chuva::getAnalogico(){
    return analogico;
}
int Chuva::getDigital(){
    return digital;
}
String Chuva::getStatus(){
    return status;
}

void Chuva::atDados(){
    int a = touchRead(digital);
    if(a == 0){
            active = true;
    }
    else{
        active = false;
    }

    int vv = 0;
    for (int i = 0; i < 10; i++)
    {
        vv+= analogRead(analogicoPin);
    }

    analogico = vv/10;
    digital = digitalRead(digitalPin);

    int mapp = map(analogico, 0, 4095, 0, 3);

    switch (mapp) {
        case 0:    
            status = "Chuva forte";
            break;
        case 1:    
            status = "Chuva fraca ou sereno";
            break;
        case 2:    
            status = "Não está chovendo";
            break;
    }
};
