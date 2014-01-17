#include "chesscore.h"
#include "chesslog.h"
#include "chessdata.h"
#include "chessinformation.h"
#include "chessboardwidget.h"
#include "chessrule.h"
#include "chessprotocol.h"

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
    init();
    connect(ChessProtocol::instance(), SIGNAL(receiveChessMessage(int,int,QPoint,QPoint)),
            this, SLOT(receiveChessMessage(int,int,QPoint,QPoint)));
    Chess_Trace(tr("new ChessCore"));
}

ChessCore::~ChessCore()
{
    Chess_Trace(tr("delete ChessCore"));
}

void ChessCore::init()
{
    lastSelected = false;
    thisTurn = ChessInformation::instance()->isRed() ? true : false;
    thisReady = false;
    thatReady = false;

}

void ChessCore::selectEmpty(const QPoint &to)
{
    if(!thisTurn)
    {
        Chess_Info("not my turn");
        return;
    }
    Chess_Info(QString("select empty at (%1, %2)").arg(to.x()).arg(to.y()));
    ChessData *d = ChessData::instance();
    if(lastSelected)
    {
        QPoint from = d->getSelectedChess();
        int fid = d->isWho(from);

        if(isOK(to))
        {
            _moveChess(fid, to);
        }
    }
    else
    {
        d->clearSelectChess();
    }
    ChessBoardWidget::instance()->update();
}

void ChessCore::selectChess(int id, const QPoint &p)
{
    if(!thisTurn)
    {
        Chess_Info("not my turn");
        return;
    }
    Chess_Info(QString("select %1 at (%2, %3)").arg(id).arg(p.x()).arg(p.y()));
    ChessData *d = ChessData::instance();
    if(d->isMine(id))
    {
        _selectMyChess(id, p);
    }
    else
    {
        if(lastSelected)
        {
            if(isOK(p))
            {
                _eatChess(d->isWho(d->getSelectedChess()), id, p);
            }
        }
    }
    ChessBoardWidget::instance()->update();
}

void ChessCore::_moveChess(int fid, const QPoint &to)
{
    ChessData *d = ChessData::instance();
    ChessProtocol::instance()->sendChessMessgae(fid, EMPTY_CHESS, d->getPos(fid), to);
    d->moveChess(fid, to);
    lastSelected = false;
    thisTurn = false;
}

void ChessCore::_eatChess(int fid, int tid, const QPoint &to)
{
    ChessData *d = ChessData::instance();
    ChessProtocol::instance()->sendChessMessgae(fid, tid, d->getPos(fid), to);
    d->eatChess(fid, tid, to);
    lastSelected = false;
    thisTurn = false;
}

void ChessCore::_selectMyChess(int id, const QPoint &p)
{
    ChessData *d = ChessData::instance();
    d->setSelectedChess(p);
    lastSelected = true;
    d->setChoicePoints(ChessRule::instance()->getChoice(id, p));
}

bool ChessCore::isOK(const QPoint &p)
{
    return ChessData::instance()->isOK(p);
}

void ChessCore::receiveChessMessage(int fid, int tid, const QPoint &from, const QPoint &to)
{
    if(!(ChessRule::instance()->getChoice(fid, from).contains(to)))
    {
        Chess_Error("receive error move chess");
        return;
    }
    ChessData *d = ChessData::instance();
    if(EMPTY_CHESS == tid)
    {
        d->moveChess(fid, to);
    }
    else
    {
        d->eatChess(fid, tid, to);
    }
    thisTurn = true;
    ChessBoardWidget::instance()->update();
}
