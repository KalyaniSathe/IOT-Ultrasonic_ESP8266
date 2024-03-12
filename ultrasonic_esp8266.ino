#include <cogcloudesp8266.h>

String ssid = "akconnect";
String pass = "Ramnagarnashik";

String apikey = "dc9a99f431f49d895ec05764c8374ec6";

void setup() {
   Serial.begin(9600);
   cogInitCloud(ssid,pass,apikey);
    pinMode(D4, OUTPUT);
    pinMode(D8, INPUT);
}
void loop() 
{
  //cogAppLoop();
  long duration, cm;
  digitalWrite(D4, LOW);
  delay(2);
  digitalWrite(D4, HIGH);
  delay(1000);
  digitalWrite(D4, LOW);
  duration = pulseIn(D8, HIGH);
  cm = (duration/29/2);
  Serial.println(cm);
  cogStoreCloudVariable("Ultrasonic",String(cm));
}
