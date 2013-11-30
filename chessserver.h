#ifndef CHESSSERVER_H
#define CHESSSERVER_H

#include "chessopposition.h"

QT_BEGIN_NAMESPACE
class QTcpSocket;
class QTcpServer;
QT_END_NAMESPACE

class ChessServer : public ChessOpposition
{
    Q_OBJECT
public:
    explicit ChessServer(QObject *parent = 0);
    ~ChessServer();
    bool isValid();
    void send(const QString &message);

signals:

public slots:

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // CHESSSERVER_H
