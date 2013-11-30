#ifndef CHESSCLIENT_H
#define CHESSCLIENT_H

#include "chessdispatch.h"

class ChessClient : public ChessDispatch
{
    Q_OBJECT
public:
    explicit ChessClient(QObject *parent = 0);

signals:

public slots:

};

#endif // CHESSCLIENT_H
