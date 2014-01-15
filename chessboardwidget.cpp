#include "chessboardwidget.h"
#include "chesslog.h"
#include "chessinformation.h"
#include "chessdefine.h"
#include "chessdata.h"
#include "chesscore.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPixmapCache>
#include <QSizePolicy>
#include <QCursor>
#include <QList>
#include <QLine>
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
    setMouseTracking(true);
    makeImageCache();
    makePens();
    factor = CHESS_SIZE;
    halfFactor = factor/2.0;
    setMinimumSize(10*30, 11*30);
    QSizePolicy sp;
    sp.setHeightForWidth(true);
    setSizePolicy(sp);
    setFixedSize(factor*10, factor*11);
    Chess_Trace(tr("new ChessBoardWidget"));
}

ChessBoardWidget::~ChessBoardWidget()
{
    Chess_Trace(tr("delete ChessBoardWidget"));
}

void ChessBoardWidget::big()
{
    factor += 5;
    if(factor > 100) factor = 100;
    halfFactor = factor/2.0;
    setFixedSize(factor*10, factor*11);
}

void ChessBoardWidget::small()
{
    factor -= 5;
    if(factor < 30) factor = 30;
    halfFactor = factor/2.0;
    setFixedSize(factor*10, factor*11);
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

void ChessBoardWidget::makePens()
{
    selectedPen.setCapStyle(Qt::RoundCap);
    selectedPen.setColor(Qt::blue);
    selectedPen.setJoinStyle(Qt::RoundJoin);
    selectedPen.setStyle(Qt::SolidLine);
    selectedPen.setWidthF(3.0);

    linePen.setCapStyle(Qt::RoundCap);
    linePen.setColor(Qt::cyan);
    linePen.setJoinStyle(Qt::RoundJoin);
    linePen.setStyle(Qt::DashLine);
    linePen.setWidthF(3.0);

    choicePen.setCapStyle(Qt::RoundCap);
    choicePen.setColor(QColor(0, 255, 0, 150));
    choicePen.setJoinStyle(Qt::RoundJoin);
    choicePen.setStyle(Qt::DashLine);
    choicePen.setWidthF(3.0);
}

void ChessBoardWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    paintBoard(painter);
    paintChesses(painter);
    paintSelectedChess(painter);
    paintLastLines(painter);
    paintSetupChoice(painter);
}

bool ChessBoardWidget::isBlack() const
{
    return ChessInformation::instance()->isBlack();
}

double ChessBoardWidget::xLogToPhy(int x) const
{
    if(isBlack()) x = 8 - x;
    return (x+1)*factor;
}

double ChessBoardWidget::yLogToPhy(int y) const
{
    if(isBlack()) y = 9 - y;
    return (y+1)*factor;
}

int ChessBoardWidget::xPhyToLog(double x) const
{
    int t = x/factor-0.5;
    if(isBlack()) t = 8 - t;
    return t;
}

int ChessBoardWidget::yPhyToLog(double y) const
{
    int t = y/factor - 0.5;
    if(isBlack()) t = 9 - t;
    return t;
}

void ChessBoardWidget::paintBoard(QPainter &painter)
{
    QString key = QString::number(RED_BOARD);
    if(ChessInformation::instance()->isBlack())
    {
        //黑方
        key = QString::number(BLACK_BOARD);
    }
    QPixmap pixmap;
    if(!QPixmapCache::find(key, &pixmap))
    {
        Chess_Error("can not load image from cache: "+key);
        if(pixmap.load(":/image/"+key+".png"))
        {
            Chess_Info("load image from resource success: "+key);
        }
        else
        {
            Chess_Error("load image from resource fail: "+key);
        }
    }
    if((pixmap.width() ==0) || (pixmap.height() == 0))
    {
        Chess_Error("paint board fail: "+key);
        return;
    }
    QRectF target(0.0, 0.0, width(), height());
    QRectF source(0.0, 0.0, pixmap.width(), pixmap.height());
    painter.drawPixmap(target, pixmap, source);
}

