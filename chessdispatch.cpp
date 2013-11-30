#include "chessdispatch.h"
#include "chessreplay.h"
#include "chessserver.h"
#include "chessclient.h"
#include "chessaicontrol.h"
#include "chessinformation.h"
#include "chesslog.h"

ChessOpposition * ChessDispatch::INSTANCE = 0;

ChessOpposition *ChessDispatch::instance()
{
    if(!INSTANCE)
    {
        switch(ChessInformation::instance()->getChessType())
        {
        case(ReplayType): INSTANCE = new ChessReplay; break;
        case(ServerType): INSTANCE = new ChessServer; break;
        case(ClientType): INSTANCE = new ChessClient; break;
        case(AIType): INSTANCE = new ChessAIControl; break;
        default: Chess_Fatal(tr("chess type error!")); break;
        }
    }
    return INSTANCE;
}

ChessDispatch::ChessDispatch(QObject *parent) :
    QObject(parent)
{

    Chess_Trace(tr("new ChessDispatch"));
}

ChessDispatch::~ChessDispatch()
{
    Chess_Trace(tr("delete ChessDispatch"));
}

bool ChessDispatch::isValid()
{
    if(INSTANCE) return INSTANCE->isValid();
    else return false;
}

void ChessDispatch::send(const QString &message)
{
    if(INSTANCE) INSTANCE->send(message);
}

void ChessDispatch::receive(const QString &message)
{
    Q_UNUSED(message);
}












