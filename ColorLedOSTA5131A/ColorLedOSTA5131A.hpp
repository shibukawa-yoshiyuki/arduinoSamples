#ifndef COLOR_LED_OSTA5131A_H
#define COLOR_LED_OSTA5131A_H
//
// Filename :   ColorLedOSTA5131A.hpp
// Abstruct :   Class definition for Fullcolor LED
// Author   :   education_division@atit.jp
// Update   :   2024/11/08 New Creation

namespace ElectronicComponent {
//
// Class    :   ColorLedOSTA5131A
// Abstruct :   Class definition for Fullcolor LED
class ColorLedOSTA5131A {
    // Definiton of constant
private:
    const int COLOR_LED_OSTA5131A_HIGH = 0xff;  // 最大アナログ値
    const int COLOR_LED_OSTA5131A_LOW  = 0x00;  // 最小アナログ値
    // Definition of variable
private:
    unsigned int pinGreen;                      // 1番アノード対向ピン(緑)
    unsigned int pinBlue;                       // 2番アノード対向ピン(青)
    unsigned int pinRed;                        // 4番アノード対向ピン(赤)
    int brightnessGreen;                        // 輝度(緑)
    int brightnessBule;                         // 輝度(青)
    int brightnessRed;                          // 輝度(赤)
    bool isLight;                               // 点灯状態
    // Definition of method
public:
    ColorLedOSTA5131A( unsigned int,
                       unsigned int,
                       unsigned int );          // method:コンストラクタ
    void lightLed( int, int, int );             // method:点灯(輝度指定)
    void lightRed();                            // method:点灯(赤)
    void lightGreen();                          // method:点灯(緑)
    void lightBlue();                           // method:点灯(青)
    void turnOff();                             // method:全消灯
    bool isLighting();                          // method:点灯状態取得
    unsigned int getPinRed();                   // method:getter(4番アノード対向ピン(赤))
    unsigned int getPinGreen();                 // method:getter(1番アノード対向ピン(緑))
    unsigned int getPinBlue();                  // method:getter(2番アノード対向ピン(青))
    int  getBrightnessRed();                    // method:getter(輝度(赤))
    int  getBrightnessGreen();                  // method:getter(輝度(緑))
    int  getBrightnessBlue();                   // method:getter(輝度(青))
};
}
#endif
