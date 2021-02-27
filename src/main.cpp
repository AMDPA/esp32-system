#include <Arduino.h>
#include <Wire.h>
#include "classes/TempSolo.h"
#include "classes/UmidSolo.h"
#include "classes/TempUmidAr.h"
#include "classes/Hidrogenio.h"
#include "classes/Chuva.h"
#include "classes/Cjmcu.h"
#include "classes/Luminosidade.h"
#include "classes/Ph.h"

TempSolo tempsolo;
UmidSolo umidSolo;
TempUmidAr tempUmidAr;
Hidrogenio hidrogenio;
Cjmcu cjmcu;
Chuva chuva;
Luminosidade l;

void setup() {
 Serial.begin(115200);

  //tempsolo = TempSolo(4);
  cjmcu = Cjmcu();
  umidSolo = UmidSolo(15);
  tempUmidAr = TempUmidAr();
  hidrogenio = Hidrogenio();
  chuva = Chuva();
  l = Luminosidade();

 
}

void loop() {
  //tempsolo.Update();
  cjmcu.Update();
  umidSolo.Update();
  tempUmidAr.Update();
  hidrogenio.Update();
  chuva.Update();
  l.Update();

  delay(2000);
  Serial.println("------------------------------------");
  
}
