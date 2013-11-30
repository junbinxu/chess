#include "chessinformation.h"
#include "chesslog.h"
#include <QObject>

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
    Chess_Trace(QObject::tr("new ChessInformation"));
}

ChessInformation::~ChessInformation()
{
    Chess_Trace(QObject::tr("delete ChessInformation"));
}

void ChessInformation::init(ChessType ct, ChessColor cc, QString ip, quint16 port)
{
    chessType = ct;
    chessColor = cc;
    serverIP = ip;
    serverPort = port;
    Chess_Info(QObject::tr("init chess information"));
}
