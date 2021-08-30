#include <Arduino.h>

#include <ArduinoJson.h>

class Json{

public:
    String serialize(StaticJsonDocument<300> doc);
    StaticJsonDocument<300> deserialize(String json);
    void merge(JsonDocument& dst, const JsonDocument& src);
};