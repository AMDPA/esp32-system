#include "Server.h"

void ServerESP32::init(bool ap){
    Serial.println("ServerESP32::init()");
    if(ssid.length() != 0){
        if(!ap){
            //WiFi.mode(WIFI_MODE_STA);
            WiFi.begin(ssid.c_str(),pass.c_str());
            while(WiFi.status() != WL_CONNECTED);
        }
        else{
            //WiFi.mode(WIFI_AP);
            WiFi.softAP("AMDPA~AMACPA 001","HNCE5C10");
            WiFi.softAPConfig(IPAddress(192,168,4,1), IPAddress(192,168,4,1), IPAddress(255,255,255,0));

            call();
            server.begin();
        }
   }
    else{
        config();
    }
}

void ServerESP32::config(){
    Serial.println("ServerESP32::config()");
    LeitorCartao l;
    l.initSD();

   StaticJsonDocument<768> doc;
    if(l.fileExists("/settings.json")){

        String msg = l.readFile("/settings.json");
        deserializeJson(doc, msg);

        user = doc["user"].as<String>();
        id_esta = doc["estacao"].as<int>();
        mode = doc["isRemote"].as<bool>();
        ssid = doc["localRede"]["ssid"].as<String>();
        pass = doc["localRede"]["password"].as<String>();
    }
    else{
        doc["name"] = "";
        doc["description"] = "";
        doc["user"] = "";
        doc["estacao"] = -1;
        doc["isRemote"] = false;

        JsonESP32 _json;
        String r = _json.serialize(doc);
        l.createFile("/settings.json");
        l.writeFile("/settings.json", r, true);
        ESP.restart();
    }
}

void ServerESP32::finish(){
    Serial.println("ServerESP32::finish()");
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
}

void ServerESP32::call(){
    Serial.println("ServerESP32::call()");
    server.on("/", HTTP_GET, [] (AsyncWebServerRequest *request){
        request->send(200, "application/json", "{\"Info\":\"AMACPA and AMDPA cientifique project\"}");
    });

    server.on("/api/hora/", HTTP_POST, [] (AsyncWebServerRequest *request){
        Hora h;
        String s = request->getParam("HORA")->value();
        h.setUnixTimeStamp(s.toInt());

        request->send(200, "application/json", "{\"msg\":\"ok\"}");
    });

    server.on("/api/at/", HTTP_POST, [] (AsyncWebServerRequest *request){
        StaticJsonDocument<768> doc;
        LeitorCartao l;

        String data =  request->getParam("data")->value();

        l.initSD();
        l.writeFile("/settings.json", data, true);

        request->send(200, "application/json", "{\"msg\":\"ok\"}");
    });

    server.on("/rst/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "application/json", "{\"msg\":\"ok\"}");
        ESP.restart();
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
}