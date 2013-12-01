#ifndef CHESSPROTOCOL_H
#define CHESSPROTOCOL_H

#include <QString>

class ChessProtocol
{
    Q_DISABLE_COPY(ChessProtocol)
public:
    static ChessProtocol *instance();
    ~ChessProtocol();

private:
    static ChessProtocol *INSTANCE;
    explicit ChessProtocol();
};

#endif // CHESSPROTOCOL_H
