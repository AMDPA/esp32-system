#include "Chuva.h"

void Chuva::init(){
    Serial.println("Chuva::init()");
}

void Chuva::update(){
    Serial.println("Chuva::update()");
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
}

bool Chuva::getActive(){
    Serial.println("Chuva::getActive()");
    return active;
}
int Chuva::getAnalogico(){
    Serial.println("Chuva::getAnalogico()");
    return analogico;
}
int Chuva::getDigital(){
    Serial.println("Chuva::getDigital()");
    return digital;
}
String Chuva::getStatus(){
    Serial.println("Chuva::getStatus()");
    return status;
}