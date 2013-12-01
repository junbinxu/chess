#include "chessserver.h"
#include "chesslog.h"
#include "chessinformation.h"
#include <QTcpServer>
#include <QTcpSocket>

ChessServer * ChessServer::INSTANCE = 0;

ChessServer * ChessServer::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessServer;
    }
    return INSTANCE;
}

ChessServer::ChessServer(QObject *parent) :
    ChessOpposition(parent), socket(0)
{
    server = new QTcpServer(this);
    quint16 port = ChessInformation::instance()->getServerPort();
    bool ok = server->listen(QHostAddress::Any, port);
    if(ok)
    {
        connect(server, SIGNAL(newConnection()), this, SLOT(newConnect()));
        Chess_Info(tr("start server at port=%1 ok").arg(port));
    }
    else
    {
        Chess_Error(tr("server listen error"));
    }

    Chess_Trace(tr("new ChessServer"));
}

ChessServer::~ChessServer()
{
    Chess_Trace(tr("delete ChessServer"));
}

bool ChessServer::isValid()
{
    if(socket)
    {
        if(socket->state() != QAbstractSocket::ConnectedState) return false;
        if(socket->isValid()) return true;
    }
    return false;
}

void ChessServer::newConnect()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
}

void ChessServer::read()
{
    receive(QString(socket->readAll()));
}

void ChessServer::send(const QString &message)
{
    if(isValid())
    {
        socket->write(message.toLocal8Bit());
    }
}

