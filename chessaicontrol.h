#ifndef CHESSAICONTROL_H
#define CHESSAICONTROL_H

#include "chessdispatch.h"

class ChessAIControl : public ChessDispatch
{
    Q_OBJECT
public:
    explicit ChessAIControl(QObject *parent = 0);

signals:

public slots:

};

#endif // CHESSAICONTROL_H
