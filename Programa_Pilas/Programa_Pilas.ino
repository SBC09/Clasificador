#include <Wire.h>//Sensores
#include <LiquidCrystal_I2C.h>// LCD
#include <ThingerESP32.h>//IOT
#include <WiFi.h>//WIFI
#include <ThingerWifi.h>//WIFI
//Credenciales de IOT
#define USERNAME "SBCPilas"
#define DEVICE_ID "Sensor"
#define DEVICE_CREDENTIAL "fE7mkTYE@jfl"

//Credenciales WiFi
#define SSID "MiFibra-CB78-24G"
#define SSID_PASSWORD "cK7NdDT9"
//Variables
void calcular_tipo_de_pila (int distancia);
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int Trigger = 26;   //Pin digital 26 para el Trigger del sensor
const int Echo = 25;   //Pin digital 25 para el Echo del sensor
int distancia,tiempo;
String Tipo=" ";
ThingerESP32 thing(USERNAME,DEVICE_ID,DEVICE_CREDENTIAL);


void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
   // Inicializar el LCD
  lcd.init();bkl
   
  //Encender la luz de fondo.
  lcd.backlight();
  thing.add_wifi(SSID,SSID_PASSWORD);
// thing["distancia"] << digitalPin(distancia);
  thing["sensores"] >> [](pson & out) {
      out["Distancia"] = distancia;
      out["Tipo"]= Tipo;
      
  };

}

void loop() {
  // put your main code here, to run repeatedly:
  
  thing.handle();
  lcd.clear();
  Tipo="Null";
  //lcd.print("Distancia:");
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  tiempo = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  distancia = tiempo/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(distancia);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(10);          //Hacemos una pausa de 100ms
   // lcd.setCursor(0, 1);
  // Escribimos el número de segundos trascurridos
  
  //lcd.print(distancia);
 
  //lcd.print(" cm");*/
  if (distancia<=40)
    calcular_tipo_de_pila(distancia);
  
  
  delay(10);
  
 

  
}
void calcular_tipo_de_pila (int distancia)
{
  if(distancia >=10 && distancia <=19){
  lcd.setCursor(0, 0);
  lcd.print("Tipo:AA");
  lcd.setCursor(0, 1);
  lcd.print("Puntos:10");
  Tipo="AA";
  
  }
  else if (distancia >= 20&& distancia <=25)
  { lcd.setCursor(0, 0);
    lcd.print("Tipo:AAA");
    lcd.setCursor(0, 1);
    lcd.print("Puntos:20");
    Tipo="AAA";

    }
    
    /*----------------------------------------*/
    
    else if (distancia >= 28&& distancia <=35)
    {
      lcd.setCursor(0, 0);
    lcd.print("Tipo:Boton");
    lcd.setCursor(0, 1);
    lcd.print("Puntos:50");
    Tipo="Boton";
    
    }
 }
   
   
  
  
