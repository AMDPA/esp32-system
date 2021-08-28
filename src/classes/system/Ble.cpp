#include "Ble.h"

void Ble::init(){
  BLEDevice::init("ESP32 AMACPA~AMDPA");

  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  BLECharacteristic *opCharacteristic = pService->createCharacteristic(MODO_OP_UUID, BLECharacteristic::PROPERTY_WRITE);
  opCharacteristic->setCallbacks(new MyCallbacks());

  BLECharacteristic *redeAddrCharacteristic = pService->createCharacteristic(REDE_ADDR_UUID, BLECharacteristic::PROPERTY_WRITE);
  redeAddrCharacteristic->setCallbacks(new MyCallbacks());

  BLECharacteristic *redePassCharacteristic = pService->createCharacteristic(REDE_PASS_UUID, BLECharacteristic::PROPERTY_WRITE);
  redePassCharacteristic->setCallbacks(new MyCallbacks());

  pService->start();
  pServer->getAdvertising()->start();
}

void MyServerCallbacks::onConnect(BLEServer* pServer){
  deviceConnected = true;
}

void MyServerCallbacks::onDisconnect(BLEServer* pServer){
  deviceConnected = false;
}

void MyCallbacks::onWrite(BLECharacteristic *pCharacteristic){
  std::string rxValue = pCharacteristic->getValue();
  std::string cUUID = pCharacteristic->getUUID().toString();

  if(cUUID == MODO_OP_UUID){

  }
  else if(cUUID == REDE_ADDR_UUID){

  }
  else if(cUUID == REDE_PASS_UUID){

  }
}