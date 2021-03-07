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

uint8_t SD_CS = 5;
class LeitorCartao
{

public:
  /// Construtor padrão, GPIO ---> 5
  LeitorCartao(){
    init();
  }

  /// Construtor, Definir GPIO
  LeitorCartao(uint8_t ssPin){
    SD_CS = ssPin;
    init();
  }

private:
  /// Inicializar SDCard
  bool init(){
    int cont = 0;
    while (!SD.begin(SD_CS))
      {
        Serial.println("Não foi possivel montar o SDCard");
        Serial.println("Tentando novamente");
        
        if(cont > 10){
          Serial.println("\nMáximo de Tentativas alcançado!");
          break;
          return false;  
        }
        cont++;
        delay(1000);
      }
    return true;
  }

public:
  /// Criar Arquivo em SDCard
  bool criarArquivo(const char * path){
    Serial.printf("Criando arquivo: %s\n", path);
    File file = SD.open(path, FILE_WRITE);
  
    if(!file) {
      Serial.println("Não foi possivel criar o arquivo.");
      
      file.close();
      return false;
    }

    file.close();
    return true; 
  }

  /// Escrever em arquivo no SDCard
  bool escreverArquivo(const char * path, const char * message){
    Serial.printf("Escrevendo mensagem %s\n, no arquivo %s\n", message, path);
    File file = SD.open(path, FILE_APPEND);

    if(!file) {
      Serial.println("Não foi possivel abrir o arquivo.");
      
      file.close();
      return false;
    }

    if(file.print(message)){
      Serial.println("Mensagem escrita!");
    }
    else{
      Serial.println("Erro ao escrever mensagem.");
      
      file.close();
      return false;
    }
    
    file.close();
    return true; 
  }

  /// Ler arquivo em SDCard
  String lerArquivo(const char * path){
     File file = SD.open(path, FILE_READ);
     String data = "";
     while(file.available()){
       data += file.readString();
     }

     file.close();
     return data;
  }
};

#endif