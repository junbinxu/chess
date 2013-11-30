#include "chesssound.h"

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
}
