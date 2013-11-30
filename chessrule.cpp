#include "chessrule.h"
#include "chesslog.h"
#include <QObject>

ChessRule * ChessRule::INSTANCE = 0;

ChessRule * ChessRule::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessRule;
    }
    return INSTANCE;
}

ChessRule::ChessRule()
{

    Chess_Trace(QObject::tr("new ChessRule"));
}

ChessRule::~ChessRule()
{
    Chess_Trace(QObject::tr("delete ChessRule"));
}
