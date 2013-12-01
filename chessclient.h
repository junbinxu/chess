#ifndef CHESSCLIENT_H
#define CHESSCLIENT_H

#include "chessopposition.h"

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE

class ChessClient : public ChessOpposition
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessClient)
public:
    static ChessClient *instance();
    ~ChessClient();
    bool isValid();
    void send(const QString &message);

signals:

public slots:
    void read();

private:
    static ChessClient *INSTANCE;
    explicit ChessClient(QObject *parent = 0);

    QTcpSocket *socket;
};

#endif // CHESSCLIENT_H
