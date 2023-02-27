#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "hT6OJysyRpkyaoybV5Bc3VAeYvpvgKyK";
char ssid[] = "Yohan's iPhone";
char pass[] = "123yohqn";

String buffer = "";
int buffer_vals[2];

int garbage_level = 0;
int object_distance = 0;
int object_status = 0;
int relay = 0;

BLYNK_WRITE(V6) {
  relay = param.asInt();
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    buffer = Serial.readString();
    buffer_vals = atoi(strtok(buffer, ','))
    garbage_level = buffer_vals[0];
    object_distance = buffer_vals[1];
    
    // garbage_level = atoi(buffer.subString(0, 3));
    // object_distance = atoi(buffer.subString(4));
    if(object_distance>0)
    {
      object_status = 1;
    }
    else
    {
      object_status = 0;
    }
  }
  Blynk.virtualWrite(V7, object_status);
  Blynk.virtualWrite(V4, garbage_level);
  Blynk.virtualWrite(V5, object_distance);
  Serial.println(relay);
}
