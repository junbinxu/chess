#include "chessserver.h"
#include "chesslog.h"
#include <QTcpServer>
#include <QTcpSocket>

ChessServer::ChessServer(QObject *parent) :
    ChessOpposition(parent)
{

    Chess_Trace(tr("new ChessServer"));
}

ChessServer::~ChessServer()
{
    Chess_Trace(tr("delete ChessServer"));
}

bool ChessServer::isValid()
{
    return false;
}

void ChessServer::send(const QString &message)
{
    Q_UNUSED(message);
}
