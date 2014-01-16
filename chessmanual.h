#ifndef CHESSMANUAL_H
#define CHESSMANUAL_H

#include <QObject>
#include <QList>
#include <QString>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

struct ManualNode
{
    int id;
    QString start;
    QString go;
    QString cgo;
    QString end;
};

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

    QList<ManualNode> manual;

    void writeSetup(int i);
};

#endif // CHESSMANUAL_H
