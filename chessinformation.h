#ifndef CHESSINFORMATION_H
#define CHESSINFORMATION_H

#include "chessdefine.h"

class ChessInformation
{
public:
    static ChessInformation *instance();
    void init(ChessType ct, ChessColor cc, QString ip, quint16 port);
    inline bool isRed() const {return RedColor == chessColor;}
    inline bool isBlack() const {return BlackColor == chessColor;}
    inline bool isServer() const {return ServerType == chessType;}
    inline bool isClient() const {return ClientType == chessType;}
    inline bool isReplay() const {return ReplayType == chessType;}
    inline bool isAIType() const {return AIType == chessType;}
    inline ChessType getChessType() const {return chessType;}
    inline ChessColor getChessColor() const {return chessColor;}
    inline QString getServerIp() const {return serverIP;}
    inline quint16 getServerPort() const {return serverPort;}

private:
    explicit ChessInformation();
    static ChessInformation *INSTANCE;

    ChessType chessType;
    ChessColor chessColor;
    QString serverIP;
    quint16 serverPort;
};

#endif // CHESSINFORMATION_H
