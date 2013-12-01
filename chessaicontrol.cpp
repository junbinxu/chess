#include "chessaicontrol.h"
#include "chesslog.h"

ChessAIControl * ChessAIControl::INSTANCE = 0;

ChessAIControl * ChessAIControl::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessAIControl;
    }
    return INSTANCE;
}

ChessAIControl::ChessAIControl(QObject *parent) :
    ChessOpposition(parent)
{

    Chess_Trace(tr("new ChessAIControl"));
}

ChessAIControl::~ChessAIControl()
{
    Chess_Trace(tr("delete ChessAIControl"));
}

void ChessAIControl::send(const QString &message)
{
    Q_UNUSED(message);
}
