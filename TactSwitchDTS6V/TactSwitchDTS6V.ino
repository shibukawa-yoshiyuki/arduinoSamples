//
// Sample sketch for class Tact Switch(use Interrupt / pull-down)
//
#include "TactSwitchDTS6V.hpp"

using namespace ElectronicComponent;

TactSwitchDTS6V* mySwitch;
const unsigned long BAUD_RATE       = 9600UL;
const unsigned int  SIGNAL_LINE_PIN = 2U;
const unsigned int  ONBOARD_LED     = 13U;

void setup() {
  Serial.begin( BAUD_RATE );
  Serial.println("Ready...");

  mySwitch = new TactSwitchDTS6V( SIGNAL_LINE_PIN, TactSwitchDTS6V::TYPE_PULLDOWN );
  attachInterrupt( digitalPinToInterrupt( SIGNAL_LINE_PIN ), (void (*)())&mySwitch->startInterrupt, RISING );

  pinMode( ONBOARD_LED, OUTPUT );
  digitalWrite( ONBOARD_LED, LOW );
}

void loop() {
  int ret = mySwitch->getCondition();

  if( ret == TactSwitchDTS6V::RET_SHORTDOWN ) {
    Serial.print( millis() );
    Serial.println( " : Switch Down" );
    digitalWrite( ONBOARD_LED, LOW );

  } else if( ret == TactSwitchDTS6V::RET_HOLDDOWN ) {
    Serial.print( millis() );
    Serial.println( " : Switch Holddown" );
    digitalWrite( ONBOARD_LED, LOW );

  } else if( ret == TactSwitchDTS6V::RET_PUSHING ) {
    digitalWrite( ONBOARD_LED, HIGH );

  }

}
