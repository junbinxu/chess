#include "chessprotocol.h"
#include "chesslog.h"
#include <QObject>

ChessProtocol * ChessProtocol::INSTANCE = 0;

ChessProtocol * ChessProtocol::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessProtocol;
    }
    return INSTANCE;
}

ChessProtocol::ChessProtocol()
{

    Chess_Trace(QObject::tr("new ChessProtocol"));
}

ChessProtocol::~ChessProtocol()
{
    Chess_Trace(QObject::tr("delete ChessProtocol"));
}
