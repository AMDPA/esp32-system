#include "Server.h"

void ServerESP32::init(String addr, String pass, bool ap){
    WiFi.disconnect(false);

    if(!ap){
        WiFi.mode(WIFI_STA);
        WiFi.begin(addr.c_str(), pass.c_str());
        while(!WiFi.isConnected());
    }
    else{
        WiFi.mode(WIFI_AP);
        WiFi.softAP(addr.c_str(), pass.c_str(), 1, 0, 1);
        server.begin();
        while(!server.available());

        Serial.println(WiFi.softAPIP());
    }
}

void ServerESP32::finish(){
    WiFi.disconnect(true);  // Disconnect from the network
    WiFi.mode(WIFI_OFF);
}

void ServerESP32::serverPrint(String data){

}