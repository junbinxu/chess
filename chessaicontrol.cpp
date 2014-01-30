#include "chessaicontrol.h"
#include "chessengine.h"
#include "chessengineeleeye.h"
#include "chesslog.h"

ChessAIControl * ChessAIControl::INSTANCE = 0;

ChessAIControl * ChessAIControl::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessAIControl;
    }
    return INSTANCE;
}

ChessAIControl::ChessAIControl(QObject *parent) :
    ChessOpposition(parent), engine(0)
{
    engine = ChessEngineEleeye::instance();
    connect(engine, SIGNAL(write(QString)), this, SLOT(receive(QString)));
    Chess_Trace(tr("new ChessAIControl"));
}

ChessAIControl::~ChessAIControl()
{
    if(engine) delete engine;
    Chess_Trace(tr("delete ChessAIControl"));
}

void ChessAIControl::send(const QString &message)
{
    engine->read(message);
}

