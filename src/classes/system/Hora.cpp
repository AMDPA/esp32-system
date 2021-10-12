#include "Hora.h"

void Hora::setUnixTimeStamp(int unixTimeStamp){
    Serial.println("Hora::setUnixTimeStamp()");
    timeval tv;
    tv.tv_sec = unixTimeStamp;
    settimeofday(&tv, NULL);
}

void Hora::updateHoraRede(){
    Serial.println("Hora::updateHoraRede()");

    WiFiUDP ntpUDP;
    NTPClient timeClient(ntpUDP, "0.br.pool.ntp.org");

    timeClient.begin();
    timeClient.setTimeOffset(-10800);
    while(!timeClient.update()) {
        timeClient.forceUpdate();
    }

    timeval tv;
    tv.tv_sec = timeClient.getEpochTime();
    settimeofday(&tv, NULL);
}

int Hora::getUnixTimeStamp(){
    Serial.println("Hora::getUnixTimeStamp()");
    time_t tt = time(NULL);
    return tt;
}

String Hora::getDataFull(){
    Serial.println("Hora::getDataFull()");
    time_t tt = time(NULL);
    data = *gmtime(&tt);
    char data_formatada[64];
    strftime(data_formatada, 64, "%Y-%m-%d %H:%M:%S", &data);

    return data_formatada;
}
String Hora::getData(){
    Serial.println("Hora::getData()");
     time_t tt = time(NULL);
    data = *gmtime(&tt);
    char data_formatada[64];
    strftime(data_formatada, 64, "%Y-%m-%d", &data);

    return data_formatada;
}
