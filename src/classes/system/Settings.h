/*#ifndef Hora_h
#define Hora_h

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>

#include "LeitorCartao.h"

class Settings
{
    
public:
    struct Network{
        IPAddress ip      = IPAddress(192,168, 0, 1);
        IPAddress gateway = IPAddress(192, 168, 0, 1);
        IPAddress subnet  = IPAddress(255,  255, 255, 0);
        String ssid       = "ÀMDPA Station";
        String password   = "";

    };
    struct Station{
        String mode = "static";
        bool active = false;
    };

    LeitorCartao leitorCartao;

    Settings(){
        leitorCartao = LeitorCartao();
        if(!leitorCartao.arquivoExiste("/settings1.json")){
            Serial.println("Configuração inexistente. \n -------\n criando... \n -------");
            if(leitorCartao.criarArquivo("/settings1.json")){
                Serial.println(" \n -------\n Salvando... \n -------");
                String settJson = "{\"network\": {";                
                
                Network n;
                settJson += "\"ip\": \"" + n.ip.toString() + "\",";
                settJson += "\"gateway\": \"" + n.gateway.toString() + "\",";
                settJson += "\"subnet\": \"" + n.subnet.toString() + "\",";
                settJson += "\"ssid\": \"" + n.ssid + "\",";
                settJson += "\"password\": \"" + n.password+ "\"";
                settJson += "},";

                settJson += "{\"station\": {";

                Station s;
                settJson += "\"mode\": \"" + s.mode + "\",";
                settJson += "\"active\":" + s.active;
                settJson += "}}";

                if(leitorCartao.escreverArquivo("settings.json", settJson.c_str())){
                     Serial.println("Dados salvos com sucesso!!");
                }
            }
        }
    }
};

#endif*/