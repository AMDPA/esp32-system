#include <Arduino.h>
#include <HTTPClient.h>

#include "classes/modules/Chuva/Chuva.h"
#include "classes/modules/CO2/Cjmcu.h"
#include "classes/modules/Hidrogenio/Hidrogenio.h"
#include "classes/modules/Luminosidade/Luminosidade.h"
#include "classes/modules/TempUmidAr/TempUmidAr.h"
#include "classes/modules/UmidSolo/UmidSolo.h"
#include "classes/modules/LeitorCartao/LeitorCartao.h"
#include "classes/modules/PH/Ph.h"
#include "classes/modules/TempSolo/TempSolo.h"

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
Ph _ph;
TempSolo _tempSolo;

Hora _hora;
JsonESP32 _json;
ServerESP32 _server;
Energia _energia;

void setup(){
    Serial.begin(115200);

    _energia.reestartSystemTokePin();
    _server.config();

    if(_energia.wakeup_reason == ESP_SLEEP_WAKEUP_TOUCHPAD || _server.user.length() == 0 || _server.id_esta == -1){
        _server.init(true);
        while(true);
    }

    if(_server.mode){
        _server.init();
        _hora.updateHoraRede();
    }

    _leitorCartao.initSD();
    _cjmcu.init();
    _hidrogenio.init();
    _luminosidade.init();
    _tempUmidAr.init();
    _umidSolo.init();
    _chuva.init();
    _ph.init();
    _tempSolo.init();
}

void loop(){
    _server.finish();

    _cjmcu.update();
    _hidrogenio.update();
    _luminosidade.update();
    _tempUmidAr.update();
    _umidSolo.update();
    _chuva.update();
    _ph.update();

    if(!_leitorCartao.fileExists("/" + _hora.getData() + ".json")){
        _leitorCartao.createFile("/" + _hora.getData() + ".json");
    }

    DynamicJsonDocument doc1(24576);

    JsonObject ssss = doc1.createNestedObject(String(_hora.getUnixTimeStamp()));
    ssss["hora"] = _hora.getUnixTimeStamp();
    ssss["dht11_temperatura"] = _tempUmidAr.getTemperature();
    ssss["dht11_umidade"] = _tempUmidAr.getHumidity();
    ssss["dht11_indiceCalor"] = _tempUmidAr.getHeatIndex();
    ssss["cjmcu101_luminosidade"] = _luminosidade.getPercent();
    ssss["soilmoisture_umidade"] = _umidSolo.getValue();
    ssss["ccs811_co2"] = _cjmcu.getEco2();
    ssss["ccs811_etvoc"] = _cjmcu.getEtvoc();
    ssss["mq8_hidrogenio"] = _hidrogenio.getPpm();
    ssss["mhrd_chuva"] = _chuva.getStatus();
    ssss["a18b20_temperatura"] = _tempSolo.getTemperatura();
    ssss["ph4502c_ph"] = _ph.getPh();
    ssss["mhz19b_co2"] = _cjmcu.getEco2();

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
    if(_server.mode){
        String _msg;
        serializeJson(doc1, _msg);
        _server.init();

/*
ADICIONAR SSL
*/

        HTTPClient http;
        http.begin("https://api-amacpa.herokuapp.com/");

        http.addHeader("Content-Type", "application/json");
        http.addHeader("User", _server.user);
        http.addHeader("Estacao", String(_server.id_esta));

        int code = http.POST(_msg);
        Serial.println(code);
        Serial.println(http.getString());
       if(code != 201){
           if(!_leitorCartao.fileExists("/enviardepois.txt")){
                _leitorCartao.createFile("/enviardepois.txt");
            }

            _leitorCartao.writeFile("/enviardepois.txt", _msg);
            _leitorCartao.writeFile("/enviardepois.txt", "\n");
       }
       else{
            if(_leitorCartao.fileExists("/enviardepois.txt")){
                 File file =  _leitorCartao.readFile("/enviardepois.txt", true);

                while (file.available())
                {
                    String e = file.readString();
                    http.POST(e);
                }

                _leitorCartao.delet("/enviardepois.txt");
            }
       }
        http.end();
    }

    _energia.setDeepSleep(15 * 60);
    //delay(5000);

}