void ChessBoardWidget::paintChesses(QPainter &painter)
{
    ChessData *d = ChessData::instance();
    QPoint point;
    QPixmap pixmap;
    QString key;
    for(int i=0; i<32; ++i)
    {
        if(d->isLive(i, &point))
        {
            key = QString::number(i);
            if(!QPixmapCache::find(key, &pixmap))
            {
                Chess_Error("can not load image from cache: "+key);
                if(pixmap.load(":/image/"+key+".png"))
                {
                    Chess_Info("load image from resource success: "+key);
                }
                else
                {
                    Chess_Error("load image from resource fail: "+key);
                }
            }
            if((pixmap.width() ==0) || (pixmap.height() == 0))
            {
                Chess_Error("paint chess fail: "+key);
                continue;
            }
            QRectF target(xLogToPhy(point.x())-halfFactor,
                          yLogToPhy(point.y())-halfFactor, factor, factor);
            QRectF source(0.0, 0.0, pixmap.width(), pixmap.height());
            painter.drawPixmap(target, pixmap, source);
        }
    }
}

void ChessBoardWidget::paintSelectedChess(QPainter &painter)
{
    QPoint p = ChessData::instance()->getSelectedChess();
    int x = p.x();
    int y = p.y();
    if((x<0)||(x>8)||(y<0)||(y>9)) return;
    QPointF point(xLogToPhy(x), yLogToPhy(y));
    painter.setPen(selectedPen);
    painter.drawEllipse(point, halfFactor, halfFactor);
}

void ChessBoardWidget::paintLastLines(QPainter &painter)
{
    QLine line = ChessData::instance()->getGoLine();
    int x1 = line.p1().x();
    int y1 = line.p1().y();
    int x2 = line.p2().x();
    int y2 = line.p2().y();
    if((x1<0)||(y1<0)||(x2<0)||(y2<0)) return;

    QLineF lineF(xLogToPhy(x1),yLogToPhy(y1),xLogToPhy(x2),yLogToPhy(y2));
    painter.setPen(linePen);
    painter.drawLine(lineF);
}

void ChessBoardWidget::paintSetupChoice(QPainter &painter)
{
    QList<QPoint> pl(ChessData::instance()->getChoicePoints());
    if(pl.isEmpty()) return;
    painter.setPen(choicePen);
    int size = pl.size();
    for(int i=0; i<size; ++i)
    {
        int x = pl.at(i).x();
        int y = pl.at(i).y();
        if((x<0)||(x>8)||(y>9)||(y<0)) continue;
        painter.drawEllipse(QPointF(xLogToPhy(x), yLogToPhy(y)),
                            halfFactor/2.0, halfFactor/2.0);
    }
}

void ChessBoardWidget::mousePressEvent(QMouseEvent *event)
{
    doMouseEvent(event, 2);
}

void ChessBoardWidget::mouseMoveEvent(QMouseEvent *event)
{
    doMouseEvent(event, 1);
}

void ChessBoardWidget::mouseReleaseEvent(QMouseEvent *event)
{
    doMouseEvent(event, 0);
}

void ChessBoardWidget::doMouseEvent(QMouseEvent *event, int type)
{
    if(ChessInformation::instance()->isReplay()) return;
    double px = event->posF().x();
    double py = event->posF().y();
    if((px<=halfFactor) || (px>=factor*10-halfFactor)
            || (py<=halfFactor) || (py>=factor*11-halfFactor))
    {
        setCursor(QCursor(Qt::ArrowCursor));
        return;
    }
    int x = xPhyToLog(px);
    int y = yPhyToLog(py);

    //qDebug()<< x <<y << px << py;

    if((x<0) || (x>8) || (y<0) || (y>9))
    {
        //not in board
        setCursor(QCursor(Qt::ArrowCursor));
    }
    else
    {
        //in board
        double tx = px - xLogToPhy(x);
        double ty = py - yLogToPhy(y);
        bool ok = (tx*tx+ty*ty) < (halfFactor*halfFactor);
        QPoint p(x, y);
        if(ok && (!(ChessData::instance()->isEmpty(p))))
        {
            //chess
            if(2 == type)
            {
                setCursor(QCursor(Qt::ClosedHandCursor));
                int id = ChessData::instance()->isWho(p);
                if((id>=0)&&(id<=31))
                {
                    ChessCore::instance()->selectChess(id, p);
                }
            }
            else
            {
                setCursor(QCursor(Qt::OpenHandCursor));
            }
        }
        else
        {
            //empty
            if(2 == type)
            {
                ChessCore::instance()->selectEmpty(p);
            }
            else
            {
                setCursor(QCursor(Qt::ArrowCursor));
            }
        }
    }
}
