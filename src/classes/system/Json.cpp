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

void Json::merge(JsonDocument& dst, const JsonDocument& src) {
   for (auto kvp : src.as<JsonObjectConst>()) {
        dst[kvp.key()] = kvp.value();
    }

   String msg = "";
   serializeJson(dst, msg);

   Serial.println(msg);
   Serial.println("\n\n\n\n");
}
