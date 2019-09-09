//Opdracht: maak het volgende schema na aan de hand van sfeer_licht.jpg
//Maak hierbij de volgende code af:

#include <FastLED.h>

#define LED_COUNT 4
#define DATA_PIN 9

#define POTPIN  A5
#define LDRPIN  A4
#define NTCPIN  A3

CRGB leds[LED_COUNT];

void setup() {
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, LED_COUNT);
    writeLeds(rgb(0,0,128));
    pinMode(POTPIN,INPUT);
    pinMode(LDRPIN,INPUT);
    pinMode(NTCPIN,INPUT);
    Serial.begin(9600);
}

void loop() {
  int pot,ldr,ntc;
  pot = analogRead(POTPIN);
  ldr = analogRead(LDRPIN);
  ntc = analogRead(NTCPIN);

  delay(100);
  Serial.println("sensor values:");
  
  Serial.println("pot=" + String(pot));
  Serial.println("ldr=" + String(ldr));
  Serial.println("ntc=" + String(ntc));

  //vul de juiste variabel naam voor de map instructie:
  //De Groen tint is afhankelijk van de temperatuur
  //De Rood tint wordt door de hoeveelheid ambiante licht bepaalt
  //De Blauw tint is instelbaar door een draaiknop 
  //haal dan vervolgens de "//" weg
  //Zorg ervoor dat de data nuttig gecalibreerd is:
  //het berijk van de NTC is bijvoorbeeld maar tussen kamer- en hand temperatuur
  //gebruik hiervoor de 2e en 3e parameter van de desbetreffende map() functie
  //(tip: bestudeer de output van de seriele monitor!!)
  
  int rood = 0,groen = 0,blauw = 0;
  //? = map(pot,0,1024,0,254);
  //? = map(ldr,0,1024,0,254);
  //? = map(ntc,0,1024,0,254);
  writeLeds(rgb(rood,groen,blauw));


}

CRGB rgb(int r, int g, int b)
{
  return CRGB{g,r,b};
}

void writeLeds(CRGB color)
{
  for(int i = 0; i < LED_COUNT; i++)
  {
    leds[i] = color;
  }
  FastLED.show();
}
