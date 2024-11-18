//
// Filename :   ColorLedOSTA5131A.cpp
// Abstruct :   Method for ColorLedOSTA5131A class
// Author   :   education_division@atit.jp
// Update   :   2024/11/08 New Creation
#include <Arduino.h>
#include "ColorLedOSTA5131A.hpp"

namespace ElectronicComponent {
//
// Method   :   ColorLedOSTA5131A
// Abstruct :   コンストラクタ
// Argument :   int redPin   4番アノード対向ピン(赤)
//              int greenPin 1番アノード対向ピン(緑)
//              int bluePin  2番アノード対向ピン(青)
ColorLedOSTA5131A::ColorLedOSTA5131A( unsigned int redPin, unsigned int greenPin, unsigned int bluePin ) {
	// 初期化(赤)
  	this->pinRed          = redPin;
  	this->brightnessRed	  = COLOR_LED_OSTA5131A_LOW;
  	pinMode( this->pinRed, OUTPUT );

  	// 初期化(緑)
  	this->pinGreen        = greenPin;
  	this->brightnessGreen = COLOR_LED_OSTA5131A_LOW;
  	pinMode( this->pinGreen, OUTPUT );

  	// 初期化(青)
  	this->pinBlue      	  = bluePin;
  	this->brightnessBule  = COLOR_LED_OSTA5131A_LOW;
  	pinMode( this->pinBlue,	OUTPUT );

  	// 初期状態にする(消灯)
  	this->turnOff();
}

//
// Method   :   lightLed
// Abstruct :   指定した輝度で点灯する
// Argument :   int red   輝度(赤)
//              int green 輝度(緑)
//              int blue  輝度(青)
// Return   :   n/a
void ColorLedOSTA5131A::lightLed( int red, int green, int blue ) {
  	// 引数検査し範囲内(0x00～0xff)ならば更新
  	if( red   >= COLOR_LED_OSTA5131A_LOW && red   <= COLOR_LED_OSTA5131A_HIGH ) {
    	this->brightnessRed   = red;
  	}
  	if( green >= COLOR_LED_OSTA5131A_LOW && green <= COLOR_LED_OSTA5131A_HIGH ) {
    	this->brightnessGreen = green;
  	}
  	if( blue  >= COLOR_LED_OSTA5131A_LOW && blue  <= COLOR_LED_OSTA5131A_HIGH ) {
    	this->brightnessBule  = blue;
  	}
  	// 輝度が指定されている場合は赤/緑/青を点灯
	if( this->brightnessRed   > COLOR_LED_OSTA5131A_LOW 
	 || this->brightnessGreen > COLOR_LED_OSTA5131A_LOW 
	 || this->brightnessBule  > COLOR_LED_OSTA5131A_LOW ) {
  		analogWrite( this->pinRed,   this->brightnessRed );
  		analogWrite( this->pinGreen, this->brightnessGreen );
  		analogWrite( this->pinBlue,  this->brightnessBule );
  		// 点灯状態を点灯にする
  		this->isLight         = true;
	} else {
  		// 全て0x00の場合は点灯状態を消灯にする
  		this->isLight         = false;
	}
}

//
// Method   :   lightRed
// Abstruct :   赤を点灯する
// Argument :   n/a
// Return   :   n/a
void ColorLedOSTA5131A::lightRed() {
  	this->turnOff();
  	// 赤を点灯
  	this->brightnessRed   = COLOR_LED_OSTA5131A_HIGH;
  	digitalWrite( this->pinRed,   this->brightnessRed );
	// 赤以外は消灯
  	this->brightnessGreen = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinGreen, this->brightnessGreen );
  	this->brightnessBule  = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinBlue,  this->brightnessBule );
  	// 点灯状態を点灯に
  	this->isLight         = true;
}

//
// Method   :   lightGreen
// Abstruct :   緑を点灯する
// Argument :   n/a
// Return   :   n/a
void ColorLedOSTA5131A::lightGreen() {
  	this->turnOff();
  	// 緑を点灯
  	this->brightnessGreen = COLOR_LED_OSTA5131A_HIGH;
  	digitalWrite( this->pinGreen, this->brightnessGreen );
	// 緑以外は消灯
  	this->brightnessRed   = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinRed,   this->brightnessRed );
  	this->brightnessBule  = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinBlue,  this->brightnessBule );
  	// 点灯状態を点灯に
  	this->isLight         = true;
}

//
// Method   :   lightBlue
// Abstruct :   青を点灯する
// Argument :   n/a
// Return   :   n/a
void ColorLedOSTA5131A::lightBlue() {
  	this->turnOff();
  	// 青を点灯
  	this->brightnessBule  = COLOR_LED_OSTA5131A_HIGH;
  	digitalWrite( this->pinBlue,  this->brightnessBule );
	// 青以外は消灯
  	this->brightnessRed   = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinRed,   this->brightnessRed );
  	this->brightnessGreen = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinGreen, this->brightnessGreen );
  	// 点灯状態を点灯に
  	this->isLight         = true;
}

//
// Method   :   turnOff
// Abstruct :   全色消灯する
// Argument :   n/a
// Return   :   n/a
void ColorLedOSTA5131A::turnOff() {
  	// 赤/緑/青を消灯
  	this->brightnessRed   = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinRed,   this->brightnessRed );
  	this->brightnessGreen = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinGreen, this->brightnessGreen );
  	this->brightnessBule  = COLOR_LED_OSTA5131A_LOW;
  	digitalWrite( this->pinBlue,  this->brightnessBule );
  	// 点灯状態を消灯に
  	this->isLight         = false;
}

//
// Method   :   isLighting
// Abstruct :   getter(isLight)
// Argument :   n/a
// Return   :   bool isLight 点灯状態
bool ColorLedOSTA5131A::isLighting() {
  	return this->isLight;
}

//
// Method   :   getPinRed
// Abstruct :   getter(pinRed)
// Argument :   n/a
// Return   :   unsigned int pinRed 4番アノード対向ピン(赤)
unsigned int  ColorLedOSTA5131A::getPinRed() {
  	return this->pinRed;
}

//
// Method   :   getPinGreen
// Abstruct :   getter(pinGreen)
// Argument :   n/a
// Return   :   unsigned int pinGreen 1番アノード対向ピン(緑)
unsigned int  ColorLedOSTA5131A::getPinGreen() {
  	return this->pinGreen;
}

//
// Method   :   getPinBlue
// Abstruct :   getter(pinBlue)
// Argument :   n/a
// Return   :   unsigned int pinBlue 2番アノード対向ピン(青)
unsigned int  ColorLedOSTA5131A::getPinBlue() {
  	return this->pinBlue;
}

//
// Method   :   getBrightnessRed
// Abstruct :   getter(brightnessRed)
// Argument :   n/a
// Return   :   int brightnessRed 輝度(赤)
int  ColorLedOSTA5131A::getBrightnessRed() {
  	return this->brightnessRed;
}

//
// Method   :   getBrightnessGreen
// Abstruct :   getter(brightnessGreen)
// Argument :   n/a
// Return   :   int brightnessGreen 輝度(緑)
int  ColorLedOSTA5131A::getBrightnessGreen() {
  	return this->brightnessGreen;
}

//
// Method   :   getBrightnessBlue
// Abstruct :   getter(brightnessBule)
// Argument :   n/a
// Return   :   int brightnessBule 輝度(青)
int  ColorLedOSTA5131A::getBrightnessBlue() {
  	return this->brightnessBule;
}
}
