#include <WiFi.h>;
const char* ssid = "MiFibra-CB78-24G";
const char* password= "cK7NdDT9";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin (ssid, password);
  Serial.print("Conectado a WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {Serial.print(".");
  delay(500);}
  Serial.println("\nConectado  al WiFi de tu RED ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED)
  {//Serial.println("Haciendo Ping");
  delay(5000);}
  else{Serial.println("Conexion Perdida");}

}
