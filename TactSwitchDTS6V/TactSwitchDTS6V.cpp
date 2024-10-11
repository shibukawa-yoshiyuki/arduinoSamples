//
// Filename :   TactSwitchDTS6V.cpp
// Abstruct :   Method for TactSwitchDTS6V class
// Author   :   application_division@atit.jp
// Update   :   2024/10/11 New Creation
#include "Arduino.h"
#include "TactSwitchDTS6V.hpp"

namespace ElectronicComponent {
//
// Method   :   TactSwitchDTS6V
// Abstruct :   コンストラクタ
// Argument :   int inputPin : Arduino側ピン番号
// Note     :   回路区分が省略された場合、プルアップにする
TactSwitchDTS6V::TactSwitchDTS6V( int inputPin ) : TactSwitchDTS6V( inputPin, TYPE_PULLUP ) {
}

//
// Method   :   TactSwitchDTS6V
// Abstruct :   コンストラクタ
// Argument :   int inputPin : Arduino側ピン番号
//          :   int typePull : 回路区分(pull-up/pull-down)
static TactSwitchDTS6V::TactSwitchDTS6V( int inputPin, const int typePull ) {
    this->pin             = inputPin;
    this->swStatus        = SW_STS_STANDBY;
    this->detectTime      = 0UL;
    this->isInterrupt     = true;
    if( typePull == TYPE_PULLUP ) {
        this->unconnected = HIGH;
        this->connected   = LOW;
    } else {
        this->unconnected = LOW;
        this->connected   = HIGH;
    }
    this->latency         = DEF_LATENCY;
    this->holdDownTime    = DEF_HOLDDOWN;
}

//
// Method   :   setLatency
// Abstruct :   チャタリング防止レイテンシ設定
// Argument :   unsigned long invalue : レイテンシ
// Return   :   n/a
void TactSwitchDTS6V::setLatency( unsigned long inValue ) {
    if( inValue <= LATENCY_MAX ) {
        this->latency = inValue;
    }
}

//
// Method   :   setHoldDown
// Abstruct :   長押し判定時間閾値設定
// Argument :   unsigned long invalue : 長押し判定時間閾値
// Return   :   n/a
void TactSwitchDTS6V::setHoldDown( unsigned long inValue ) {
    if( inValue >= HOLDDOWN_MIN && inValue <= HOLDDOWN_MAX ) {
        this->holdDownTime = inValue;
    }
}

//
// Method   :   setNoInterrupt
// Abstruct :   割り込みなし設定
// Argument :   n/a
// Return   :   n/a
// Note     :   外部割込みを使用しないときは Setup() 内で本関数をコールすること
void TactSwitchDTS6V::setNoInterrupt() {
    this->isInterrupt = false;
}

//
// Method   :   startInterrupt
// Abstruct :   割り込み時の判定(to DETECTING)
// Argument :   n/a
// Return   :   n/a
void TactSwitchDTS6V::startInterrupt() {
    if( this->swStatus != SW_STS_STANDBY ) {
        // スタンバイ以外は無視
        return;
    }
    // ステータス移行処理実施する
    this->swStatus   = SW_STS_DETECTING;
    this->detectTime = millis();
    return;
}

//
// Method   :   startDetect
// Abstruct :   ステータス判定(to DETECTING)
// Argument :   n/a
// Return   :   int : 判定結果
//                    RET_NOCHANGE : ステータス変更なし
//                    RET_CHANGED  : ステータス変更
int TactSwitchDTS6V::startDetect() {
    if( this->swStatus != SW_STS_STANDBY ) {
        // スタンバイ以外は無視
        return RET_NOCHANGE;
    }
    // スイッチが押された場合ステータス移行判定する
    if( digitalRead( this->pin ) == this->connected ) {
        this->swStatus   = SW_STS_DETECTING;
        this->detectTime = millis();
        return RET_CHANGED;
    } else {
        return RET_NOCHANGE;
    }
}

//
// Method   :   startWait
// Abstruct :   ステータス判定(to WAITING)
// Argument :   unsigned long detectTime 
//                : ステータス変更からの経過時間
// Return   :   int
//                : 判定結果
//                  RET_NOCHANGE : ステータス変更なし
//                  RET_CHANGED  : ステータス変更
int TactSwitchDTS6V::startWait( unsigned long detectTime ) {
    if( this->swStatus != SW_STS_DETECTING ) {
        // DETECTED以外のステータスは無視
        return RET_NOCHANGE;
    }
    // レイテンシ時間超過しているかつスイッチから離されている場合ステータス移行と判定
    if( detectTime > this->latency && digitalRead( this->pin ) == this->unconnected ) {
        this->swStatus   = SW_STS_WAITING;
        this->detectTime = millis();
        return RET_CHANGED;
    } else {
        return RET_NOCHANGE;
    }
}

//
// Method   :   startStandby
// Abstruct :   ステータス判定(to STAND_BY)
// Argument :   unsigned long detectTime 
//                : ステータス変更からの経過時間
// Return   :   int
//                : 判定結果
//                  RET_NOCHANGE : ステータス変更なし
//                  RET_CHANGED  : ステータス変更
int TactSwitchDTS6V::startStandby( unsigned long detectTime ) {
    if( this->swStatus != SW_STS_WAITING ) {
        // WAITING以外のステータスは無視
        return RET_NOCHANGE;
    }
    // レイテンシ時間超過している場合ステータス移行を判定
    if( detectTime > this->latency ) {
        this->swStatus   = SW_STS_STANDBY;
        this->detectTime = 0UL;
        return RET_CHANGED;
    } else {
        return RET_NOCHANGE;
    }
}

//
// Method   :   getCondition
// Abstruct :   タクトスイッチ状態判定
// Argument :   n/a
// Return   :   int : 判定結果
//                    RET_SKIP      : 判定スキップ
//                    RET_PUSHING   : 押されている
//                    RET_SHORTDOWN : 押された
//                    RET_HOLDDOWN  : 長押しされた
int TactSwitchDTS6V::getCondition() {
    int retValue = RET_SKIP;    // 戻り値保持用

    // 経過時間の取得(経過時間が 0 の場合経過時間 0 とする)
    unsigned long elapsedTime = ( this->detectTime == 0UL ? 0UL: millis() - this->detectTime );

    switch ( this->swStatus ) {
        // ステータスが STANDBYの場合、DETECTINGへの移行判定を行う
        case SW_STS_STANDBY:
            if( this->isInterrupt == true ) {
                // 割り込み処理を利用する場合ここではコールしない
                return RET_SKIP;
            }
            if( RET_CHANGED == startDetect() ) {
                // ステータス移行した場合は押されている状態を返す(移行なしの場合SKIP)
                retValue = RET_PUSHING;
            }
            break;
        // ステータスが DETECTINGの場合、WAITINGへの移行判定を行う
        case SW_STS_DETECTING: 
            if( RET_CHANGED == startWait( elapsedTime ) ) {
                // ステータス移行した場合、スイッチを離すまでの経過時間から長押し判定を行う
                if( elapsedTime > this->holdDownTime ) {
                    retValue = RET_HOLDDOWN;
                } else {
                    retValue = RET_SHORTDOWN;
                }
            } else {
                // ステータス移行なしの場合は押されている状態を返す
                retValue = RET_PUSHING;
            }
            break;
        // ステータスが WAITINGの場合、STANDBYへの移行判定を行う
        case SW_STS_WAITING:
            startStandby( elapsedTime );
            break;
    }
    return retValue;
}
}
