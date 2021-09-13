#include <Arduino.h>

#include "classes/modules/Chuva/Chuva.h"
#include "classes/modules/CO2/Cjmcu.h"
#include "classes/modules/Hidrogenio/Hidrogenio.h"
#include "classes/modules/Luminosidade/Luminosidade.h"
#include "classes/modules/TempUmidAr/TempUmidAr.h"
#include "classes/modules/UmidSolo/UmidSolo.h"
#include "classes/modules/LeitorCartao/LeitorCartao.h"

#include "classes/system/Hora.h"
#include "classes/system/Server.h"
#include "classes/system/Energia.h"

LeitorCartao _leitorCartao;
Cjmcu _cjmcu;
Hidrogenio _hidrogenio;
Luminosidade _luminosidade;
TempUmidAr _tempUmidAr;
UmidSolo _umidSolo;
Chuva _chuva;

//Ble _ble;
Hora _hora;
JsonESP32 _json;
ServerESP32 _server;
Energia _energia;

void setup(){
    Serial.begin(115200);

    _energia.reestartSystemTokePin();
    if(_energia.wakeup_reason == ESP_SLEEP_WAKEUP_TOUCHPAD){
      _server.config();
      _server.init();
      while(true);
    }

    _leitorCartao.initSD();
    _cjmcu.init();
    _hidrogenio.init();
    _luminosidade.init();
    _tempUmidAr.init();
    _umidSolo.init();
}

void loop(){
    Serial.print("-");
   
    Serial.println("LOOP");
    _server.finish();
    _cjmcu.update();
    _hidrogenio.update();
    _luminosidade.update();
    _tempUmidAr.update();
    _umidSolo.update();

    if(!_leitorCartao.fileExists("/" + _hora.getData() + ".json")){
        _leitorCartao.createFile("/" + _hora.getData() + ".json");
    }

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

    String msg = _leitorCartao.readFile("/" + _hora.getData() + ".json");
    String msg2;
    if(msg.length() == 0){
        serializeJson(doc1, msg2);
    }
    else{
        DynamicJsonDocument doc(24576);
        DynamicJsonDocument docd(24576);

        deserializeJson(doc, msg);

        _json.merge(docd, doc);
        _json.merge(docd, doc1);

        serializeJson(docd, msg2);
    }

    _leitorCartao.writeFile("/" + _hora.getData() + ".json", msg2, true);
    Serial.println(msg2);

    if(_server.m.equals("REMOTO")){
        String _msg = msg2;
        serializeJson(doc1, msg);

        //Quando tiver um servidor, imprementar o envio de dados aqui. Submeter a var _msg;
    }

    _energia.setDeepSleep(15 * 60);

}

