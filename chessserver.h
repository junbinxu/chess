#ifndef CHESSSERVER_H
#define CHESSSERVER_H

#include "chessdispatch.h"

class ChessServer : public ChessDispatch
{
    Q_OBJECT
public:
    explicit ChessServer(QObject *parent = 0);

signals:

public slots:

};

#endif // CHESSSERVER_H
