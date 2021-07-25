#include <Arduino.h>

//#include "classes/Chuva.h"
#include "classes/modules/CO2/Cjmcu.h"
#include "classes/modules/Hidrogenio/Hidrogenio.h"
#include "classes/modules/Luminosidade/Luminosidade.h"
#include "classes/modules/TempUmidAr/TempUmidAr.h"
#include "classes/modules/UmidSolo/UmidSolo.h"

#include "classes/modules/LeitorCartao/LeitorCartao.h"
#include "classes/system/Json.h"
//#include "classes/Ble.h"

Cjmcu cjmcu;
Hidrogenio hidrogenio;
Luminosidade luminosidade;
TempUmidAr tempUmidAr;
UmidSolo umidSolo;

LeitorCartao leitorCartao;

unsigned long millisLeitura = millis();

void setup(){
    Serial.begin(115200);

    //leitorCartao.initSD();

    cjmcu.init();
    hidrogenio.init();
    luminosidade.init();
    tempUmidAr.init();
    umidSolo.init();

    /*if(!leitorCartao.fileExists("/medicoes4.csv")){
        leitorCartao.createFile("/medicoes4.csv");
        leitorCartao.writeFile("/medicoes4.csv", "cjmcu_co2, cjmcu_etvoc, hidrogenio_ppm, luminosidade_percent, temUmidAr_humidity, tempUmidAr_temperature, tempUmidAr_heatIndex, umidSolo_percent\n");
    }*/
}

void loop(){

    cjmcu.update();
    hidrogenio.update();
    luminosidade.update();
    tempUmidAr.update();
    umidSolo.update();

    if(millis() - millisLeitura >= 2000 ){
        String msg = "";

        msg += String(cjmcu.getEco2()) + ", ";
        msg += String(cjmcu.getEtvoc()) + ", ";

        msg += String(hidrogenio.getPpm()) + ", ";

        msg += String(luminosidade.getPercent()) + ", ";

        msg += String(tempUmidAr.getHumidity()) + ", ";
        msg += String(tempUmidAr.getTemperature()) + ", ";
        msg += String(tempUmidAr.getHeatIndex()) + ", ";

        msg += String(umidSolo.getValue()) + "\n";

        //leitorCartao.writeFile("/medicoes4.csv", msg);
        Serial.println(msg);
        millisLeitura = millis();
    }
}