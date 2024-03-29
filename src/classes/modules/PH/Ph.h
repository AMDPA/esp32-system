/*
 Ph.h - Arquivo incluso no projeto ÀMDPA - 2021

 Configurações (Padrão):
  - To  ---> 
  - Do  ---> 
  - Po  ---> GPIO32
  - G1  ---> 
  - G2  ---> GND
  - V+  ---> 5v
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
  int pH_Value = 0;
  float voltage = 0;

public:
  void init();
  void update();
  float getPh();
};

#endif