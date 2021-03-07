#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
OneWire pino(14);
DallasTemperature barramento(&pino);
DeviceAddress sensor;
void setup(void)
{
  Serial.begin(115200);
  pinMode(14, INPUT);
  barramento.begin();
  barramento.getAddress(sensor, 0);  
}
void loop()
{
  barramento.requestTemperatures(); 
  float temperatura = barramento.getTempC(sensor);
  Serial.print(temperatura);
  delay(500);
}