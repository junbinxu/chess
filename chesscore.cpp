#include "chesscore.h"
#include "chesslog.h"

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

    Chess_Trace(tr("new ChessCore"));
}

ChessCore::~ChessCore()
{
    Chess_Trace(tr("delete ChessCore"));
}
