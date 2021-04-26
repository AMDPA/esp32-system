#include <Arduino.h>
#include <WiFi.h>

#include "classes/Chuva.h"
#include "classes/Cjmcu.h"
#include "classes/Hidrogenio.h"
#include "classes/Luminosidade.h"
#include "classes/TempUmidAr.h"
#include "classes/UmidSolo.h"

#include "classes/LeitorCartao.h"

LeitorCartao l = LeitorCartao();
void setup()
{
 Serial.begin(115200);
 delay(10000);
 Serial.println("INICIAL...");
 l.createFile("/test.txt");
}

void loop()
{
    Chuva chuva = Chuva();
    Cjmcu cjmcu = Cjmcu();
    Hidrogenio hidrogenio = Hidrogenio();
    Luminosidade luminosidade = Luminosidade();
    TempUmidAr tempUmidAr = TempUmidAr();
    UmidSolo umidSolo = UmidSolo();

    delay(2000);
    Serial.println("----Chuva----");
   
    Serial.print("Active: ");
    Serial.println(chuva.getActive());
    
    Serial.print("Analogico: ");
    Serial.println(chuva.getAnalogico());
   
    Serial.print("Digital: ");
    Serial.println(chuva.getDigital());
    
    Serial.print("Status: ");
    Serial.println(chuva.getStatus());

    Serial.println("-------------\n");

    delay(2000);
    Serial.println("----Cjmcu----");
    
    Serial.print("ECO2:");
    Serial.println(cjmcu.getEco2());
   
    Serial.print("Errstat: ");
    Serial.println(cjmcu.getErrstat());
    
    Serial.print("Etvoc: ");
    Serial.println(cjmcu.getEtvoc());
   
    Serial.print("Raw: ");
    Serial.println(cjmcu.getRaw());
    Serial.println("-------------\n");

    delay(2000);
    Serial.println("----Hidrogenio----");
    
    Serial.print("Value: ");
    Serial.println(hidrogenio.getValue());
    
    Serial.println("-------------\n");

    delay(2000);
    Serial.println("----Luminosidade----");
    
    Serial.print("Value: ");
    Serial.println(luminosidade.getValue());
    Serial.print("Percent: ");
    Serial.println(luminosidade.getPercent());
    Serial.println("-------------\n");

    delay(2000);
    Serial.println("----TempUmidAr----");
    
    Serial.print("HeatIndex: ");
    Serial.println(tempUmidAr.getHeatIndex());
    Serial.print("Humidity: ");
    Serial.println(tempUmidAr.getHumidity());
    Serial.print("Temperature: ");
    Serial.println(tempUmidAr.getTemperature());
    Serial.println("-------------\n");

    delay(2000);
    Serial.println("----UmidSolo----");
    
    Serial.print("Value: ");
    Serial.println(umidSolo.getValue());
    Serial.println("-------------\n");

    String msg = "";
    msg+= "active: " + String(chuva.getActive());
    msg+= "\nanalogico: " + String(chuva.getAnalogico());
    msg+= "\ndigital: " + String(chuva.getDigital());
    msg+= "\nstatus: " + String(chuva.getStatus());
    msg+= "\nECO2: " + String(cjmcu.getEco2());
    msg+= "\nErrstat: " + String(cjmcu.getErrstat());
    msg+= "\nEtvoc: " + String(cjmcu.getEtvoc());
    msg+= "\nRaw: " + String(cjmcu.getRaw());
    msg+= "\nvalue: " + String(hidrogenio.getValue());
    msg+= "\nvalue: " + String(luminosidade.getValue());
    msg+= "\npercent: " + String(luminosidade.getPercent());
    msg+= "\n HeatIndex: " + String(tempUmidAr.getHeatIndex());
    msg+= "\nHumidity: " + String(tempUmidAr.getHumidity());
    msg+= "\nTemperature: " + String(tempUmidAr.getTemperature());
    msg+= "\nValue: " + umidSolo.getValue();

    l.writeFile("/test.txt", msg);
}