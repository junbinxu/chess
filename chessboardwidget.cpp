#include "chessboardwidget.h"
#include "chesslog.h"
#include "chessinformation.h"
#include "chessdefine.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPixmapCache>
#include <QDebug>

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
    makeImageCache();
    fixWidth = CHESS_SIZE*10;
    fixHeight =CHESS_SIZE*11;
    setFixedSize(fixWidth, fixHeight);
    Chess_Trace(tr("new ChessBoardWidget"));
}

ChessBoardWidget::~ChessBoardWidget()
{
    Chess_Trace(tr("delete ChessBoardWidget"));
}

void  ChessBoardWidget::makeImageCache()
{
    QString id;
    for(int i=0; i<=34; ++i)
    {
        id = QString::number(i);
        QPixmapCache::insert(id, QPixmap(":/image/"+id+".png"));
    }
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
    QString key = "33";
    if(ChessInformation::instance()->isBlack())
    {
        //黑方
        key = "34";
    }
    QPixmap pixmap;
    if(QPixmapCache::find(key, &pixmap))
    {
        pixmap.load(":/image/"+key+".png");
    }
    QRectF target(0.0, 0.0, fixWidth, fixHeight);
    QRectF source(0.0, 0.0, pixmap.width(), pixmap.height());
    //qDebug() << target << source;
    painter.drawPixmap(target, pixmap, source);
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
