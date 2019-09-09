//opdracht:
//Maak het schema na zoals in de bij behorende jpg bestand.
//Bekijk de waardes van de NTC sensor doormiddel van de seriele poort,
//Verwarm de NTC doormiddel van je handen, en bekijk welke waarde je duidelijk ziet dat de sensor opwarmt
//Vervang het getal van int max_value, met deze waarde.
//maak de volgende code af:

#include <FastLED.h>

#define LED_COUNT 4

//maak deze #defines af: (zoek hun pin namen in de JPG)
//------------
#define DATA_PIN 
#define NTCPIN 
//----------------

CRGB leds[LED_COUNT];

int max_value = 2000;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, LED_COUNT);
  clearLeds();
  
  //wat is de pinmodus van NTCPIN?
  pinMode(NTCPIN,????);
  Serial.begin(9600);
}

void loop() {
  delay(10);
  //De led moet hier GROEN zijn:
  leds[0] = rgb(0,0,0);

  //als de NTC te warm word, moet de led rood gaan knipperen, zorg ervoor dat een led knipper een kwart seconde aan staat, en een kwart seconde uit
  if(analogRead(NTCPIN) < max_value)
  {
    //De led moet hier ROOD zijn:
    leds[0] = rgb(0,0,0);
    FastLED.show();
    delay(1000);
    clearLeds();
    delay(1000);
  }
  FastLED.show();
}

CRGB rgb(int r, int g, int b)
{
  return CRGB{g,r,b};
}

void clearLeds()
{
  for(int i = 0; i < LED_COUNT; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}
