#ifndef CHESSDEFINE_H
#define CHESSDEFINE_H

#include <QtGlobal>
#include <QString>

//(major << 16) + (minor << 8) + patch
#define CHESS_VERSION_STR "1.0.0"
#define CHESS_VERSION_INT 0x010000

#define CHESS_MANUAL_FILE_VERSION_STR "1.0.0"
#define CHESS_MANUAL_FILE_VERSION_INT 0x010000

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
enum ChessChess
{
    NO_CHESS = 0,
    RED_KING = 1,
    RED_SHI1 = 2,
    RED_SHI2 = 3,
    RED_XIANG1 = 4,
    RED_XIANG2 = 5,
    RED_MA1 = 6,
    RED_MA2 = 7,
    RED_JU1 = 8,
    RED_JU2 = 9,
    RED_PAO1 = 10,
    RED_PAO2 = 11,
    RED_BZ1 = 12,
    RED_BZ2 = 13,
    RED_BZ3 = 14,
    RED_BZ4 = 15,
    RED_BZ5 = 16,
    BLACK_KING = 17,
    BLACK_SHI1 = 18,
    BLACK_SHI2 = 19,
    BLACK_XIANG1 = 20,
    BLACK_XIANG2 = 21,
    BLACK_MA1 = 22,
    BLACK_MA2 = 23,
    BLACK_JU1 = 24,
    BLACK_JU2 = 25,
    BLACK_PAO1 = 26,
    BLACK_PAO2 = 27,
    BLACK_BZ1 = 28,
    BLACK_BZ2 = 29,
    BLACK_BZ3 = 30,
    BLACK_BZ4 = 31,
    BLACK_BZ5 = 32
};
























#endif // CHESSDEFINE_H
