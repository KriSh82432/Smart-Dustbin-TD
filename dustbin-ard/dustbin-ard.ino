#include <NewPing.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define TRIGGER_PIN_TOP 11
#define ECHO_PIN_TOP 10
#define TRIGGER_PIN_FRONT 9
#define ECHO_PIN_FRONT 8

#define MAX_DISTANCE_TOP 16
#define MAX_DISTANCE_FRONT 47

#define SERVO_PIN 9

#define TX_EXT 4
#define RX_EXT 5

NewPing topSonar(TRIGGER_PIN_TOP, ECHO_PIN_TOP, MAX_DISTANCE_TOP);
NewPing frontSonar(TRIGGER_PIN_FRONT, ECHO_PIN_FRONT, MAX_DISTANCE_FRONT);

Servo garbageDoor;

SoftwareSerial espSerial(RX_EXT, TX_EXT);

long pingTop()
{
  return topSonar.ping_cm(); 
}

long pingFront()
{
  return frontSonar.ping_cm();
}

void setup()
{
  Serial.begin(115200);
  garbageDoor.attach(SERVO_PIN);
  while (!Serial) {
  ;
  }
}

void loop()
{
  delay(50);
  Serial.print("Garbage Level: ");
  Serial.print(pingTop());
  Serial.println(" cm");
  delay(50);
  Serial.print("Object Distance: ");
  Serial.print(pingFront());
  Serial.println(" cm");
}