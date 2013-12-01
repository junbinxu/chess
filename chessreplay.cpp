#include "chessreplay.h"
#include "chesslog.h"

ChessReplay * ChessReplay::INSTANCE = 0;

ChessReplay * ChessReplay::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessReplay;
    }
    return INSTANCE;
}

ChessReplay::ChessReplay(QObject *parent) :
    ChessOpposition(parent)
{

    Chess_Trace(tr("new ChessReplay"));
}

ChessReplay::~ChessReplay()
{
    Chess_Trace(tr("delete ChessReplay"));
}

void ChessReplay::send(const QString &message)
{
    Q_UNUSED(message);
}
