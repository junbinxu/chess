#include "chessmanual.h"
#include "chessinformation.h"
#include "chesslog.h"
#include <QXmlStreamWriter>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDateTime>
#include <QCoreApplication>
#include <QFileInfo>
#include <QDir>

ChessManual * ChessManual::INSTANCE = 0;

ChessManual * ChessManual::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessManual;
    }
    return INSTANCE;
}

ChessManual::ChessManual(QObject *parent) : QObject(parent)
{

    Chess_Trace(tr("new ChessManual"));
}

ChessManual::~ChessManual()
{
    Chess_Trace(tr("delete ChessManual"));
}

void ChessManual::makeDir(const QString &dirName)
{
    QFileInfo fi(dirName);
    QFile file(dirName);
    QDir dir;
    if(!(fi.exists() && fi.isDir()))
    {
        file.remove();
        dir.mkpath(dirName);
        Chess_Info(tr("make dir %1").arg(dirName));
    }
}

void ChessManual::saveChessManual()
{
    bool isRed = ChessInformation::instance()->isRed();
    QString myColor = isRed ? QLatin1String("red") : QLatin1String("black");
    QString currentTime = QDateTime::currentDateTime()
            .toString(QLatin1String("yyyyMMddHHmmsszzz"));
    qint64 pid = QCoreApplication::instance()->applicationPid();
    QString fileName = QString("chess_%1_%2_%3.xml")
            .arg(myColor)
            .arg(currentTime)
            .arg(pid);
    QString dirName = QCoreApplication::applicationDirPath() + "/manual/";
    makeDir(dirName);
    fileName.prepend(dirName);
    QFile file(fileName);
    if(file.exists())
    {
        Chess_Warning(tr("already save chess manual %1").arg(fileName));
        return;
    }
    if(!file.open(QIODevice::Text | QIODevice::WriteOnly))
    {
        Chess_Warning(tr("can not save chess manual %1").arg(fileName));
        return;
    }
    QXmlStreamWriter writer;
    writer.setCodec("UTF-8");
    writer.setAutoFormatting(true);
    int size = manual.size();
    QString result = QLatin1String("unknown");
    writer.setDevice(&file);
    writer.writeStartDocument();                        //doc begin

    writer.writeStartElement(QLatin1String("chess"));   //chess begin
    writer.writeAttribute(QLatin1String("version_str"),
                          QLatin1String(CHESS_MANUAL_FILE_VERSION_STR));
    writer.writeAttribute(QLatin1String("version_int"),
                          QString::number(CHESS_MANUAL_FILE_VERSION_INT));

    writer.writeStartElement(QLatin1String("outline")); //outline begin
    writer.writeAttribute(QLatin1String("count"), QString::number(size));
    writer.writeAttribute(QLatin1String("color"), myColor);
    writer.writeAttribute(QLatin1String("result"), result);
    writer.writeTextElement("start_manual", "aaaaaaaa");
    writer.writeEndElement();                           //outline end

    writer.writeStartElement(QLatin1String("detail"));
    for(int i=0; i<size; ++i)
    {
        writeSetup(i);
    }
    writer.writeEndElement();

    writer.writeEndElement();                           //chess end
    writer.writeEndDocument();                          //doc end
}

void ChessManual::writeSetup(int i)
{
    //writer.writeStartElement(QLatin1String("setup"));
    //writer.writeAttribute(QLatin1String("id"), QString::number(i));
    //writer.writeEndElement();
}
