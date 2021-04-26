/*
 LeitorCartao.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - CS   ---> GPIO 5
  - SCK  ---> GPIO 18
  - MOSI ---> GPIO 23
  - MISO ---> GPIO 19
  - VCC  ---> 5V ou 3V3
  - GND  ---> GND
*/

#ifndef LeitorCartao_h
#define LeitorCartao_h
           
#include <Arduino.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>

class LeitorCartao
{
private:
  uint8_t SD_CS = 5;

public:
  LeitorCartao();
  LeitorCartao(uint8_t pin);
  void createFile(String path);
  void writeFile(String path, String msg);
  String readFile(String path);
};

#endif