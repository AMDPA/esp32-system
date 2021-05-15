#include <Arduino.h>

#include <ArduinoJson.h>

class Json{

public:
    Json();
    String serialize(StaticJsonDocument<300> doc);
    StaticJsonDocument<300> deserialize(String json);
};