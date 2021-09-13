#include <Arduino.h>

#include <ArduinoJson.h>

class JsonESP32{

public:
    String serialize(StaticJsonDocument<300> doc);
    StaticJsonDocument<300> deserialize(String json);
    void merge(JsonDocument& dst, const JsonDocument& src);
};