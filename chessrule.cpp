#include "chessrule.h"
#include "chessdefine.h"
#include "chesslog.h"
#include "chessdata.h"
#include <QObject>

ChessRule * ChessRule::INSTANCE = 0;

ChessRule * ChessRule::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessRule;
    }
    return INSTANCE;
}

const int ChessRule::DMA[8][2] =
{
    {-1, -2}, {-1, 2}, {1, -2}, {1, 2},
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
};

const int ChessRule::DXIANG_RED[7][2] =
{
    {2, 5}, {6, 5}, {0, 7}, {4, 7}, {8, 7}, {2, 9}, {6, 9}
};

const int ChessRule::DXIANG_BLACK[7][2] =
{
    {2, 0}, {6, 0}, {0, 2}, {4, 2}, {8, 2}, {2, 4}, {6, 4}
};

const int ChessRule::DSHI_RED[5][2] =
{
    {3, 7}, {3, 9}, {4, 8}, {5, 7}, {5, 9}
};

const int ChessRule::DSHI_BLACK[5][2] =
{
    {3, 0}, {3, 2}, {4, 1}, {5, 0}, {5, 2}
};

const int ChessRule::DSHUAI_RED[9][2] =
{
    {3, 7}, {3, 8}, {3, 9}, {4, 7}, {4, 8}, {4, 9}, {5, 7}, {5, 8}, {5, 9}
};

const int ChessRule::DJIANG_BLACK[9][2] =
{
    {3, 0}, {3, 1}, {3, 2}, {4, 0}, {4, 1}, {4, 2}, {5, 0}, {5, 1}, {5, 2}
};

ChessRule::ChessRule()
{

    Chess_Trace(QObject::tr("new ChessRule"));
}

ChessRule::~ChessRule()
{
    Chess_Trace(QObject::tr("delete ChessRule"));
}

QList<QPoint> ChessRule::getChoice(int id, const QPoint &p)
{
    QList<QPoint> pl;
    int x = p.x();
    int y = p.y();
    ChessData *d = ChessData::instance();
    if((id<0)||(id>31)||(!(d->isLive(id)))||(!(d->isMine(id)))
            ||(x<0)||(x>8)||(y<0)||(y>9))
    {
        Chess_Error(QString("error select: id=%1 at (%2, %3)").arg(id).arg(x).arg(y));
        return pl;
    }

    switch (id)
    {
    case(RED_SHUAI): return red_shuai(id, p);
    case(RED_SHI1):
    case(RED_SHI2): return red_shi(id, p);
    case(RED_XIANG1):
    case(RED_XIANG2): return red_xiang(id, p);
    case(RED_MA1):
    case(RED_MA2): return red_ma(id, p);
    case(RED_JU1):
    case(RED_JU2): return red_ju(id, p);
    case(RED_PAO1):
    case(RED_PAO2): return red_pao(id, p);
    case(RED_BING1):
    case(RED_BING2):
    case(RED_BING3):
    case(RED_BING4):
    case(RED_BING5): return red_bing(id, p);
    case(BLACK_JIANG): return black_jiang(id, p);
    case(BLACK_SHI1):
    case(BLACK_SHI2):return black_shi(id, p);
    case(BLACK_XIANG1):
    case(BLACK_XIANG2): return black_xiang(id, p);
    case(BLACK_MA1):
    case(BLACK_MA2): return black_ma(id, p);
    case(BLACK_JU1):
    case(BLACK_JU2): return black_ju(id, p);
    case(BLACK_PAO1):
    case(BLACK_PAO2): return black_pao(id, p);
    case(BLACK_ZU1):
    case(BLACK_ZU2):
    case(BLACK_ZU3):
    case(BLACK_ZU4):
    case(BLACK_ZU5): return black_zu(id, p);
    default: return pl;
    }
}

QList<QPoint> ChessRule::red_shuai(int id, const QPoint &p)
{
    return _shuai_jiang(id, p, DSHUAI_RED);
}

QList<QPoint> ChessRule::red_shi(int id, const QPoint &p)
{
    return _shi(id, p, DSHI_RED);
}

QList<QPoint> ChessRule::red_xiang(int id, const QPoint &p)
{
    return _xiang(id, p, DXIANG_RED);
}

QList<QPoint> ChessRule::red_ma(int id, const QPoint &p)
{
    return _ma(id, p);
}

QList<QPoint> ChessRule::red_ju(int id, const QPoint &p)
{
    return _ju(id, p);
}

QList<QPoint> ChessRule::red_pao(int id, const QPoint &p)
{
    return _pao(id, p);
}

QList<QPoint> ChessRule::red_bing(int id, const QPoint &p)
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();
    int x = p.x();
    int y = p.y();
    QPoint toLeft(x-1, y);
    QPoint toRight(x+1, y);
    QPoint toHead(x, y-1);

    if((y>=1)&&(!(d->isMine(toHead))))
    {
        pl.append(toHead);
    }
    if((y<=4)&&(x>=1)&&(!(d->isMine(toLeft))))
    {
        pl.append(toLeft);
    }
    if((y<=4)&&(x<=7)&&(!(d->isMine(toRight))))
    {
        pl.append(toRight);
    }
    return pl;
}

QList<QPoint> ChessRule::black_jiang(int id, const QPoint &p)
{
    return _shuai_jiang(id, p, DJIANG_BLACK);
}

QList<QPoint> ChessRule::black_shi(int id, const QPoint &p)
{
    return _shi(id, p, DSHI_BLACK);
}

