#ifndef CHESSDEFINE_H
#define CHESSDEFINE_H

#include <QtGlobal>
#include <QString>

//(major << 16) + (minor << 8) + patch
#define CHESS_VERSION_STR "1.0.0"
#define CHESS_VERSION_INT 0x010000

#define CHESS_MANUAL_FILE_VERSION_STR "1.0.0"
#define CHESS_MANUAL_FILE_VERSION_INT 0x010000

#define CHESS_SIZE 60

//
enum LogLevel
{
    TraceLevel = 0,
    DebugLevel,
    InfoLevel,
    WarnLevel,
    ErrorLevel,
    FatalLevel
};

//
enum TipsLevel
{
    NormalLevel = 0,
    ImportantLevel,
    SeriousLevel
};

//
enum  ChessType
{
    ServerType = 1,
    ClientType,
    ReplayType,
    AIType
};
//
enum ChessColor
{
    RedColor = 0,
    BlackColor = 1
};
//
enum ChessResult
{
    Both_Unknown = -1,
    Both_Draw = 0,
    RedWin_BlackLose = 1,
    RedWin_BlackRenounce = 2,
    BlackWin_RedLose = 3,
    BlackWin_RedRenounce = 4
};

//

#define RED_SHUAI       0
#define RED_JU1         1
#define RED_JU2         2
#define RED_MA1         3
#define RED_MA2         4
#define RED_PAO1        5
#define RED_PAO2        6
#define RED_SHI1        7
#define RED_SHI2        8
#define RED_XIANG1      9
#define RED_XIANG2      10
#define RED_BING1       11
#define RED_BING2       12
#define RED_BING3       13
#define RED_BING4       14
#define RED_BING5       15
#define BLACK_JIANG     16
#define BLACK_JU1       17
#define BLACK_JU2       18
#define BLACK_MA1       19
#define BLACK_MA2       20
#define BLACK_PAO1      21
#define BLACK_PAO2      22
#define BLACK_SHI1      23
#define BLACK_SHI2      24
#define BLACK_XIANG1    25
#define BLACK_XIANG2    26
#define BLACK_ZU1       27
#define BLACK_ZU2       28
#define BLACK_ZU3       29
#define BLACK_ZU4       30
#define BLACK_ZU5       31
#define EMPTY_CHESS     32
#define RED_BOARD       33
#define BLACK_BOARD     34























#endif // CHESSDEFINE_H
