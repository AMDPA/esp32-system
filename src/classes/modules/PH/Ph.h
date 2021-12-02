/*
 Ph.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - To  ---> 
  - Do  ---> 
  - Po  ---> 
  - G1  ---> 
  - G2  ---> 
  - V+  ---> 
*/

#ifndef Ph_h
#define Ph_h

#include <Arduino.h>
#include <Wire.h>

class Ph
{
private:
  int pHSense = 32;
  int samples = 10;
  int pH_Value;
  float voltage;

public:
  void init();
  void update();
  float getPh();
};

#endif