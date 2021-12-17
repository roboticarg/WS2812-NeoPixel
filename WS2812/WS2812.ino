//https://blog.330ohms.com/2020/06/12/como-conectar-led-rgb-neopixel-ws2812-a-arduino/
// Basado en el ejemplo "simple" de Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>//Incluimos la librería en el código

// Pin del Arduino al cual conectamos el DIN del primer led en la cadena
#define PIN        2

// Número de píxeles encadenados
#define NUMPIXELS 16 //Modifica este npumero según el arreglo de LEDs con el que cuentes

// Inicializamos nuestro objeto "pixeles"
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Argumento 1 = Número de pixeles encadenados
// Argumento 2 = Número del pin de Arduino utilizado con pin de datos
// Argumento 3 = Banderas de tipo de pixel:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

#define DELAYVAL 500 //timpo de espera en ms 

void setup() {
  pixels.begin(); // Inicializamos el objeto "pixeles"
}


void loop() {
  pixels.clear(); // Apagamos todos los LEDs
  // El primer pixel de una cadena es el #0, el segundo es el #1, y así sucesivamente
  // hasta el npumero de pixeles menos uno
  for(int i=0; i<NUMPIXELS; i++) { // Para cada pixel...
    pixels.setPixelColor(i, pixels.Color(10, i*1, 1));// Modificamos el LED #i, encendiendolo con un color verde moderadamente brillante
  }
  pixels.show();   // Mandamos todos los colores con la actualización hecha
  delay(DELAYVAL); // Pausa antes de modificar el color del siguiente LED
}
