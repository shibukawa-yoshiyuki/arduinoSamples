//
// Sample sketch for class ColorLedOSTA5131A
//
#include <math.h>
#include "ColorLedOSTA5131A.hpp"

using namespace ElectronicComponent;

const unsigned int RED_OUT_PIN   = 9U;
const int INI_RED_MIN   = 52;
const int INI_RED_MAX   = 171;
const unsigned int GREEN_OUT_PIN = 10U;
const int INI_GREEN_MIN = 22;
const int INI_GREEN_MAX = 111;
const unsigned int BULE_OUT_PIN  = 11U;
const int INI_BULE_MIN  = 41;
const int INI_BULE_MAX  = 73;

ColorLedOSTA5131A* myLed;
int redVal   = 0x00;
int greenVal = 0x00;
int blueVal  = 0x00;
int i        = INI_RED_MIN;
int j        = INI_GREEN_MAX;
int k        = INI_BULE_MIN;

void setup() {
  myLed = new ColorLedOSTA5131A( RED_OUT_PIN, GREEN_OUT_PIN, BULE_OUT_PIN );

  myLed->lightRed();
  delay( 2000 );
  myLed->lightGreen();
  delay( 2000 );
  myLed->lightBlue();
  delay( 2000 );
  myLed->turnOff();
  delay( 2000 );
}

void loop() {
  redVal   = (int)round( sin( (double)i *  3.0 * M_PI / 180.0 ) * 36.0 + 36.0 );
  if( i < INI_RED_MAX ) {
    i++;
  } else {
    i = INI_RED_MIN;
  }

  greenVal = (int)round( sin( (double)j *  4.0 * M_PI / 180.0 ) * 127.0 + 127.0 );
  if( j > INI_GREEN_MIN ) {
    j--;
  } else {
    j = INI_GREEN_MAX;
  }

  blueVal  = (int)round( sin( (double)k * 11.0 * M_PI / 180.0 ) * 127.0 + 127.0 );
  if( k < INI_BULE_MAX ) {
    k++;
  } else {
    k = INI_BULE_MIN;
  }

  myLed->lightLed( redVal, greenVal, blueVal );
  delay( 200 );
}
