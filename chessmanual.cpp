#include "chessmanual.h"
#include "chessinformation.h"
#include <QXmlStreamWriter>
#include <QXmlStreamWriter>
#include <QFile>
#include <QCoreApplication>

ChessManual * ChessManual::INSTANCE = 0;

ChessManual * ChessManual::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessManual;
    }
    return INSTANCE;
}

ChessManual::ChessManual()
{

}

void ChessManual::saveChessManual()
{
    QXmlStreamWriter writer;
    writer.setCodec("UTF-8");
    writer.setAutoFormatting(true);

    bool isRed = ChessInformation::instance()->isRed();
    QString myColor = isRed ? QLatin1String("red") : QLatin1String("black");
    QString result = QLatin1String("unknown");

    QString fileName = QCoreApplication::applicationDirPath() + "/manual/test.xml";
    QFile file(fileName);
    if(!file.open(QIODevice::Text | QIODevice::WriteOnly))
    {
        qDebug() << "can not open the file to save manual";
        return;
    }
    int size = manual.size();
    writer.setDevice(&file);
    qDebug() << writer.hasError();
    writer.writeStartDocument();                        //doc begin
    qDebug() << writer.hasError();

    writer.writeStartElement(QLatin1String("chess"));   //chess begin
    writer.writeAttribute(QLatin1String("version_str"),
                          QLatin1String(CHESS_MANUAL_FILE_VERSION_STR));
    writer.writeAttribute(QLatin1String("version_int"),
                          QString::number(CHESS_MANUAL_FILE_VERSION_INT));

    writer.writeStartElement(QLatin1String("outline")); //outline begin
    writer.writeAttribute(QLatin1String("count"), QString::number(size));
    writer.writeAttribute(QLatin1String("color"), myColor);
    writer.writeAttribute(QLatin1String("result"), result);
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
