#include <Arduino.h>

#include "classes/modules/Chuva/Chuva.h"
#include "classes/modules/CO2/Cjmcu.h"
#include "classes/modules/Hidrogenio/Hidrogenio.h"
#include "classes/modules/Luminosidade/Luminosidade.h"
#include "classes/modules/TempUmidAr/TempUmidAr.h"
#include "classes/modules/UmidSolo/UmidSolo.h"
#include "classes/modules/LeitorCartao/LeitorCartao.h"

#include "classes/system/Json.h"
#include "classes/system/Ble.h"
#include "classes/system/Hora.h"
#include "classes/system/Server.h"

LeitorCartao _leitorCartao;
Cjmcu _cjmcu;
Hidrogenio _hidrogenio;
Luminosidade _luminosidade;
TempUmidAr _tempUmidAr;
UmidSolo _umidSolo;

Ble _ble;
Hora _hora;
Json _json;
ServerESP32 _server;

unsigned long millisLeitura = millis();
bool deviceConnected = false;

void setup(){
    Serial.begin(115200);

    _leitorCartao.initSD();

    if(_leitorCartao.fileExists("/settings.json")){
        String msg = _leitorCartao.readFile("/settings.json");
        StaticJsonDocument<300> doc = _json.deserialize(msg);

        if(doc["MODO_OP"] == "REMOTO"){
            _server.init(doc["REDE_ADDR"], doc["REDE_PASS"]);
            _hora.updateHoraRede();
        }
        else{
            _server.init(doc["REDE_ADDR"], doc["REDE_PASS"], true);
        }
    }
    else{
        _ble.init();
    }

    _cjmcu.init();
    _hidrogenio.init();
    _luminosidade.init();
    _tempUmidAr.init();
    _umidSolo.init();

    _ble.init();
}

void loop(){
    if(millis() - millisLeitura >= 2000 ){
        _cjmcu.update();
        _hidrogenio.update();
        _luminosidade.update();
        _tempUmidAr.update();
        _umidSolo.update();

        String msg = "";

        msg += String(_hora.getUnixTimeStamp()) + ", ";
        msg += String(_hora.getDataFull()) + ", ";

        msg += String(_cjmcu.getEco2()) + ", ";
        msg += String(_cjmcu.getEtvoc()) + ", ";

        msg += String(_hidrogenio.getPpm()) + ", ";

        msg += String(_luminosidade.getPercent()) + ", ";

        msg += String(_tempUmidAr.getHumidity()) + ", ";
        msg += String(_tempUmidAr.getTemperature()) + ", ";
        msg += String(_tempUmidAr.getHeatIndex()) + ", ";

        msg += String(_umidSolo.getValue()) + "\n";

        if(!_leitorCartao.fileExists("/" + _hora.getData() + ".csv")){
            _leitorCartao.createFile("/" + _hora.getData() + ".csv");
            _leitorCartao.writeFile("/" + _hora.getData() + ".csv", "unix, data, cjmcu_co2, cjmcu_etvoc, hidrogenio_ppm, luminosidade_percent, temUmidAr_humidity, tempUmidAr_temperature, tempUmidAr_heatIndex, umidSolo_percent\n");
        }

        _leitorCartao.writeFile("/" + _hora.getData() + ".csv", msg);
        millisLeitura = millis();

        Serial.println(msg);
    }
}