#include "Hora.h"

void Hora::setUnixTimeStamp(int unixTimeStamp){
    timeval tv;
    tv.tv_sec = unixTimeStamp;
    settimeofday(&tv, NULL);
}

void Hora::updateHoraRede(){
    WiFiUDP ntpUDP;
    NTPClient timeClient(ntpUDP, "a.ntp.br", 3600, 60000);
    timeClient.begin();
    timeClient.update();

    timeval tv;
    tv.tv_sec = timeClient.getEpochTime();
    settimeofday(&tv, NULL);
}

int Hora::getUnixTimeStamp(){
    time_t tt = time(NULL);
    return tt;
}

String Hora::getDataFull(){
    time_t tt = time(NULL);
    data = *gmtime(&tt);
    char data_formatada[64];
    strftime(data_formatada, 64, "%Y-%m-%d %H:%M:%S", &data);

    return data_formatada;
}
String Hora::getData(){
     time_t tt = time(NULL);
    data = *gmtime(&tt);
    char data_formatada[64];
    strftime(data_formatada, 64, "%Y-%m-%d", &data);

    return data_formatada;
}
