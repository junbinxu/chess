#include "chessrule.h"

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
}
