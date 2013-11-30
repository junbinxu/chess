#ifndef CHESSLOG_H
#define CHESSLOG_H

#include "chessdefine.h"
#include <QObject>
#include <QThread>
#include <QMutex>
#include <QMap>

void Chess_Log(LogLevel level, const QString &message);
void Chess_Trace(const QString &message);
void Chess_Debug(const QString &message);
void Chess_Info(const QString &message);
void Chess_Warning(const QString &message);
void Chess_Error(const QString &message);
void Chess_Fatal(const QString &message);


class ChessLog : public QThread
{
public:
    ~ChessLog();
    static ChessLog *instance();
    static QString levelToText(LogLevel level);
    inline LogLevel getLevel() const {return logLevel;}
    void conf(const QString &file, LogLevel level);
    void write(LogLevel level, const QString &message);
    void closeLogger();
    QMutex mutex;

private:
    static ChessLog *INSTANCE;
    explicit ChessLog();
    LogLevel logLevel;
    QString logFileName;
};

#endif // CHESSLOG_H
