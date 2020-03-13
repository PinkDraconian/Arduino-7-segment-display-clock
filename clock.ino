#include <FastLED.h>
#define NUM_LEDS 58
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

const int TOTAL_SEGMENTS = 4; // Total amount of segments
const int LEDS_PER_SEGMENT = 14; // Amount of LEDs per segment
const int DISPLAY_SEGMENT[] = {0, 14, 14 * 2 + 2, 14 * 3 + 2}; // LED starting position of each segment
const int DISPLAY_NUMBER[][14] = { // True: Lit, False:  Not lit
  {true, true, false, false, true, true, true, true, true, true, true, true, true, true}, // 0
  {false, false, false, false, false, false, false, false, true, true, true, true, false, false}, // 1
  {true, true, true, true, false, false, true, true, true, true, false, false, true, true}, // 2
  {false, false, true, true, false, false, true, true, true, true, true, true, true, true}, // 3
  {false, false, true, true, true, true, false, false, true, true, true, true, false, false}, // 4
  {false, false, true, true, true, true, true, true, false, false, true, true, true, true}, // 5
  {true, true, true, true, true, true, true, true, false, false, true, true, true, true}, // 6
  {false, false, false, false, false, false, true, true, true, true, true, true, false, false}, // 7
  {true, true, true, true, true, true, true, true, true, true, true, true, true, true}, // 8
  {false, false, true, true, true, true, true, true, true, true, true, true, true, true}, // 9
};

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(40); // Lower brightness
}

void loop() {
  int numberToDisplay = Serial.readString().toInt(); // Take in user input

  FastLED.clear(); // Clear the LEDs

  for (int i = 0; i < TOTAL_SEGMENTS; i++) { // Loop over each segment
    for (int j = 0; j < LEDS_PER_SEGMENT; j++) { // Loop over each LED of said segment
      if (DISPLAY_NUMBER[numberToDisplay][j]) { // If this LED should be on
        leds[DISPLAY_SEGMENT[i] + j] = CRGB::Red; // Turn it on
      }
    }
  }
  leds[14 * 2] = CRGB::Red; // Light the dots
  leds[14 * 2 + 1] == CRGB::Red;
  
  FastLED.show(); // Show the current LEDs
  delay(500);
}
