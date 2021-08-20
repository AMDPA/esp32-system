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

#include "Hora.h"

#define SERVICE_UUID           "f9d4045a-ff8b-11eb-9a03-0242ac130003"
#define CHARACTERISTIC_UUID_RX "f9d40860-ff8b-11eb-9a03-0242ac130003"
#define DHTDATA_CHAR_UUID      "f9d40982-ff8b-11eb-9a03-0242ac130003"
#define HOUR_UUID              "9fbc90f6-01f0-11ec-9a03-0242ac130003"
#define OPERATION_UUID         "fa0b0f5a-01f6-11ec-9a03-0242ac130003"
#define ATUA_UUID              "654b1b18-01ff-11ec-9a03-0242ac130003"

extern bool deviceConnected;
class Ble{
    private:
        BLECharacteristic *pCharacteristic;

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