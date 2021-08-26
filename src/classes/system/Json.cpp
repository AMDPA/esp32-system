#include "Json.h"

String Json::serialize(StaticJsonDocument<300> doc){
    String json = "";
    serializeJson(doc, json);

    return json;
}

StaticJsonDocument<300> Json::deserialize(String json){
    StaticJsonDocument<300> doc;
    deserializeJson(doc, json);

    return doc;
}