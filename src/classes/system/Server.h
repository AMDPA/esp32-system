#ifndef ServerESP32_h
#define ServerESP32_h

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

#include "Json.h"
#include "../modules/LeitorCartao/LeitorCartao.h"


class ServerESP32
{

public:
    AsyncWebServer server = AsyncWebServer(80);

    void init(String addr, String pass, bool ap = false);
    void finish();
    void serverPrint(String data);
    void call();

};

#endif