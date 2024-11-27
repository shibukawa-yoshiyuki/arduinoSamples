//
// Sample sketch for class Micro Servo
//
#include "MicroServoMG90S.hpp"

using namespace ElectronicComponent;

const unsigned int CONTROL_PIN = 9U;
MicroServoMG90S* myServo;

void setup() {
  myServo = new MicroServoMG90S( CONTROL_PIN );
  myServo->adjustDegree( MicroServoMG90S::anglePosition::ANGLE_START_POSITION );
  delay( 2000UL );
}

void loop() {
  for( int i = MicroServoMG90S::anglePosition::ANGLE_START_POSITION; i <= MicroServoMG90S::anglePosition::ANGLE_END_POSITION; i++ ) {
    myServo->adjustDegree( i );
    delay( 10UL );
  }
  for( int i = MicroServoMG90S::anglePosition::ANGLE_END_POSITION; i >= MicroServoMG90S::anglePosition::ANGLE_START_POSITION ; i-- ) {
    myServo->adjustDegree( i );
    delay( 10UL );
  }
}
