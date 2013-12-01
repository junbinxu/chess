#include "chess.h"
#include "chesslog.h"
#include "chesscenterwidget.h"
#include "chessinformation.h"
#include "chesssetting.h"
#include "chessdata.h"
#include "chesscore.h"
#include "chesssound.h"
#include "chessrule.h"
#include "chessmanual.h"
#include "chessdispatch.h"

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
    init();

    setCentralWidget(ChessCenterWidget::instance());


    setWindowTitle(tr("Chinese Chess"));
    Chess_Trace(tr("new Chess"));
}

Chess::~Chess()
{
    delete ChessSound::instance();
    delete ChessManual::instance();
    delete ChessRule::instance();
    delete ChessData::instance();
    delete ChessDispatch::instance();
    delete ChessCore::instance();

    delete ChessInformation::instance();
    delete ChessSetting::instance();
    Chess_Trace(tr("delete Chess"));
}

void Chess::init()
{
    ChessData::instance();
    ChessRule::instance();
    ChessSound::instance();
    ChessManual::instance();
    ChessDispatch::instance();
    ChessCore::instance();
}
