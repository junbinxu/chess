#include "chesslog.h"
#include <cstdio>
#include <QMutexLocker>
#include <QDateTime>

void Chess_Trace(const QString &message)
{
    Chess_Log(TraceLevel, message);
}

void Chess_Debug(const QString &message)
{
    Chess_Log( DebugLevel, message);
}

void Chess_Info(const QString &message)
{
    Chess_Log(InfoLevel, message);
}

void Chess_Warning(const QString &message)
{
    Chess_Log(WarnLevel, message);
}

void Chess_Error(const QString &message)
{
    Chess_Log(ErrorLevel, message);
}

void Chess_Fatal(const QString &message)
{
    Chess_Log(FatalLevel, message);
}

void Chess_Log(LogLevel level, const QString &message)
{
    ChessLog *manager = ChessLog::instance();
    if(level < manager->getLevel()) return;
    QMutexLocker(&manager->mutex);
    manager->write(level, message);
}

ChessLog * ChessLog::INSTANCE = 0;

ChessLog::ChessLog() : QThread(), mutex(QMutex::Recursive)
{
    start();
}

ChessLog * ChessLog::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessLog;
    }
    return INSTANCE;
}

void ChessLog::conf(const QString &file, LogLevel level)
{
    logFileName = file;
    logLevel = level;

}

QString ChessLog::levelToText(LogLevel level)
{
    switch (level)
    {
    case TraceLevel: return "Trace";
    case DebugLevel: return "Debug";
    case InfoLevel: return "Info";
    case WarnLevel: return "Warning";
    case ErrorLevel: return "Error";
    case FatalLevel: return "Fatal";
    default: return QString();
    }
}

ChessLog::~ChessLog()
{
    exit(0);
}

void ChessLog::write(LogLevel level, const QString &message)
{
    QByteArray currentTime = QDateTime::currentDateTime()
            .toString("yyyy-MM-dd HH:mm:ss.zzz").toLatin1();
    QByteArray levelChar = levelToText(level).toLocal8Bit();
    QByteArray msg = message.toLocal8Bit();
    std::fprintf(stderr, "%s [%s] %s\n", currentTime.data(), levelChar.data(), msg.data());
}





