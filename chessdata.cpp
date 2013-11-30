#include "chessdata.h"
#include "chesslog.h"
#include <QObject>

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

    Chess_Trace(QObject::tr("new ChessData"));
}

ChessData::~ChessData()
{
    Chess_Trace(QObject::tr("delete ChessData"));
}
