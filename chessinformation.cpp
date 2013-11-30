#include "chessinformation.h"

ChessInformation * ChessInformation::INSTANCE = 0;

ChessInformation * ChessInformation::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessInformation;
    }
    return INSTANCE;
}

ChessInformation::ChessInformation()
{
}

void ChessInformation::init(ChessType ct, ChessColor cc, QString ip, quint16 port)
{
    chessType = ct;
    chessColor = cc;
    serverIP = ip;
    serverPort = port;
}
