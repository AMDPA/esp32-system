#include "Hidrogenio.h"

void Hidrogenio::init(){
    MQ8 = MQUnifiedsensor(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);
    MQ8.setRegressionMethod(1); 
    MQ8.setA(976.97); MQ8.setB(-0.688); 

    MQ8.init();   

    float calcR0 = 0;
    for(int i = 1; i<=10; i ++)
    {
        MQ8.update(); // Update data, the arduino will be read the voltage on the analog pin
        calcR0 += MQ8.calibrate(RatioMQ8CleanAir);
        Serial.print(".");
    }

    MQ8.setR0(calcR0/10);

}

void Hidrogenio::update(){
     MQ8.update();
     ppm = MQ8.readSensor();
}

float Hidrogenio::getPpm(){
    return ppm;
}