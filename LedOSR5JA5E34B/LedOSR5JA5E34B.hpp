#ifndef LED_OSR5JA5E34B_H
#define LED_OSR5JA5E34B_H
//
// Filename :   LedOSR5JA5E34B.hpp
// Abstruct :   Class definition for LED
// Author   :   education_division@atit.jp
// Update   :   2024/11/15 New Creation

namespace ElectronicComponent {
//
// Class    :   LedOSR5JA5E34B
// Abstruct :   Class definition for LED
class LedOSR5JA5E34B {
private:
    // Definiton of constant
    const int LED_OSR5JA5E34B_HIGH = 0xff;  // 最大アナログ値
    const int LED_OSR5JA5E34B_LOW  = 0x00;  // 最小アナログ値
    // Definition of variable
private:
    unsigned int pin;                       // アノード対向ピン番号
    int          brightness;                // 輝度
    bool         isLight;                   // 点灯状態
    // Definition of method
public:
    LedOSR5JA5E34B( unsgined int );         // method:コンストラクタ
    void lightLEDFull();                    // method:点灯
    void lightLED( int );                   // method:点灯(輝度指定)
    void turnOff();                         // method:消灯
    bool isLighting();                      // method:点灯状態取得
    int  getPin();                          // method:getter(pin)
    int  getBrightness();                   // method:getter(brightness)
};
}
#endif
