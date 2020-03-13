#include <FastLED.h>
#define NUM_LEDS 58
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

const int TOTAL_SEGMENTS = 4;
const int DISPLAY_SEGMENT[] = {0, 14, 14 * 2 + 2, 14 * 3 + 2};
const int DISPLAY_NUMBER[][] = {
  {0, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13} // 0
};

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  int numberToDisplay = 0;
  for (int i = 0; i < TOTAL_SEGMENTS; i++) {
    for (int j = 0; j < sizeof DISPLAY_NUMBER[numberToDisplay]; j++) {
      leds[DISPLAY_SEGMENT[i + j]] = CRGB::Red;
    }
  }
  
  FastLED.show();
  delay(30);
}
