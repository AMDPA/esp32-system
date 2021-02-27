///
///
///Configurations: 
/// - Pino: scl(22),sda(21)
/// - Voltagem: 3.3v
///
///
#ifndef Cjmcu_h
#define Cjmcu_h

#include <Arduino.h>
#include <Adafruit_CCS811.h>
#include <SparkFunCCS811.h>
#define CCS811_ADDR 0x5A

Adafruit_CCS811 ccs;

class Cjmcu
{
  
public:
    Cjmcu()
    {
        ccs.begin();
    }
    
    void Update()
    {
        ccs.available();
        ccs.readData();
        Serial.print("CO2: ");
        Serial.print(ccs.geteCO2());
        Serial.print("ppm, TVOC: ");
        Serial.println(ccs.getTVOC());
        Serial.print("\n\n");
  }
};

#endif