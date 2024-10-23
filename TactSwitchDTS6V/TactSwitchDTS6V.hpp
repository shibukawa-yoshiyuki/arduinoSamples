#ifndef TACT_SWITCH_DTS6V_H
#define TACT_SWITCH_DTS6V_H
//
// Filename :   TactSwitchDTS6V.hpp
// Abstruct :   Class definition for Tact Switch
// Author   :   application_division@atit.jp
// Update   :   2024/10/11 New Creation

namespace ElectronicComponent {
//
// Class    :   TactSwitchDTS6V
// Abstruct :   Class definition for Tact Switch
class TactSwitchDTS6V {
    // Definition of constant
private:
    enum statusValue {
        SW_STS_STANDBY               = 0,       // ステータス(待機)
        SW_STS_DETECTING,                       // ステータス(検知中)
        SW_STS_WAITING                          // ステータス(復帰待ち)
    };
    enum intarnalReturnValue {
        RET_CHANGED                  = 4,       // ステータス変更あり
        RET_NOCHANGE                            // ステータス変更なし
    };
    const unsigned long DEF_LATENCY  = 30UL;    // レイテンシデフォルト値
    const unsigned long LATENCY_MAX  = 50UL;    // レイテンシ上限値
    const unsigned long DEF_HOLDDOWN = 2000UL;  // 長押し判定時間閾値デフォルト値
    const unsigned long HOLDDOWN_MIN = 2000UL;  // 長押し判定時間閾値下限値
    const unsigned long HOLDDOWN_MAX = 2000UL;  // 長押し判定時間閾値上限値
public:
    enum cercitType {
        TYPE_PULLUP                  = 0,       // 回路区分(プルアップ)
        TYPE_PULLDOWN                           // 回路区分(プルダウン)
    };
    enum returnValue {
        RET_SKIP                     = -99,     // 判定スキップまたは押されていない
        RET_PUSHING                  = 1,       // 押されている
        RET_SHORTDOWN,                          // 押された
        RET_HOLDDOWN                            // 長押しされた
    };
    // Definition of variable
private:
    unsigned int  pin;                          // 対向Arduinoピン番号
    int           swStatus;                     // 処理ステータス
    unsigned long detectTime;                   // ステータス変更時刻(msec)
    bool          isInterrupt;                  // 割り込み有無
    int           connected;                    // 未接続時状態
    int           unconnected;                  // 接続時状態
    unsigned long latency;                      // チャタリング防止レイテンシ(ms,デフォルト値30ms)
    unsigned long holdDownTime;                 // 長押し判定時間閾値(ms,デフォルト値2000ms)
    // Definition of method
private:
    int  startDetect();                         // Method:ステータス判定(to DETECTING)
    int  startWait( unsigned long );            // Method:ステータス判定(to WAITING)
    int  startStandby( unsigned long);          // Method:ステータス判定(to STAND_BY)
public:
    TactSwitchDTS6V( unsigned int );            // Method:コンストラクタ
    TactSwitchDTS6V( unsigned int, int );       // Method:コンストラクタ
    void setLatency( unsigned long );           // Method:チャタリング防止レイテンシ設定
    void setHoldDown( unsigned long );          // Method:長押し判定時間閾値設定
    void setNoInterrupt();                      // Method:割り込み設定
    void startInterrupt();                      // Method:割り込み時の判定(to DETECTING)
    int  getCondition();                        // Method:ボタン状態判定
};
}
#endif
