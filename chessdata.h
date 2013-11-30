#ifndef CHESSDATA_H
#define CHESSDATA_H

#include <QtGlobal>

class ChessData
{
    Q_DISABLE_COPY(ChessData)
public:
    static ChessData *instance();

private:
    static ChessData *INSTANCE;
    explicit ChessData();
};

#endif // CHESSDATA_H
