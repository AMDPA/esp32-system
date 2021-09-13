#include "Json.h"

String JsonESP32::serialize(StaticJsonDocument<300> doc){
    String json = "";
    serializeJson(doc, json);

    return json;
}

StaticJsonDocument<300> JsonESP32::deserialize(String json){
    StaticJsonDocument<300> doc;
    deserializeJson(doc, json);

    return doc;
}

void JsonESP32::merge(JsonDocument& dst, const JsonDocument& src) {
   for (auto kvp : src.as<JsonObjectConst>()) {
        dst[kvp.key()] = kvp.value();
    }

   String msg = "";
   serializeJson(dst, msg);
}
