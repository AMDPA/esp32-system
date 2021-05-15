#include "LeitorCartao.h"

void LeitorCartao::initSD(){
    init();
    while(!SD.begin(SD_CS));
}

void LeitorCartao::createFile(String path){
    File file = SD.open(path, FILE_WRITE);
    file.close();
}

void LeitorCartao::writeFile(String path, String msg){
    File file = SD.open(path, FILE_APPEND);
    file.print(msg);
    file.close();
}

String LeitorCartao::readFile(String path){
     File file = SD.open(path, FILE_READ);
     String data = "";
     while(file.available()){
       data += file.readString();
     }

     file.close();
     return data;
}

bool LeitorCartao::fileExists(String path){
    File file = SD.open(path, FILE_READ);
    if(file){
        return true;
    }
    return false;
}