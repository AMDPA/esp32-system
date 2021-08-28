#ifndef BLE_h
#define BLE_h

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <BLEServer.h>
#include <iostream>
#include <string>
#include <StringSplitter.h>

#include "../modules/LeitorCartao/LeitorCartao.h"

#define SERVICE_UUID           "3f247b34-07fc-11ec-9a03-0242ac130003"
#define CHARACTERISTIC_UUID_RX "3f247d64-07fc-11ec-9a03-0242ac130003"
#define MODO_OP_UUID           "3f247e4a-07fc-11ec-9a03-0242ac130003"
#define REDE_ADDR_UUID         "3f24803e-07fc-11ec-9a03-0242ac130003"
#define REDE_PASS_UUID         "3f248110-07fc-11ec-9a03-0242ac130003"

extern bool deviceConnected;
class Ble{

    public:
        void init();
        void sendValue(std::string value);
};

class MyServerCallbacks: public BLEServerCallbacks {
    private:
        void onConnect(BLEServer* pServer);
        void onDisconnect(BLEServer* pServer);
};

class MyCallbacks: public BLECharacteristicCallbacks {
    private:
        void onWrite(BLECharacteristic *pCharacteristic);
};

#endif