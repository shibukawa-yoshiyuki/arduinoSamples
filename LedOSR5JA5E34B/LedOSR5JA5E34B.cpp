//
// Filename :   LedOSR5JA5E34B.cpp
// Abstruct :   Method for LedOSR5JA5E34B class
// Author   :   education_division@atit.jp
// Update   :   2024/11/15 New Creation
#include <Arduino.h>
#include "LedOSR5JA5E34B.hpp"

namespace ElectronicComponent {
//
// Method   :   LedOSR5JA5E34B
// Abstruct :   コンストラクタ
// Argument :   int pinNo   アノード対向ピン番号
LedOSR5JA5E34B::LedOSR5JA5E34B( unsigned int pinNo ) {
    // 初期化
    this->pin = pinNo;
    pinMode( this->pin, OUTPUT );

    // 初期状態(全消灯)
    this->turnOff();
}

//
// Method   :   lightLEDFull
// Abstruct :   LED点灯
// Argument :   n/a
// Return   :   n/a
void LedOSR5JA5E34B::lightLEDFull() {
    this->brightness = LED_OSR5JA5E34B_HIGH;
    digitalWrite( this->pin, HIGH );
    this->isLight = true;
}

//
// Method   :   lightLED
// Abstruct :   指定した輝度でLEDを点灯
// Argument :   int brightness 輝度
// Return   :   n/a
void LedOSR5JA5E34B::lightLED( int brightness ) {
    this->brightness = brightness;
    analogWrite( this->pin, this->brightness );
    this->isLight = true;
}

//
// Method   :   turnOff
// Abstruct :   LED消灯
// Argument :   n/a
// Return   :   n/a
void LedOSR5JA5E34B::turnOff() {
    this->brightness = LED_OSR5JA5E34B_LOW;
    digitalWrite( this->pin, LOW );
    this->isLight = false;
}

//
// Method   :   isLighting
// Abstruct :   点灯状態を取得する
// Argument :   n/a
// Return   :   n/a
bool LedOSR5JA5E34B::isLighting() {
    return this->isLight;
}

//
// Method   :   getPin
// Abstruct :   getter(pin)
// Argument :   n/a
// Return   :   n/a
unsigned int LedOSR5JA5E34B::getPin() {
    return this->pin;
}

//
// Method   :   getBrightness
// Abstruct :   getter(brightness)
// Argument :   n/a
// Return   :   n/a
int LedOSR5JA5E34B::getBrightness() {
    return this->brightness;
}
}
