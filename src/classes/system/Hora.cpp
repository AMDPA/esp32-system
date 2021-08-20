#include "Hora.h"

void Hora::setUnixTimeStamp(int unixTimeStamp){
    timeval tv;
    tv.tv_sec = unixTimeStamp;
    settimeofday(&tv, NULL);
}

int Hora::getUnixTimeStamp(){
    time_t tt = time(NULL);
    return tt;
}

String Hora::getData(){
    time_t tt = time(NULL);
    data = *gmtime(&tt);
    char data_formatada[64];
    strftime(data_formatada, 64, "%Y-%m-%d %H:%M:%S", &data);

    return data_formatada;
}