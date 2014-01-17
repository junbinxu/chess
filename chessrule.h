#ifndef CHESSRULE_H
#define CHESSRULE_H

#include <QtGlobal>
#include <QList>
#include <QPoint>

class ChessRule
{
    Q_DISABLE_COPY(ChessRule)
public:
    static ChessRule *instance();
    ~ChessRule();

    QList<QPoint> getChoice(int id, const QPoint &p);


private:
    static ChessRule *INSTANCE;
    explicit ChessRule();

    bool isOK(int fid, const QPoint &go) const;

    QList<QPoint> red_shuai(int id, const QPoint &p);
    QList<QPoint> red_shi(int id, const QPoint &p);
    QList<QPoint> red_xiang(int id, const QPoint &p);
    QList<QPoint> red_ma(int id, const QPoint &p);
    QList<QPoint> red_ju(int id, const QPoint &p);
    QList<QPoint> red_pao(int id, const QPoint &p);
    QList<QPoint> red_bing(int id, const QPoint &p);

    QList<QPoint> black_jiang(int id, const QPoint &p);
    QList<QPoint> black_shi(int id, const QPoint &p);
    QList<QPoint> black_xiang(int id, const QPoint &p);
    QList<QPoint> black_ma(int id, const QPoint &p);
    QList<QPoint> black_ju(int id, const QPoint &p);
    QList<QPoint> black_pao(int id, const QPoint &p);
    QList<QPoint> black_zu(int id, const QPoint &p);

    QList<QPoint> _ma(int id, const QPoint &p);
    QList<QPoint> _ju(int id, const QPoint &p);
    QList<QPoint> _pao(int id, const QPoint &p);
    QList<QPoint> _xiang(int id, const QPoint &p, const int ARR[7][2]);
    QList<QPoint> _shi(int id, const QPoint &p, const int ARR[5][2]);
    QList<QPoint> _shuai_jiang(int id, const QPoint &p, const int ARR[9][2]);

    static const int DMA[8][2];
    static const int DXIANG_RED[7][2];
    static const int DXIANG_BLACK[7][2];
    static const int DSHI_RED[5][2];
    static const int DSHI_BLACK[5][2];
    static const int DSHUAI_RED[9][2];
    static const int DJIANG_BLACK[9][2];
};

#endif // CHESSRULE_H
