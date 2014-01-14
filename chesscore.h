#ifndef CHESSCORE_H
#define CHESSCORE_H

#include <QObject>
#include <QPoint>

class ChessCore : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessCore)
public:
    static ChessCore *instance();
    ~ChessCore();

    void selectEmpty();
    void selectChess(int id, const QPoint &p);

    inline bool isMyTurn() const {return myTurn;}

signals:

public slots:

private:
    static ChessCore *INSTANCE;
    explicit ChessCore(QObject *parent = 0);

    bool myTurn;

};

#endif // CHESSCORE_H
