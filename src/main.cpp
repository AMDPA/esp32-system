#include <Arduino.h>

#include "classes/LeitorCartao.h"

void setup(){
  Serial.begin(115200);
  LeitorCartao l = LeitorCartao();
  LeitorCartao(5);
  
}

void loop(){
}