#include <Adafruit_NeoPixel.h>

#define LED_PIN 11 /* D2 */
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(14*4 + 2, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t rgb[14*4 + 2];

int rgb_r = 255;
int rgb_g = 255;
int rgb_b = 255;

void setup() {
  RGBsetup();  
}

void loop() {
  sevenSegment(0, 8);
}

void RGBsetup() {
  pixels.begin(); // This initializes the NeoPixel library.
  for (int i=0; i<14*4 + 2; i++)
  {
    rgb[i]=0;
  }
}
const uint8_t hexTable[] =
{
  0x7d, // 0 0x00   xxxxx.x
  0x30, // 1 0x01   .xx....               bit #
  0x5b, // 2 0x02   x.xx.xx
  0x7a, // 3 0x03   xxxx.x.             ....3....
  0x36, // 4 0x04   .xx.xx.             .       .
  0x6e, // 5 0x05   xx.xxx.             2       4
  0x6f, // 6 0x06   xx.xxxx             .       .
  0x38, // 7 0x07   .xxx...             ....1....
  0x7f, // 8 0x08   xxxxxxx             .       .
  0x7e, // 9 0x09   xxxxxx.             0       5
  0x3f, // A 0x0a   .xxxxxx             .       .       
  0x67, // b 0x0b   xx..xxx             ....6....
  0x43, // c 0x0c   x....xx
  0x73, // d 0x0d   xxx..xx
  0x4f, // E 0x0e   x..xxxx
  0x0f, // F 0x0f   ...xxxx
  0x1e, // ° 0x10   ..xxxx.
  0x4d, // C 0x11   x..xx.x
  0x02, // - 0x12   .....x.
  0x40, // _ 0x13   x......
  0x00, //   0x14   .......
};

const uint8_t pos2segment[4] =
{
  0,
  14,
  2*14+2,
  3*14+2
};

void sevenSegment(int pos, int val)
{
  uint8_t digit = hexTable[val];
  uint32_t color = pixels.Color(rgb_r, rgb_g, rgb_b);
  int j = pos2segment[pos];
  for (uint8_t i=0; i<7; i++)
  {
    if (0 != (digit & ((uint8_t)1 << i)))
    {
      rgb[j++] = color;
      rgb[j++] = color;
    }
    else
    {
      rgb[j++] = 0;
      rgb[j++] = 0;
    }
  }
}
