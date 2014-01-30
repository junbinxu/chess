#ifndef CHESSENGINEELEEYE_H
#define CHESSENGINEELEEYE_H

#include "chessengine.h"
#include <QProcess>

class ChessEngineEleeye : public ChessEngine
{
    Q_OBJECT
public:
    static ChessEngineEleeye * instance();
    ~ChessEngineEleeye();
    void read(const QString &msg);
    void init();

signals:

public slots:
    void readFromEngine();
    void processChangeState(QProcess::ProcessState s);

private:
    static  ChessEngineEleeye * INSTANCE;
    explicit ChessEngineEleeye(QObject *parent = 0);

    void writeToEngine(const char *ic);


    QProcess process;

    bool isEngineInit;
};

#endif // CHESSENGINEELEEYE_H
