#ifndef CHESSDATA_H
#define CHESSDATA_H

#include <QtGlobal>
#include <QPoint>
#include <QList>

class ChessData
{
    Q_DISABLE_COPY(ChessData)
public:
    static ChessData *instance();
    ~ChessData();
    void init();
    inline QPoint getPos(int id) const
    {
        return ((id>=0)&&(id<=31)) ? data.at(id) : QPoint(-100, -100);
    }
    inline int isWho(const QPoint &p) const
    {
        return data.indexOf(p);
    }
    inline bool isEmpty(const QPoint &p) const
    {
        return (data.indexOf(p) < 0);
    }
    inline bool isLive(int id) const
    {
        return (getPos(id).x() >= 0);
    }
    inline bool isLive(int id, QPoint *p) const
    {
        return ((*p = getPos(id)).x() >= 0);
    }
    bool isMine(int id) const;


    void moveChess(int fid, QPoint to);
    void eatChess(int fid, int tid, QPoint to);

    void selectChess(QPoint p);
    inline QPoint getSelectedChess() const {return selectedChessPos;}

private:
    static ChessData *INSTANCE;
    explicit ChessData();

    void putChess(int id, QPoint p);
    void deleteChess(int id);

    QList<QPoint> data;

    QPoint selectedChessPos;

    static const int chessInitPos[32][2];
};

#endif // CHESSDATA_H
