#include "Hidrogenio.h"

Hidrogenio::Hidrogenio(){
       pinMode(pin, INPUT);
       value = analogRead(pin);
}

Hidrogenio::Hidrogenio(uint8_t p){
    pin = p;
    pinMode(pin, INPUT); 
    value = analogRead(pin);  
}

int Hidrogenio::getValue(){
    return value;
}