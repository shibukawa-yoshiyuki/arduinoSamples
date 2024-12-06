# MusicalComposition Namespace 定義
## Ⅰ.概要
### Ⅰ-ⅰ 名前空間パラメータ

|Parameter |Value |Note |
|:---|---:|:---|
|namespace |MusicalComposition |楽曲名前空間 |

### Ⅰ-ⅱ 概要
楽曲データ関連定義 

## Ⅱ.メンバ定義
### Ⅱ-ⅰ.列挙定数
1. musicalScale  
fig2-1 の音階 C3 から B5 までに該当する周波数を定義
![figure2-1](img/Octaves.png)  
**fig2-1 階名対照表([Wikipedia](https://ja.wikipedia.org/wiki/%E9%9F%B3%E5%90%8D%E3%81%A8%E9%9A%8E%E5%90%8D#/media/%E3%83%95%E3%82%A1%E3%82%A4%E3%83%AB:Octaves.png)より引用)**  

|No |ID |Access |Type |Value |Abstruct |
|:---:|:---|:---|:---:|---:|:---|
|1 |MUSICAL_SCALE_DO3 |public |unsigned int |131U |音高周波数(C3) |
|2 |MUSICAL_SCALE_DI3 |public |unsigned int |139U |音高周波数(C3#) |
|3 |MUSICAL_SCALE_RE3 |public |unsigned int |147U |音高周波数(D3) |
|4 |MUSICAL_SCALE_RI3 |public |unsigned int |156U |音高周波数(D3#) |
|5 |MUSICAL_SCALE_MI3 |public |unsigned int |165U |音高周波数(E3) |
|6 |MUSICAL_SCALE_FA3 |public |unsigned int |175U |音高周波数(F3) |
|7 |MUSICAL_SCALE_FI3 |public |unsigned int |195U |音高周波数(F3#) |
|8 |MUSICAL_SCALE_SO3 |public |unsigned int |196U |音高周波数(G3) |
|9 |MUSICAL_SCALE_SI3 |public |unsigned int |208U |音高周波数(G3#) |
|10 |MUSICAL_SCALE_LA3 |public |unsigned int |220U |音高周波数(A3) |
|11 |MUSICAL_SCALE_LI3 |public |unsigned int |233U |音高周波数(A3#) |
|12 |MUSICAL_SCALE_TI3 |public |unsigned int |247U |音高周波数(B3) |
|13 |MUSICAL_SCALE_DO4 |public |unsigned int |262U |音高周波数(C4) |
|14 |MUSICAL_SCALE_DI4 |public |unsigned int |277U |音高周波数(C4#) |
|15 |MUSICAL_SCALE_RE4 |public |unsigned int |294U |音高周波数(D4) |
|16 |MUSICAL_SCALE_RI4 |public |unsigned int |311U |音高周波数(D4#) |
|17 |MUSICAL_SCALE_MI4 |public |unsigned int |330U |音高周波数(E4) |
|18 |MUSICAL_SCALE_FA4 |public |unsigned int |349U |音高周波数(F4) |
|19 |MUSICAL_SCALE_FI4 |public |unsigned int |370U |音高周波数(F4#) |
|20 |MUSICAL_SCALE_SO4 |public |unsigned int |392U |音高周波数(G4) |
|21 |MUSICAL_SCALE_SI4 |public |unsigned int |415U |音高周波数(G4#) |
|22 |MUSICAL_SCALE_LA4 |public |unsigned int |440U |音高周波数(A4) |
|23 |MUSICAL_SCALE_LI4 |public |unsigned int |466U |音高周波数(A4#) |
|24 |MUSICAL_SCALE_TI4 |public |unsigned int |494U |音高周波数(B4) |
|25 |MUSICAL_SCALE_DO5 |public |unsigned int |523U |音高周波数(C5) |
|26 |MUSICAL_SCALE_DI5 |public |unsigned int |554U |音高周波数(C5#) |
|27 |MUSICAL_SCALE_RE5 |public |unsigned int |587U |音高周波数(D5) |
|28 |MUSICAL_SCALE_RI5 |public |unsigned int |622U |音高周波数(D5#) |
|29 |MUSICAL_SCALE_MI5 |public |unsigned int |659U |音高周波数(E5) |
|30 |MUSICAL_SCALE_FA5 |public |unsigned int |698U |音高周波数(F5) |
|31 |MUSICAL_SCALE_FI5 |public |unsigned int |740U |音高周波数(F5#) |
|32 |MUSICAL_SCALE_SO5 |public |unsigned int |784U |音高周波数(G5) |
|33 |MUSICAL_SCALE_SI5 |public |unsigned int |801U |音高周波数(G5#) |
|34 |MUSICAL_SCALE_LA5 |public |unsigned int |880U |音高周波数(A5) |
|35 |MUSICAL_SCALE_LI5 |public |unsigned int |932U |音高周波数(A5#) |
|36 |MUSICAL_SCALE_TI5 |public |unsigned int |988U |音高周波数(B5) |
|37 |MUSICAL_SCALE_NAN |public |unsigned int |0U |音なし(休符など) |
|38 |MUSICAL_SCALE_END |public |unsigned int |9999U |データ終端 |

> [!NOTE]
> この周波数値は整数値とするため、小数点以下は四捨五入している  

2. musicalNote  

|No |ID |Access |Type |Value |Abstruct |
|:---:|:---|:---|:---:|---:|:---|
|1 |MUSICAL_NOTE_1 |public |unsigned int |32U |全音符 |
|2 |MUSICAL_NOTE_1-2 |public |unsigned int |16U |二分音符 |
|3 |MUSICAL_DOTTED_NOTE_1-2 |public |unsigned int |24U |付点付き二分音符 |
|4 |MUSICAL_NOTE_1-4 |public |unsigned int |8U |四分音符 |
|5 |MUSICAL_DOTTED_NOTE_1-4 |public |unsigned int |12U |付点付き四分音符 |
|6 |MUSICAL_NOTE_1-8 |public |unsigned int |4U |八分音符 |
|7 |MUSICAL_DOTTED_NOTE_1-8 |public |unsigned int |6U |付点付き八分音符 |
|8 |MUSICAL_NOTE_1-16 |public |unsigned int |2U |十六分音符 |
|9 |MUSICAL_DOTTED_NOTE_1-16 |public |unsigned int |3U |付点付き十六分音符 |
|10 |MUSICAL_NOTE_1-32 |public |unsigned int |1U |三十二分音符 |
|11 |MUSICAL_REST_1 |public |unsigned int |32U |全休符 |
|12 |MUSICAL_REST_1-2 |public |unsigned int |16U |二分休符 |
|13 |MUSICAL_DOTTED_REST_1-2 |public |unsigned int |24U |付点付き二分休符 |
|14 |MUSICAL_REST_1-4 |public |unsigned int |8U |四分休符 |
|15 |MUSICAL_DOTTED_REST_1-4 |public |unsigned int |12U |付点付き四分休符 |
|16 |MUSICAL_REST_1-8 |public |unsigned int |4U |八分休符 |
|17 |MUSICAL_DOTTED_REST_1-8 |public |unsigned int |6U |付点付き八分休符 |
|18 |MUSICAL_REST_1-16 |public |unsigned int |2U |十六分休符 |
|19 |MUSICAL_DOTTED_REST_1-16 |public |unsigned int |3U |付点付き十六分休符 |
|20 |MUSICAL_REST_1-32 |public |unsigned int |1U |三十二分休符 |

### Ⅱ-ⅱ.構造体
1. musicData  
   
|No |ID |Access |Type |Abstruct |
|:---:|:---|:---|:---:|:---|
|1 |musicScale |private |unsigned int |音高 | 
|2 |musicNote |public |unsigned int |拍 | 
