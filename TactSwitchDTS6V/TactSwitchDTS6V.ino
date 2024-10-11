//
// Sample sketch for class Tact Switch(use Interrupt / pull-down)
//
#include "TactSwitchDTS6V.hpp"

using namespace ElectronicComponent;

TactSwitchDTS6V* mySwitch;
const int BAUD_RATE = 9600;
const int SIGNAL_LINE_PIN = 2;

void chkSwitch() {
  mySwitch->startInterrupt();
}

void setup() {
  Serial.begin( BAUD_RATE );
  mySwitch = new TactSwitchDTS6V( SIGNAL_LINE_PIN, TactSwitchDTS6V::TYPE_PULLDOWN );
  attachInterrupt( digitalPinToInterrupt( SIGNAL_LINE_PIN ), chkSwitch, RISING );
  Serial.println("Ready...");
}

void loop() {
  int ret = mySwitch->getCondition();
  if( ret == TactSwitchDTS6V::RET_SHORTDOWN ) {
    Serial.print( millis() );
    Serial.println( " : Switch Down" );
  } else if( ret == TactSwitchDTS6V::RET_HOLDDOWN ) {
    Serial.print( millis() );
    Serial.println( " : Switch Holddown" );
  }
}
