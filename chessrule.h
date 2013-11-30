#ifndef CHESSRULE_H
#define CHESSRULE_H

#include <QtGlobal>

class ChessRule
{
    Q_DISABLE_COPY(ChessRule)
public:
    static ChessRule *instance();

private:
    static ChessRule *INSTANCE;
    explicit ChessRule();
};

#endif // CHESSRULE_H
