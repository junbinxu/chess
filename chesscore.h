#ifndef CHESSCORE_H
#define CHESSCORE_H

#include <QObject>
#include <QPoint>
#include <QList>

class ChessCore : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessCore)
public:
    static ChessCore *instance();
    ~ChessCore();
    void init();

    void selectEmpty(const QPoint &to);
    void selectChess(int id, const QPoint &p);


signals:

public slots:
    void receiveChessMessage(int fid, int tid, const QPoint &from, const QPoint &to);

private:
    static ChessCore *INSTANCE;
    explicit ChessCore(QObject *parent = 0);

    void _moveChess(int fid, const QPoint &to);
    void _eatChess(int fid, int tid, const QPoint &to);
    void _selectMyChess(int id, const QPoint &p);

    bool isOK(const QPoint &p);

    bool lastSelected;
    bool thisTurn;
    bool thisReady;
    bool thatReady;

};

#endif // CHESSCORE_H
