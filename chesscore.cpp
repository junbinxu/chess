#include "chesscore.h"

ChessCore * ChessCore::INSTANCE = 0;

ChessCore * ChessCore::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessCore;
    }
    return INSTANCE;
}

ChessCore::ChessCore(QObject *parent) :
    QObject(parent)
{
}
