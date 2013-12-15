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
#include <QMessageBox>

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

    delete ChessInformation::instance();
    delete ChessSetting::instance();
    Chess_Trace(tr("delete Chess"));
}

void Chess::initActions()
{
    // 关于 Qt
    aboutQtAction = new QAction(QString::fromUtf8("\xe5\x85\xb3\xe4\xba\x8e\x20\x51\x74"), this);
    connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));
    // 关于中国象棋
    aboutChineseChessAction = new QAction(QString::fromUtf8("\xe5\x85\xb3\xe4\xba\x8e\xe4\xb8\xad\xe5\x9b\xbd\xe8\xb1\xa1\xe6\xa3\x8b"), this);
}

void Chess::aboutQt()
{
    // 关于 Qt
    QMessageBox::aboutQt(this, QString::fromUtf8("\xe5\x85\xb3\xe4\xba\x8e\x20\x51\x74"));
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

}
