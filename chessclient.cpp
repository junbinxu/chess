#include "chessclient.h"
#include "chesslog.h"
#include "chessinformation.h"
#include <QTcpSocket>

ChessClient * ChessClient::INSTANCE = 0;

ChessClient * ChessClient::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessClient;
    }
    return INSTANCE;
}

ChessClient::ChessClient(QObject *parent) :
    ChessOpposition(parent), socket(0)
{
    QString ip = ChessInformation::instance()->getServerIp();
    quint16 port = ChessInformation::instance()->getServerPort();
    socket = new QTcpSocket(this);
    socket->connectToHost(ip, port);
    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));

    Chess_Trace(tr("new ChessClient"));
}

ChessClient::~ChessClient()
{
    Chess_Trace(tr("delete ChessClient"));
}

bool ChessClient::isValid()
{
    if(socket)
    {
        if(socket->state() != QAbstractSocket::ConnectedState) return false;
        if(socket->isValid()) return true;
    }
    return false;
}

void ChessClient::send(const QString &message)
{
    if(isValid())
    {
        socket->write(message.toLocal8Bit());
    }
}

void ChessClient::read()
{
    receive(QString(socket->readAll()));
}







