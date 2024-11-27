#ifndef MICRO_SERVO_MG90S_H
#define MICRO_SERVO_MG90S_H
//
// Filename :   MicroServoMG90S.hpp
// Abstruct :   Class definition for 
// Author   :   education_division@atit.jp
// Update   :   2024/11/27 New Creation
#include <Servo.h>

namespace ElectronicComponent {
//
// Class    :   MicroServoMG90S
// Abstruct :   Class definition for 
class MicroServoMG90S {
    // Definition of constant
public:
    enum anglePosition {
        ANGLE_CENTER_POSITION   = 90,   // 角度指定(中央位置)
        ANGLE_START_POSITION    = 0,    // 角度指定(端位置)
        ANGLE_END_POSITION      = 180   // 角度指定(端位置)
    };
    // Definition of variable
private:
    Servo*          clServo;            // サーボモータクラスインスタンス
    unsigned int    pinNo;              // Arduino側ピン番号
    int             degree;             // サーボモータ角度
    // Definition of method
public:
    MicroServoMG90S( unsigned int );    // Method:コンストラクタ
    void         adjustDegree( int );   // Method:角度調整
    unsigned int getPinNo();            // Method:制御ピン番号取得
    int          getDegree();           // Method:角度取得
};
}
#endif 
