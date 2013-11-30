#ifndef CHESSMANUAL_H
#define CHESSMANUAL_H

#include "chessdefine.h"
#include <QList>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class ChessManual
{
    Q_DISABLE_COPY(ChessManual)
public:
    static ChessManual *instance();
    void saveChessManual();

private:
    explicit ChessManual();
    static ChessManual *INSTANCE;

    QList<QString> manual;

    void writeSetup(int i);
};

#endif // CHESSMANUAL_H
