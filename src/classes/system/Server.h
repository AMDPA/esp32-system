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
    String m, rd, rp;

    void init(bool ap = false);
    void finish();
    void call();
    void config();

};

#endif