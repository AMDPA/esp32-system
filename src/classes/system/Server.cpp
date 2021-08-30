#include "Server.h"

void ServerESP32::init(String addr, String pass, bool ap){

    if(!ap){
        WiFi.begin(addr.c_str(), pass.c_str());
        while(WiFi.status() != WL_CONNECTED);
        call();
        server.begin();
    }
    else{
        WiFi.softAP(addr.c_str(), pass.c_str(), 1, 0, 1);
        call();
        server.begin();
    }
}

void ServerESP32::finish(){
    WiFi.disconnect(true);  // Disconnect from the network
    WiFi.mode(WIFI_OFF);
}

void ServerESP32::serverPrint(String data){

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
        String data[3] = {request->pathArg(0), request->pathArg(1), request->pathArg(2)};

        LeitorCartao l;
        l.initSD();

        if(l.fileExists("/" + data[0] + "-" + data[1] + "-" + data[2] + ".json")){
            String msg = l.readFile("/" + data[0] + "-" + data[1] + "-" + data[2] + ".json");
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

        Json j;
        StaticJsonDocument<300> doc = j.deserialize(msg);

        doc["MODO_OP"] = m;
        doc["REDE_ADDR"] = rd;
        doc["REDE_PASS"] = rp;

        msg = j.serialize(doc);

        l.writeFile("/settings.json", msg, true);

        request->send(200, "application/json", "{\"msg\":\"ok\"}");
        ESP.restart();
    });
}