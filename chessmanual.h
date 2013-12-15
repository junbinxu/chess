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
    ~ChessManual();
    void saveChessManual();

private:
    void makeDir(const QString &dirName);


    explicit ChessManual(QObject *parent = 0);
    static ChessManual *INSTANCE;

    QList<QString> manual;

    void writeSetup(int i);
};

#endif // CHESSMANUAL_H
