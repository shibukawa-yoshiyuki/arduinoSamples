//
// Sample sketch for class LED
//
#include <math.h>
#include "LedOSR5JA5E34B.hpp"

using namespace ElectronicComponent;

const unsigned int LED_OUT_PIN = 9U;
const int INI_LED_MIN          = 22;
const int INI_LED_MAX          = 111;

LedOSR5JA5E34B* myLed;
int brightVal = 0x00;
int i         = INI_LED_MIN;

void setup() {
  myLed = new LedOSR5JA5E34B( LED_OUT_PIN );

  myLed->lightLEDFull();
  delay( 2000 );
  myLed->turnOff();
  delay( 2000 );
}

void loop() {
  brightVal = (int)round( sin( (double)i *  4.0 * M_PI / 180.0 ) * 127.0 + 127.0 );
  if( i > INI_LED_MIN ) {
    i--;
  } else {
    i = INI_LED_MAX;
  }

  myLed->lightLED( brightVal );
  delay( 200 );
}
