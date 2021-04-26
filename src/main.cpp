#include <Arduino.h>
#include <WiFi.h>

IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

#include "classes/Settings.h"
//Settings settings;

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

 

void setup()
{
  Serial.begin(115200);
  // Inicializa o sistema e carrega dados importantes. 
 // Serial.println("INICIANDO...\n");
  //settings = Settings();

  /*Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP("ESPsoftAP_01") ? "Ready" : "Failed!");

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());*/

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
                settJson += "\"active\":" +  s.active;
                settJson += "}}";

                Serial.println(settJson);
                Serial.println(settJson.c_str());
}

void loop()
{

}