#include "LeitorCartao.h"

void LeitorCartao::initSD(){
    Serial.println("LeitorCartao::init()");
    init();
    while(!SD.begin(SD_CS));
}

void LeitorCartao::createFile(String path){
    Serial.println("LeitorCartao::createFile()");
    File file = SD.open(path, FILE_WRITE);
    file.close();
}

void LeitorCartao::writeFile(String path, String msg, bool reset){
    Serial.println("LeitorCartao::writeFile()");
    if(reset){
      SD.remove(path);
      createFile(path);
    }

    File file = SD.open(path, FILE_APPEND);
    file.print(msg);
    file.close();
}

String LeitorCartao::readFile(String path){
    Serial.println("LeitorCartao::readFile()");
     File file = SD.open(path, FILE_READ);
     String data = "";
     while(file.available()){
       data += file.readString();
     }

     file.close();
     return data;
}

bool LeitorCartao::fileExists(String path){
    Serial.println("LeitorCartao::fileExists()");
    if(SD.exists(path)){
        return true;
    }
    return false;
}