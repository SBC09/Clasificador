#include <ThingerESP32.h>
#include <WiFi.h>
#include <ThingerWifi.h>
#define USERNAME "SBCPilas"
#define DEVICE_ID "Sensor"
#define DEVICE_CREDENTIAL "fE7mkTYE@jfl"
#define SSID "MiFibra-CB78-24G"
#define SSID_PASSWORD "cK7NdDT9"
const int Trigger = 26;   //Pin digital 2 para el Trigger del sensor
const int Echo = 25;  
ThingerESP32 thing(USERNAME,DEVICE_ID,DEVICE_CREDENTIAL);
void setup() {
  // put your setup code here, to run once:
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  
  thing.add_wifi(SSID,SSID_PASSWORD);
  thing["trigger"] << digitalPin(Trigger);
  thing["millis"] >> outputValue(millis());}

void loop() {
  // put your main code here, to run repeatedly:
thing.handle();
}
