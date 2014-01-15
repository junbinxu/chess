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
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::red_shi(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::red_xiang(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
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
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::black_jiang(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::black_shi(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::black_xiang(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
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
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::_ma(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::_ju(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}

QList<QPoint> ChessRule::_pao(int id, const QPoint &p)
{
    Q_UNUSED(id);
    Q_UNUSED(p);
    QList<QPoint> pl;


    return pl;
}
