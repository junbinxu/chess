#ifndef CHESSDATA_H
#define CHESSDATA_H

#include <QtGlobal>
#include <QPoint>
#include <QList>
#include <QLine>

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
    bool isMine(const QPoint &p) const;


    void moveChess(int fid, QPoint to);
    void eatChess(int fid, int tid, QPoint to);
    inline bool isNotEmpty(const QPoint &p) const {return data.contains(p);}
    inline void setSelectedChess(const QPoint &p) {selectedChessPos = p;}
    inline QPoint getSelectedChess() const {return selectedChessPos;}
    inline QLine getGoLine() const {return goLine;}

    inline void clearSelectChess()
    {
        selectedChessPos = QPoint(-100, -100);
        choicePoints.clear();
    }

    inline QList<QPoint> getChoicePoints() const {return choicePoints;}
    inline void setChoicePoints(const QList<QPoint> &pl) {choicePoints = pl;}
    inline bool isOK(const QPoint &p) const {return choicePoints.contains(p);}

    int chessNumberFromTo(const QPoint &f, const QPoint &t);

    QString boardMap() const;

private:
    static ChessData *INSTANCE;
    explicit ChessData();

    inline void putChess(int id, QPoint p) {data[id] = p;}
    inline void deleteChess(int id) {data[id] = QPoint(-100, -100);}



    QList<QPoint> data;

    QPoint selectedChessPos;
    QLine goLine;
    QList<QPoint> choicePoints;

    static const int chessInitPos[32][2];

    static const char chessName[32];
};

#endif // CHESSDATA_H
