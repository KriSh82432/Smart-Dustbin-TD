int relay = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  if(Serial.available()>0)
  {
    relay = Serial.parseInt();
  }
}
