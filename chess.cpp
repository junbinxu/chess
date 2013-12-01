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
#include "chessprotocol.h"
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>

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

    initMenuBar();
    initToolBar();
    setCentralWidget(ChessCenterWidget::instance());


    setWindowTitle(tr("Chinese Chess"));
    Chess_Trace(tr("new Chess"));
}

Chess::~Chess()
{
    delete ChessSound::instance();
    delete ChessProtocol::instance();
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
    ChessProtocol::instance();
    ChessSound::instance();
    ChessManual::instance();
    ChessDispatch::instance();
    ChessCore::instance();
}

void Chess::initMenuBar()
{
    helpMenu = new QMenu(tr("&Help"), this);
    aboutQtAction = new QAction(tr("about qt"), 0);
    helpMenu->addAction(aboutQtAction);
    aboutChineseChessAction = new QAction(tr("about this"), 0);
    helpMenu->addAction(aboutChineseChessAction);

    QMenuBar *mb = menuBar();
    mb->addMenu(helpMenu);
}

void Chess::initToolBar()
{

}
