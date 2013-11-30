#ifndef CHESSREPLAY_H
#define CHESSREPLAY_H

#include "chessdispatch.h"

class ChessReplay : public ChessDispatch
{
    Q_OBJECT
public:
    explicit ChessReplay(QObject *parent = 0);

signals:

public slots:

};

#endif // CHESSREPLAY_H
