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
#include "chessversion.h"
#include "chessversiondialog.h"
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QMessageBox>
#include <QTimer>

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
    ChessVersion::instance();
    ChessVersionDialog::instance();
    ChessData::instance();
    ChessRule::instance();
    ChessProtocol::instance();
    ChessSound::instance();
    ChessManual::instance();
    ChessDispatch::instance();
    ChessCore::instance();

    initActions();
    initMenuBar();
    initToolBar();
    setCentralWidget(ChessCenterWidget::instance());

    // 中国象棋
    setWindowTitle(QString::fromUtf8("\xe4\xb8\xad\xe5\x9b\xbd\xe8\xb1\xa1\xe6\xa3\x8b"));
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
    delete ChessVersionDialog::instance();
    delete ChessVersion::instance();
    delete ChessInformation::instance();
    delete ChessSetting::instance();
    Chess_Trace(tr("delete Chess"));
}

void Chess::closeEvent(QCloseEvent *event)
{
    exitGame();
}

void Chess::initActions()
{
    // 关于 Qt
    aboutQtAction = new QAction(QString::fromUtf8("\xe5\x85\xb3\xe4\xba\x8e\x20\x51\x74"), this);
    connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));
    // 关于中国象棋
    aboutChineseChessAction = new QAction(QString::fromUtf8("\xe5\x85\xb3\xe4\xba\x8e\xe4\xb8\xad\xe5\x9b\xbd\xe8\xb1\xa1\xe6\xa3\x8b"), this);
    connect(aboutChineseChessAction, SIGNAL(triggered()),
            ChessVersionDialog::instance(), SLOT(show()));

    newGameAction = new QAction(QString::fromUtf8("\xE6\x96\xB0\xE5\xBB\xBA"), this);
    connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

    startGameAction = new QAction(QString::fromUtf8("\xE5\xBC\x80\xE5\xA7\x8B"), this);
    connect(startGameAction, SIGNAL(triggered()), this, SLOT(startGame()));

    changeGameAction = new QAction(QString::fromUtf8("\xE4\xBA\xA4\xE6\x8D\xA2"), this);
    connect(changeGameAction, SIGNAL(triggered()), this, SLOT(changeGame()));

    exitGameAction = new QAction(QString::fromUtf8("\xE9\x80\x80\xE5\x87\xBA"), this);
    connect(exitGameAction, SIGNAL(triggered()), this, SLOT(exitGame()));

    saveGameAction = new QAction(QString::fromUtf8("\xE4\xBF\x9D\xE5\xAD\x98"), this);
    connect(saveGameAction, SIGNAL(triggered()), this, SLOT(saveGame()));
}

void Chess::initMenuBar()
{
    // 帮助(&H)
    helpMenu = new QMenu(QString::fromUtf8("\xe5\xb8\xae\xe5\x8a\xa9\x28\x26\x48\x29"), this);
    helpMenu->addAction(aboutQtAction);
    helpMenu->addAction(aboutChineseChessAction);

    QMenuBar *mb = menuBar();
    mb->addMenu(helpMenu);
}

void Chess::initToolBar()
{
    toolbar = addToolBar("chess");
    toolbar->addAction(newGameAction);
    toolbar->addAction(startGameAction);
    toolbar->addAction(changeGameAction);
    toolbar->addAction(saveGameAction);
    toolbar->addAction(exitGameAction);
}

void Chess::aboutQt()
{
    // 关于 Qt
    QMessageBox::aboutQt(this, QString::fromUtf8("\xe5\x85\xb3\xe4\xba\x8e\x20\x51\x74"));
}

void Chess::newGame()
{

}

void Chess::startGame()
{
    ChessCore::instance()->startGame();
}

void Chess::exitGame()
{
    ChessCore::instance()->exitGame();
    QTimer::singleShot(1000, this, SLOT(close()));
}

void Chess::changeGame()
{

}

void Chess::saveGame()
{

}
