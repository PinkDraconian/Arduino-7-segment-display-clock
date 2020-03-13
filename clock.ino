#include <FastLED.h>
#define NUM_LEDS 58
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

const int TOTAL_SEGMENTS = 4;
const int LEDS_PER_SEGMENT = 14;
const int DISPLAY_SEGMENT[] = {0, 14, 14 * 2 + 2, 14 * 3 + 2};
const int DISPLAY_NUMBER[][14] = {
  {true, true, false, false, true, true, true, true, true, true, true, true, true, true} // 0
};

void setup() {
  Serial.begin(9600);
  Serial.println("Starting execution");
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(40);
}

void loop() {
  int numberToDisplay = 0;
  for (int i = 0; i < TOTAL_SEGMENTS; i++) {
    for (int j = 0; j < LEDS_PER_SEGMENT; j++) {
      if (DISPLAY_NUMBER[numberToDisplay][j]) {
        leds[DISPLAY_SEGMENT[i] + j] = CRGB::Red;
      }
    }
  }
  
  FastLED.show();
  delay(500);
}
