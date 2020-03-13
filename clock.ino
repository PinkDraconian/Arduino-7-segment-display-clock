#include <FastLED.h>
#include <DS3231.h>
#include <Wire.h>

#define NUM_LEDS 58
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
DS3231 rtc;

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
  Serial.begin(9600);
  Serial.println("Starting execution");
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(40); // Lower brightness
  
  Wire.begin();

  // The following lines can be uncommented to set the date and time
  //rtc.setHour(15);     // Set the hour to 15 (24hr format)
  //rtc.setMinute(12);   // Set the minute to 12
}

void loop() {
  bool h12, pm;
  int hour = rtc.getHour(h12, pm); // Get the hour
  int minute = rtc.getMinute(); // Get the minute

  int hourFirstDigit = hour / 10; // Take the first digit
  int hourSecondDigit = hour % 10; // Take the second digit

  int minuteFirstDigit = minute / 10; // Take the first digit
  int minuteSecondDigit = minute % 10; // Take the second digit

  displayNumber(3, hourFirstDigit);
  displayNumber(2, hourSecondDigit);
  displayNumber(1, minuteFirstDigit);
  displayNumber(0, minuteSecondDigit);

  leds[14 * 2] = CRGB::Red; // Light the dots
  leds[14 * 2 + 1] = CRGB::Red;
  
  FastLED.show(); // Show the current LEDs
  delay(10000); // Wait 10 seconds
  FastLED.clear(); // Clear the LEDs
}

void displayNumber(int segment, int number) {
  for (int j = 0; j < LEDS_PER_SEGMENT; j++) { // Loop over each LED of said segment
    if (DISPLAY_NUMBER[number][j]) { // If this LED should be on
      leds[DISPLAY_SEGMENT[segment] + j] = CRGB::Red; // Turn it on
    }
  }
}
