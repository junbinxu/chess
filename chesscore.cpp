#include "chesscore.h"
#include "chesslog.h"
#include "chessdata.h"
#include "chessinformation.h"
#include "chessboardwidget.h"

ChessCore * ChessCore::INSTANCE = 0;

ChessCore * ChessCore::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessCore;
    }
    return INSTANCE;
}

ChessCore::ChessCore(QObject *parent) :
    QObject(parent)
{
    myTurn = (ChessInformation::instance()->isRed()) ? true : false;
    Chess_Trace(tr("new ChessCore"));
}

ChessCore::~ChessCore()
{
    Chess_Trace(tr("delete ChessCore"));
}

void ChessCore::selectEmpty()
{
    Chess_Info("select empty");
    if(!isMyTurn())
    {
        Chess_Info("not my turn");
        return;
    }


    ChessBoardWidget::instance()->update();
}

void ChessCore::selectChess(int id, const QPoint &p)
{
    Chess_Info(QString("select %1 at (%2, %3)").arg(id).arg(p.x()).arg(p.y()));
    if(!isMyTurn())
    {
        Chess_Info("not my turn");
        return;
    }
    ChessData *d = ChessData::instance();
    if(d->isMine(id))
    {
        Chess_Info("select myself");
        d->selectChess(p);
    }
    else
    {
        Chess_Info("select opposity");
    }

    ChessBoardWidget::instance()->update();
}
