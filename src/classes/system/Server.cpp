#include "Server.h"

void ServerESP32::init(bool ap){
    if(m.length() != 0){
        if(!ap){
            //WiFi.mode(WIFI_MODE_STA);
            WiFi.begin(rd.c_str(),rp.c_str());
            while(WiFi.status() != WL_CONNECTED);
        }
        else{
            //WiFi.mode(WIFI_MODE_AP);
            WiFi.softAP(rd.c_str(),rp.c_str());
        }
    }
    else{
        config();
    }

    call();
    server.begin();
}

void ServerESP32::config(){
    LeitorCartao l;
    l.initSD();

    StaticJsonDocument<300> doc;
    if(l.fileExists("/settings.json")){

        String msg = l.readFile("/settings.json");
        deserializeJson(doc, msg);

        m = doc["MODO_OP"].as<String>();
        rd = doc["REDE_ADDR"].as<String>();
        rp = doc["REDE_PASS"].as<String>();

        if(m.equals("REMOTO")){
            init();
            Hora h;
            h.updateHoraRede();
        }
        else{
            init(true);
        }
    }
    else{
        doc["MODO_OP"] = "LOCAL";
        doc["REDE_ADDR"] = "esp32 001";
        doc["REDE_PASS"] = "ESPDEFAULT";
        JsonESP32 _json;
        String r = _json.serialize(doc);
        l.createFile("/settings.json");
        l.writeFile("/settings.json", r, true);
        ESP.restart();
    }

}

void ServerESP32::finish(){
    WiFi.disconnect(true);  // Disconnect from the network
    WiFi.mode(WIFI_OFF);
}

void ServerESP32::call(){
    server.on("/", HTTP_GET, [] (AsyncWebServerRequest *request){
        request->send(200, "application/json", "{\"Info\":\"AMACPA and AMDPA cientifique project\"}");
    });

    server.on("^\\/api\\/hora\\/([0-9]+)$", HTTP_POST, [] (AsyncWebServerRequest *request){
        Hora h;
        String s = request->pathArg(0);
        h.setUnixTimeStamp(s.toInt());

        request->send(200, "application/json", "{\"msg\":\"ok\"}");
    });

    server.on("^\\/api\\/data\\/([0-9]+)\\/([0-9]+)\\/([0-9]+)$", HTTP_GET, [] (AsyncWebServerRequest *request){
        LeitorCartao l;
        l.initSD();

        if(l.fileExists("/" + request->pathArg(0) + "-" + request->pathArg(1) + "-" + request->pathArg(2) + ".json")){
            String msg = l.readFile("/" + request->pathArg(0) + "-" + request->pathArg(1) + "-" + request->pathArg(2) + ".json");
            request->send(200, "application/json", msg);
        }
        else{
            request->send(404, "application/json", "{'msg': 'not_found'}");
        }
    });

    server.on("/api/at/", HTTP_POST, [] (AsyncWebServerRequest *request){
        String m = request->getParam("MODO_OP")->value();
        String rd = request->getParam("REDE_ADDR")->value();
        String rp = request->getParam("REDE_PASS")->value();

        LeitorCartao l;
        l.initSD();

        String msg = l.readFile("/settings.json");

        JsonESP32 j;
        StaticJsonDocument<300> doc = j.deserialize(msg);

        doc["MODO_OP"] = m;
        doc["REDE_ADDR"] = rd;
        doc["REDE_PASS"] = rp;

        msg = j.serialize(doc);

        l.writeFile("/settings.json", msg, true);

        request->send(200, "application/json", "{\"msg\":\"ok\"}");
        ESP.restart();
    });

    server.on("/rst", HTTP_GET, [](AsyncWebServerRequest *request){
        ESP.restart();
    });
}