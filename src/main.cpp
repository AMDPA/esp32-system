#include <Arduino.h>

#include "esp32/Energia.h"
#include "esp32/Hora.h"

#include "classes/Luminosidade.h"
#include "classes/TempUmidAr.h"
#include "classes/LeitorCartao.h"
#include "classes/Ph.h"

#include <SPI.h>
#include <FS.h>
#include <SD.h>

/*Luminosidade l;
TempUmidAr um;
//LeitorCartao aa;
//Ph h;

void setup(){
  delay(10000);
  Serial.begin(115200);
  l = Luminosidade();
  um = TempUmidAr();
  //aa = LeitorCartao();
  h = Ph();
}

void loop(){
//l.Update();
//um.Update();
//delay(2000); 
//aa.writeFile(SD, "/data.txt", "Reading ID, Date, Hour, Temperature \r\n");
h.Update();
}*/

#include <WiFi.h>

LeitorCartao l;
void setup(){
  //l = LeitorCartao();
  Serial.begin(115200);
  
}

void loop(){
int adcValue = analogRead(25);
  float phVoltag = (float) adcValue * (3.3 / 4095);
  Serial.print("ADC = "); Serial.println(adcValue);
  Serial.print("Po = "); Serial.println(phVoltag);

  String dataMe;
  dataMe = String(adcValue) + ", " + String(phVoltag) + ", \r\n"; 
  l.appendFile(SD, "/datalog_ESP32.txt", dataMe.c_str());
  delay(5000);
}