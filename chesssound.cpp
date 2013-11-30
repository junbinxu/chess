#include "chesssound.h"
#include "chesslog.h"
#include <QObject>

ChessSound * ChessSound::INSTANCE = 0;

ChessSound * ChessSound::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessSound;
    }
    return INSTANCE;
}

ChessSound::ChessSound()
{

    Chess_Trace(QObject::tr("new ChessSound"));
}

ChessSound::~ChessSound()
{
    Chess_Trace(QObject::tr("delete ChessSound"));
}
