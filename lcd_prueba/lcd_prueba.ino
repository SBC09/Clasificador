#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2); //

void setup() {
  // Inicializar el LCD
  lcd.init();

  //Encender la luz de fondo.
  lcd.backlight();
  lcd.setCursor(0, 1);
  // Escribimos el Mensaje en el LCD.
  lcd.print("Tipo:AA");
}

void loop() {
   lcd.setCursor(0, 0);
  // Escribimos el Mensaje en el LCD.
  lcd.print("Tipo:AA");
  // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 1);
  lcd.print("Puntos: 10");
  delay(100);
}
