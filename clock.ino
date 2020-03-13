#include <FastLED.h>
#define NUM_LEDS 60
#define DATA_PIN 11
CRGB leds[NUM_LEDS];

const int TOTAL_SEGMENTS = 4;
const int[] DISPLAY_NUMBER = {0, 14, 14 * 2 + 2, 14 * 3 + 2};

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < TOTAL_SEGMENTS; i++) {
  	leds[DISPLAY_NUMBER[i]] = CRGB::Red;
    FastLED.show()
  }
  
  // leds[0] = CRGB::Red;
  // FastLED.show(); 
  delay(30);
}

