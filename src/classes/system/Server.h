#ifndef ServerESP32_h
#define ServerESP32_h

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

#include "Json.h"
#include "Hora.h"
#include "../modules/LeitorCartao/LeitorCartao.h"

class ServerESP32
{

public:
    AsyncWebServer server = AsyncWebServer(80);
    bool mode;
    String ssid;
    String pass;
    String user;
    int id_esta;

    void init(bool ap = false);
    void finish();
    void call();
    void config();

};

#endif