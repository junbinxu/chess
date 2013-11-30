#ifndef CHESSCORE_H
#define CHESSCORE_H

#include <QObject>

class ChessCore : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessCore)
public:
    static ChessCore *instance();
    ~ChessCore();

signals:

public slots:

private:
    static ChessCore *INSTANCE;
    explicit ChessCore(QObject *parent = 0);
};

#endif // CHESSCORE_H
