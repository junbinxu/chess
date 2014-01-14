#ifndef CHESSLOG_H
#define CHESSLOG_H

#include <QString>
#include <QDebug>

void Chess_Trace(const QString &message);
void Chess_Debug(const QString &message);
void Chess_Info(const QString &message);
void Chess_Warning(const QString &message);
void Chess_Error(const QString &message);
void Chess_Fatal(const QString &message);

#endif // CHESSLOG_H
