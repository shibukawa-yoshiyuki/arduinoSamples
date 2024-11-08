//
// Sample sketch for class ColorLedOSTA5131A
//
#include <math.h>
#include "ColorLedOSTA5131A.hpp"

//using namespace ElectronicComponent;

ColorLedOSTA5131A* myLed;
int redVal   = 0x00;  // 輝度(赤)
int greenVal = 0x00;  // 輝度(緑)
int blueVal  = 0x00;  // 輝度(青)
int i        = 52;    // 周期変数(赤)
int j        = 111;   // 周期変数(緑)
int k        = 41;    // 周期変数(青)

void setup() {
  // 初期化
  myLed = new ColorLedOSTA5131A( 9, 10, 11 );

  // 単色点灯(赤→緑→青→消灯)
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
  // 輝度の計算(赤)
  redVal   = (int)round( sin( (double)i *  3.0 * M_PI / 180.0 ) * 36.0 + 36.0 );
  if( i < 171 ) {
    i++;
  } else {
    i = 52;
  }

  // 輝度の計算(緑)
  greenVal = (int)round( sin( (double)j *  4.0 * M_PI / 180.0 ) * 127.0 + 127.0 );
  if( j > 22 ) {
    j--;
  } else {
    j = 111;
  }

  // 輝度の計算(青)
  blueVal  = (int)round( sin( (double)k * 11.0 * M_PI / 180.0 ) * 127.0 + 127.0 );
  if( k < 73 ) {
    k++;
  } else {
    k = 41;
  }

  // 輝度を指定して点灯
  myLed->lightLed( redVal, greenVal, blueVal );
  delay( 200 );
}