QList<QPoint> ChessRule::black_xiang(int id, const QPoint &p)
{
    return _xiang(id, p, DXIANG_BLACK);
}

QList<QPoint> ChessRule::black_ma(int id, const QPoint &p)
{
    return _ma(id, p);
}

QList<QPoint> ChessRule::black_ju(int id, const QPoint &p)
{
    return _ju(id, p);
}

QList<QPoint> ChessRule::black_pao(int id, const QPoint &p)
{
    return _pao(id, p);
}

QList<QPoint> ChessRule::black_zu(int id, const QPoint &p)
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();
    int x = p.x();
    int y = p.y();
    QPoint toLeft(x-1, y);
    QPoint toRight(x+1, y);
    QPoint toHead(x, y+1);

    if((y<=8)&&(!(d->isMine(toHead))))
    {
        pl.append(toHead);
    }
    if((y>=5)&&(x>=1)&&(!(d->isMine(toLeft))))
    {
        pl.append(toLeft);
    }
    if((y>=5)&&(x<=7)&&(!(d->isMine(toRight))))
    {
        pl.append(toRight);
    }
    return pl;
}

QList<QPoint> ChessRule::_shuai_jiang(int id, const QPoint &p, const int ARR[9][2])
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();
    int x = p.x();
    int y = p.y();
    for(int i=0; i<9; ++i)
    {
        int tx = ARR[i][0];
        int ty = ARR[i][1];
        QPoint point(tx, ty);
        if(qAbs(x-tx) + qAbs(y-ty) == 1)
        {
            if(!(d->isMine(point))) pl.append(point);
        }
    }
    return pl;
}

QList<QPoint> ChessRule::_xiang(int id, const QPoint &p, const int ARR[7][2])
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();
    int x = p.x();
    int y = p.y();
    for(int i=0; i<7; ++i)
    {
        int tx = ARR[i][0];
        int ty = ARR[i][1];
        QPoint point(tx, ty);
        if((x != tx) && (y != ty) && (qAbs(x-tx) + qAbs(y-ty) == 4))
        {
            QPoint tmp((x+tx)/2, (y+ty)/2);
            if((!d->isMine(point)) && (d->isEmpty(tmp))) pl.append(point);
        }
    }
    return pl;
}

QList<QPoint> ChessRule::_shi(int id, const QPoint &p, const int ARR[5][2])
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();
    int x = p.x();
    int y = p.y();
    for(int i=0; i<5; ++i)
    {
        int tx = ARR[i][0];
        int ty = ARR[i][1];
        QPoint point(tx, ty);
        if((x != tx) && (y != ty) && (qAbs(x-tx) + qAbs(y-ty) == 2))
        {
            if(!(d->isMine(point))) pl.append(point);
        }
    }
    return pl;
}

QList<QPoint> ChessRule::_ma(int id, const QPoint &p)
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();
    int x = p.x();
    int y = p.y();

    for(int i=0; i<8; ++i)
    {
        int dx = DMA[i][0];
        int dy = DMA[i][1];
        int tx = x + dx;
        int ty = y + dy;
        if((tx<0)||(tx>8)||(ty<0)||(ty>9)) continue;
        QPoint point(tx, ty);
        if(d->isMine(point)) continue;
        QPoint tmp;
        if(1 == qAbs(dx))
        {
            tmp.setX(x);
            if(2 == dy) tmp.setY(y+1);
            else tmp.setY(y-1);
        }
        else
        {
            tmp.setY(y);
            if(2 == dx) tmp.setX(x+1);
            else tmp.setX(x-1);
        }
        if(d->isEmpty(tmp))
        {
            pl.append(point);
        }
    }
    return pl;
}

QList<QPoint> ChessRule::_ju(int id, const QPoint &p)
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();

    int x = p.x();
    int y = p.y();
    for(int i=0; i<=8; ++i)
    {
        if(i == x) continue;
        QPoint point(i, y);
        if(d->isMine(point)) continue;
        int count = d->chessNumberFromTo(point, p);
        if(0 == count)
        {
            pl.append(point);
        }
    }
    for(int j=0; j<=9; ++j)
    {
        if(j == y) continue;
        QPoint point(x, j);
        if(d->isMine(point)) continue;
        int count = d->chessNumberFromTo(point, p);
        if(0 == count)
        {
            pl.append(point);
        }
    }
    return pl;
}

QList<QPoint> ChessRule::_pao(int id, const QPoint &p)
{
    Q_UNUSED(id);
    QList<QPoint> pl;
    ChessData *d = ChessData::instance();

    int x = p.x();
    int y = p.y();
    for(int i=0; i<=8; ++i)
    {
        if(i == x) continue;
        QPoint point(i, y);
        if(d->isMine(point)) continue;
        int count = d->chessNumberFromTo(point, p);
        if(0 == count)
        {
            if(d->isEmpty(point))
            {
                pl.append(point);
            }
        }
        else if(1 == count)
        {
            if(d->isNotEmpty(point))
            {
                pl.append(point);
            }
        }
    }
    for(int j=0; j<=9; ++j)
    {
        if(j == y) continue;
        QPoint point(x, j);
        if(d->isMine(point)) continue;
        int count = d->chessNumberFromTo(point, p);
        if(0 == count)
        {
            if(d->isEmpty(point))
            {
                pl.append(point);
            }
        }
        else if(1 == count)
        {
            if(d->isNotEmpty(point))
            {
                pl.append(point);
            }
        }
    }
    return pl;
}
