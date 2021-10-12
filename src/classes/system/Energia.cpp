#include "Energia.h"

 void Energia::setDeepSleep(int segundos){
   Serial.println("Energia::setDeepSleep()");
    esp_sleep_enable_timer_wakeup(segundos * 1000000);
    touchAttachInterrupt(4, []{}, 40);
    esp_sleep_enable_touchpad_wakeup();
    esp_deep_sleep_start();
}

void Energia::reestartSystemTokePin(){
  Serial.println("Energia::reestartSystemTokePin()");
  wakeup_reason = esp_sleep_get_wakeup_cause();
}