#include "chessboardwidget.h"
#include "chesslog.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPixmapCache>

ChessBoardWidget * ChessBoardWidget::INSTANCE = 0;

ChessBoardWidget * ChessBoardWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessBoardWidget;
    }
    return INSTANCE;
}

ChessBoardWidget::ChessBoardWidget(QWidget *parent) :
    QWidget(parent)
{
    makeBoardCache();
    makeChessesCache();
    Chess_Trace(tr("new ChessBoardWidget"));
}

ChessBoardWidget::~ChessBoardWidget()
{
    Chess_Trace(tr("delete ChessBoardWidget"));
}

void  ChessBoardWidget::makeBoardCache()
{

}

void ChessBoardWidget::makeChessesCache()
{

}

void ChessBoardWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    paintBoard(painter);
    paintChesses(painter);
    paintSelectedChess(painter);
    paintLastLines(painter);
    paintSetupChoice(painter);
}

void ChessBoardWidget::paintBoard(QPainter &painter)
{

}

void ChessBoardWidget::paintChesses(QPainter &painter)
{

}

void ChessBoardWidget::paintSelectedChess(QPainter &painter)
{

}

void ChessBoardWidget::paintLastLines(QPainter &painter)
{

}

void ChessBoardWidget::paintSetupChoice(QPainter &painter)
{

}

void ChessBoardWidget::mousePressEvent(QMouseEvent *event)
{

}

void ChessBoardWidget::mouseMoveEvent(QMouseEvent *event)
{

}

void ChessBoardWidget::mouseReleaseEvent(QMouseEvent *event)
{

}
