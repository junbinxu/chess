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
    Q_DISABLE_COPY(ChessServer)
public:
    static ChessServer *instance();
    ~ChessServer();
    bool isValid();
    void send(const QString &message);

signals:

public slots:
    void read();
    void newConnect();

private:
    static ChessServer *INSTANCE;
    explicit ChessServer(QObject *parent = 0);

    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // CHESSSERVER_H
