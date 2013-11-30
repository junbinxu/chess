#include "chess.h"
#include "chesslog.h"
#include "chesscenterwidget.h"

Chess * Chess::INSTANCE = 0;

Chess * Chess::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new Chess;
    }
    return INSTANCE;
}

Chess::Chess(QWidget *parent) :
    QMainWindow(parent)
{


    setCentralWidget(ChessCenterWidget::instance());


    Chess_Trace(tr("new Chess"));
}

Chess::~Chess()
{
    Chess_Trace(tr("delete Chess"));
}
