#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2); //

String texto = "En una mano estas tu y en la otra el Abismo";
const int VELOCIDAD = 250;

void setup() {
  // Inicializar el LCD
  lcd.init();

  //Encender la luz de fondo.
  lcd.backlight();

}
 
void loop() {
 
 const int longitud=texto.length();    // Creamos una constante "longitud" que será un número entero y tendrá el valor de la longitud o tamaño total del "texto" (caractéres + espacios).
 for(int i=longitud; i>0 ; i--)        // Mostramos entrada texto por la izquierda hasta que la primera letra (W) alcanza la coordenada (0, 0)
 {
 String texto_cortado = texto.substring(i-1); 
 /* La función .substring(numero) devuelve un trozo del texto. El número indica a partir de qué letra vamos a coger por ejemplo si hacemos “WELCOME-DOMOTIC PARKING!”.substring(3) 
 nos devolverá “COME-DOMOTIC PARKING!”. Recuerda que es un lenguaje de índice cero, el primer carácter del texto empieza por cero.
 */
 lcd.setCursor(0, 0);                  //Situamos el cursor
 lcd.print(texto_cortado);             // Escribimos el texto
 delay(VELOCIDAD);                     // Esperamos
 }
 for(int i=1; i<=16;i++)               // Una vez que se coloca elinicio del texto (o letra W) en la coordenada (0, 0) desplazamos el texto hacia la derecha para que recorra toda la longitud del display (16 unidades). 
 {
 lcd.clear();
 lcd.setCursor(i, 0);
 lcd.print(texto);
 delay(VELOCIDAD);
 } 
 for(int i=16;i>=1;i--)                // Mostramos el texto por la derecha en la segunda fila y lo desplazamos hacia la izquierda hasta que recorra toda la pantalla (16 unidades) 
 {
 lcd.clear();
 lcd.setCursor(i, 1);
 lcd.print(texto);
 delay(VELOCIDAD);
 }
 for(int i=1; i<=longitud ; i++)        // Sacamos el texto por la izquierda de la pantalla para conseguir el efecto de que desaparece. 
 {
 String texto_cortado = texto.substring(i-1);
 lcd.setCursor(0, 1);
 lcd.print(texto_cortado);
 delay(VELOCIDAD);
 lcd.clear();
 }
}
