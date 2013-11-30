#ifndef CHESSCLIENT_H
#define CHESSCLIENT_H

#include "chessopposition.h"

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE

class ChessClient : public ChessOpposition
{
    Q_OBJECT
public:
    explicit ChessClient(QObject *parent = 0);
    ~ChessClient();
    bool isValid();
    void send(const QString &message);

signals:

public slots:

private:
    QTcpSocket *socket;
};

#endif // CHESSCLIENT_H
