#include <Arduino.h>

/*#include "classes/modules/Chuva/Chuva.h"
#include "classes/modules/CO2/Cjmcu.h"
#include "classes/modules/Hidrogenio/Hidrogenio.h"
#include "classes/modules/Luminosidade/Luminosidade.h"
#include "classes/modules/TempUmidAr/TempUmidAr.h"
#include "classes/modules/UmidSolo/UmidSolo.h"
#include "classes/modules/LeitorCartao/LeitorCartao.h"

#include "classes/system/Hora.h"
#include "classes/system/Server.h"

LeitorCartao _leitorCartao;
Cjmcu _cjmcu;
Hidrogenio _hidrogenio;
Luminosidade _luminosidade;
TempUmidAr _tempUmidAr;
UmidSolo _umidSolo;

//Ble _ble;
Hora _hora;
Json _json;
ServerESP32 _server;

String m, rd, rp, msg = "";

unsigned long millisLeitura = millis();

void setup(){
    Serial.begin(115200);

    _leitorCartao.initSD();

    StaticJsonDocument<300> doc;

    if(_leitorCartao.fileExists("/settings.json")){

        m = doc["MODO_OP"].as<String>();
        rd = doc["REDE_ADDR"].as<String>();
        rp = doc["REDE_PASS"].as<String>();

        if(m.equals("REMOTO")){
            _server.init(rd, rp);
            _hora.updateHoraRede();
        }
    }
    else{
        doc["MODO_OP"] = "LOCAL";
        doc["REDE_ADDR"] = "esp32 001";
        doc["REDE_PASS"] = "ESPDEFAULT";

        String r = _json.serialize(doc);
        _leitorCartao.createFile("/settings.json");
        _leitorCartao.writeFile("/settings.json", r, true);
        ESP.restart();
    }

    _cjmcu.init();
    _hidrogenio.init();
    _luminosidade.init();
    _tempUmidAr.init();
    _umidSolo.init();

}

void loop(){
    if(millis() - millisLeitura >= 10000 ){
        _server.finish();

        _cjmcu.update();
        _hidrogenio.update();
        _luminosidade.update();
        _tempUmidAr.update();
        _umidSolo.update();

        if(!_leitorCartao.fileExists("/" + _hora.getData() + ".json")){
            _leitorCartao.createFile("/" + _hora.getData() + ".json");
            //_leitorCartao.writeFile("/" + _hora.getData() + ".json", "[{\"hora\": \"f\",\"cjmcu\": {\"eco2\": 0.0,\"etvoc\": 0.0},\"hidrogenio\": 0.0,\"luminosidade\": 0.0,\"tempUmidAr\": {\"umidade\": 0.0,\"temperatura\": 0.0,\"heatIndex\": 0.0}}]");
        }

        msg = _leitorCartao.readFile("/" + _hora.getData() + ".json");

        DynamicJsonDocument doc1(24576);

        JsonObject doc_0 = doc1.createNestedObject(String(_hora.getUnixTimeStamp()));
        doc_0["hora"] = _hora.getDataFull();

        JsonObject doc_0_cjmcu = doc_0.createNestedObject("cjmcu");
        doc_0_cjmcu["eco2"] = _cjmcu.getEco2();
        doc_0_cjmcu["etvoc"] = _cjmcu.getEtvoc();

        doc_0["hidrogenio"] = _hidrogenio.getPpm();
        doc_0["luminosidade"] = _luminosidade.getPercent();

        JsonObject doc_0_tempUmidAr = doc_0.createNestedObject("tempUmidAr");
        doc_0_tempUmidAr["umidade"] = _tempUmidAr.getHumidity();
        doc_0_tempUmidAr["temperatura"] = _tempUmidAr.getTemperature();
        doc_0_tempUmidAr["heatIndex"] = _tempUmidAr.getHeatIndex();

        if(msg.length() == 0){
            serializeJson(doc1, msg);
        }
        else{
            DynamicJsonDocument doc(24576);
            DynamicJsonDocument docd(24576);

            deserializeJson(doc, msg);

            _json.merge(docd, doc);
            _json.merge(docd, doc1);

            serializeJson(docd, msg);
        }

        _leitorCartao.writeFile("/" + _hora.getData() + ".json", msg, true);

        if(m.equals("REMOTO")){
            _server.init(rd, rp);
        }
        Serial.println(msg);
        Serial.println("\n\n\n\n");
        millisLeitura = millis();
    }
}*/

void setup(){
    Serial.begin(115200);
}

void loop(){
    
}