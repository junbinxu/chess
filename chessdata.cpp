#include "chessdata.h"

ChessData * ChessData::INSTANCE = 0;

ChessData * ChessData::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessData;
    }
    return INSTANCE;
}

ChessData::ChessData()
{
}
