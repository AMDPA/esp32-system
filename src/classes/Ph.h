#include <Arduino.h>
#ifndef Ph_h
#define Ph_h

#include <Wire.h> 
int pHSense = 12;
int samples = 10;
float adc_resolution = 4095.0;

class Ph
{
private:
    /* data */
public:
    Ph(/* args */){

    }

    void Update(){
    int measurings=0;
  for (int i = 0; i < samples; i++)
  {
    measurings += analogRead(pHSense);
    delay(10);
  }
    float voltage = 5 / adc_resolution * measurings/samples;
    Serial.print("pH= ");
    Serial.println(ph(voltage));
    delay(3000);
    }

    float ph (float voltage) {
  return 7 + ((2.5 - voltage) / 0.18);
}
};
#endif