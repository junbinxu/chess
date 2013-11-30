#ifndef CHESSMANUAL_H
#define CHESSMANUAL_H

#include <QObject>
#include <QList>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class ChessManual : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessManual)
public:
    static ChessManual *instance();
    void saveChessManual();

private:
    explicit ChessManual();
    static ChessManual *INSTANCE;

    QList<QString> manual;

    void writeSetup(int i);
};

#endif // CHESSMANUAL_H
