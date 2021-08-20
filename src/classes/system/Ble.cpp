#include "Ble.h"

void Ble::init(){
  BLEDevice::init("ESP32 AMACPA~AMDPA");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  //Envio de dados
  pCharacteristic = pService->createCharacteristic(DHTDATA_CHAR_UUID, BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->addDescriptor(new BLE2902());

  //Recebimento de dados
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
  pCharacteristic->setCallbacks(new MyCallbacks());

  //Ajusta Hora
  BLECharacteristic *hourCaracteristic = pService->createCharacteristic(HOUR_UUID, BLECharacteristic::PROPERTY_WRITE);
  hourCaracteristic->setCallbacks(new MyCallbacks());

  //Definir modo de Operação
  BLECharacteristic *operationCaracteristic = pService->createCharacteristic(OPERATION_UUID, BLECharacteristic::PROPERTY_WRITE);
  operationCaracteristic->setCallbacks(new MyCallbacks());

  pService->start();
  pServer->getAdvertising()->start();
}

void Ble::sendValue(std::string value){
  Serial.println("BLE");
  pCharacteristic->setValue(value);
  pCharacteristic->notify(); // Envia o valor para o aplicativo!
  Serial.print("*** Dado enviado: ");
  Serial.print(String(value.c_str()));
  Serial.println(" ***");
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

  if(cUUID == HOUR_UUID){
    Hora hora = Hora();
    hora.setUnixTimeStamp(String(rxValue.c_str()).toInt());
  }
  else if(cUUID == OPERATION_UUID){
    String d = String(rxValue.c_str());
    StringSplitter *splitter = new StringSplitter(d, ',', 3);

    if(String(splitter->getItemAtIndex(0)) == "WIFI"){
      String redeNome =  splitter->getItemAtIndex(1);
      String redePassword =  splitter->getItemAtIndex(2);
    }
  }
  else if(cUUID == ATUA_UUID){
    String d = String(rxValue.c_str());
    StringSplitter *splitter = new StringSplitter(d, ',', 3);

    if(String(splitter->getItemAtIndex(0)) == "DIA"){
      int time = String(splitter->getItemAtIndex(1)).toInt();
    }
    else{
      int id = String(splitter->getItemAtIndex(1)).toInt();
    }
  }
      Serial.println(rxValue[0]);

      if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.print("Received Value: ");

        for (int i = 0; i < rxValue.length(); i++) {
          Serial.print(rxValue[i]);
        }
        Serial.println();
        Serial.println("*********");
      }
      if (rxValue.find("A") != -1) {
        Serial.println("Turning ON!");
      }
      else if (rxValue.find("B") != -1) {
        Serial.println("Turning OFF!");
      }
}