#ifndef BLE_h
#define BLE_h

#include <Arduino.h>

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <iostream>
#include <string>
 

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define DHTDATA_CHAR_UUID "6E400003-B5A3-F393-E0A9-E50E24DCCA9E" 

class Ble{
public:
    BLECharacteristic *pCharacteristic;
    bool deviceConnected = false;
    void con();
    
};
class BleServerCallbacks: public BLEServerCallbacks, public Ble{
    void onConnect(BLEServer* pServer);
    void onDisconnect(BLEServer* pServer);
};

class BleCallbacks: public BLECharacteristicCallbacks{
    void onWrite(BLECharacteristic *pCharacteristic);

};



#endif