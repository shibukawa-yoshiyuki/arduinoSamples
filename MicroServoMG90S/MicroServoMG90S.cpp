//
// Filename :   MicroServoMG90S.cpp
// Abstruct :   Method for MicroServoMG90S class
// Author   :   education_division@atit.jp
// Update   :   2024/11/27 New Creation
#include "MicroServoMG90S.hpp"

namespace ElectronicComponent {
//
// Method   :   MicroServoMG90S
// Abstruct :   コンストラクタ
// Argument :   int id  : ID
//              int pin : Arduino側ピン番号
MicroServoMG90S::MicroServoMG90S( unsigned int pin ) {
    // 初期パラメータの設定
    this->pinNo = pin;

    // サーボインスタンスの初期化
    clServo = new Servo;
    clServo->attach( this->pinNo );
}

//
// Method   :   adjustDegree
// Abstruct :   サーボモータ角度調整
// Argument :   VolumeTSR3386* vol : ボリュームクラスインスタンス
// Return   :   n/a
void MicroServoMG90S::adjustDegree( int inputValue ) {
  // 角度が変更されたときは 0～180 度の間で、サーボモータ角度を制御する
    if( this->degree != inputValue && 
        inputValue   >= ANGLE_START_POSITION &&
        inputValue   <  ANGLE_END_POSITION ) {
        this->degree = inputValue;
        this->clServo->write( this->degree );
    }
    return;
}

//
// Method   :   getPinNo
// Abstruct :   制御ピン番号取得
// Argument :   n/a
// Return   :   unsigned int pinNo  : 制御ピン番号
unsigned int MicroServoMG90S::getPinNo() {
    return this->pinNo;
}

//
// Method   :   getDegree
// Abstruct :   サーボモータ角度取得
// Argument :   n/a
// Return   :   int degree  : サーボモータ角度
int MicroServoMG90S::getDegree() {
    return this->degree;
}
}
