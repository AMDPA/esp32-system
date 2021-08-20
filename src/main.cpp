#include <Arduino.h>
#include <string.h>

//#include "classes/Chuva.h"
/*#include "classes/modules/CO2/Cjmcu.h"
#include "classes/modules/Hidrogenio/Hidrogenio.h"
#include "classes/modules/Luminosidade/Luminosidade.h"
#include "classes/modules/TempUmidAr/TempUmidAr.h"
#include "classes/modules/UmidSolo/UmidSolo.h"

#include "classes/modules/LeitorCartao/LeitorCartao.h"
#include "classes/system/Json.h"
//#include "classes/Ble.h"

Cjmcu cjmcu;
Hidrogenio hidrogenio;
Luminosidade luminosidade;
TempUmidAr tempUmidAr;
UmidSolo umidSolo;

LeitorCartao leitorCartao;

unsigned long millisLeitura = millis();

void setup(){
    Serial.begin(115200);

    //leitorCartao.initSD();

    cjmcu.init();
    hidrogenio.init();
    luminosidade.init();
    tempUmidAr.init();
    umidSolo.init();

    /*if(!leitorCartao.fileExists("/medicoes4.csv")){
        leitorCartao.createFile("/medicoes4.csv");
        leitorCartao.writeFile("/medicoes4.csv", "cjmcu_co2, cjmcu_etvoc, hidrogenio_ppm, luminosidade_percent, temUmidAr_humidity, tempUmidAr_temperature, tempUmidAr_heatIndex, umidSolo_percent\n");
    }*/
//}

/*void loop(){

    cjmcu.update();
    hidrogenio.update();
    luminosidade.update();
    tempUmidAr.update();
    umidSolo.update();

    if(millis() - millisLeitura >= 2000 ){
        String msg = "";

        msg += String(cjmcu.getEco2()) + ", ";
        msg += String(cjmcu.getEtvoc()) + ", ";

        msg += String(hidrogenio.getPpm()) + ", ";

        msg += String(luminosidade.getPercent()) + ", ";

        msg += String(tempUmidAr.getHumidity()) + ", ";
        msg += String(tempUmidAr.getTemperature()) + ", ";
        msg += String(tempUmidAr.getHeatIndex()) + ", ";

        msg += String(umidSolo.getValue()) + "\n";

        //leitorCartao.writeFile("/medicoes4.csv", msg);
        Serial.println(msg);
        millisLeitura = millis();
    }
}*/

/*
    Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleServer.cpp
    Ported to Arduino ESP32 by Evandro Copercini
    updates by chegewara
*/

/*#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID        "5bc6b4f0-ff87-11eb-9a03-0242ac130003"
#define CHARACTERISTIC_UUID "68c3bf90-ff87-11eb-9a03-0242ac130003"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("ESP32");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("Hello World says Neil");
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");

  int cont = 0;
  while(true){
      cont++;
      pCharacteristic->setValue(cont);
      delay(2000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}*/

#include "classes/system/Ble.h"

Ble ble;
bool deviceConnected = false;

void TaskRunningOnAppCore(void *arg) {
    while(1) {
       Serial.print("medições");
       vTaskDelay(5000);
    }
}

void TaskRunningOnProtocolCore(void *arg) {
    while(1) {
        Serial.println("BLE");
        if (deviceConnected) {
            ble.sendValue("TESTANDOOOOOOOO");
        }

        vTaskDelay(2000);
    }
}

void setup(){
    Serial.begin(115200);

    ble = Ble();
    ble.init();

    xTaskCreatePinnedToCore(TaskRunningOnProtocolCore, "TaskOnPro", 2048, NULL, 8, NULL, PRO_CPU_NUM);
}

void loop(){
    Serial.println(deviceConnected);
    delay(2500);
}

