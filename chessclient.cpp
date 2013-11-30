#include "chessclient.h"
#include "chesslog.h"
#include <QTcpSocket>

ChessClient::ChessClient(QObject *parent) :
    ChessOpposition(parent)
{

    Chess_Trace(tr("new ChessClient"));
}

ChessClient::~ChessClient()
{
    Chess_Trace(tr("delete ChessClient"));
}

bool ChessClient::isValid()
{
    return false;
}

void ChessClient::send(const QString &message)
{
    Q_UNUSED(message);
}
