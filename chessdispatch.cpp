#include "chessdispatch.h"
#include "chessreplay.h"
#include "chessserver.h"
#include "chessclient.h"
#include "chessaicontrol.h"
#include "chessinformation.h"
#include "chesslog.h"
#include "chessprotocol.h"

ChessDispatch * ChessDispatch::INSTANCE = 0;

ChessDispatch *ChessDispatch::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessDispatch;
    }
    return INSTANCE;
}

ChessDispatch::ChessDispatch(QObject *parent) :
    QObject(parent), chessOpposition(0)
{
    switch(ChessInformation::instance()->getChessType())
    {
    case(ReplayType): chessOpposition = ChessReplay::instance(); break;
    case(ServerType): chessOpposition = ChessServer::instance(); break;
    case(ClientType): chessOpposition = ChessClient::instance(); break;
    case(AIType): chessOpposition = ChessAIControl::instance(); break;
    default: Chess_Fatal(tr("chess type error!")); break;
    }
    Chess_Trace(tr("new ChessDispatch"));
}

ChessDispatch::~ChessDispatch()
{
    delete chessOpposition;
    chessOpposition = 0;
    Chess_Trace(tr("delete ChessDispatch"));
}

bool ChessDispatch::isValid()
{
    if(chessOpposition) return chessOpposition->isValid();
    else return false;
}

void ChessDispatch::send(const QString &message)
{
    Chess_Info("send: "+message);
    if(chessOpposition) chessOpposition->send(message);
}

void ChessDispatch::receive(const QString &message)
{
    Chess_Info("receive: "+message);
    ChessProtocol::instance()->receiveMessage(message);
}
