/*#ifndef TempSolo_h
#define TempSolo_h
#include "../classes/LeitorCartao.h"
#include <WiFi.h>

WiFiServer server(80);
class ServerESP32
{   
private:
    const char* ssid     = "MineStation";
    const char* password = "minestation123";
    
    String header;
    
public:
    ServerESP32(){
        WiFi.softAP(ssid, password);
    }

    void iniciarServidor(){
        server.begin();
    }

    IPAddress getIp(){
        return WiFi.softAPIP();
    }


  
};

#endif*/