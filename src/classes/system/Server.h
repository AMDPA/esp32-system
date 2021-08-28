#ifndef ServerESP32_h
#define ServerESP32_h

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>


class ServerESP32
{

public:
    WiFiServer server = WiFiServer(80);

    void init(String addr, String pass, bool ap = false);
    void finish();
    void serverPrint(String data);

};

#endif