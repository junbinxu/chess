#include "chessversion.h"
#include "chesslog.h"
#include "chessdefine.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QXmlStreamReader>
#include <QDebug>

ChessVersion * ChessVersion::INSTANCE = 0;
ChessVersion * ChessVersion::instance()
{
    if(!INSTANCE) INSTANCE = new ChessVersion;
    return INSTANCE;
}

ChessVersion::ChessVersion(QObject *parent) :
    QObject(parent)
{
    versionState = UnKnown;
    Chess_Trace("new ChessVersion");
}

ChessVersion::~ChessVersion()
{
    Chess_Trace("delete ChessVersion");
}

QString ChessVersion::buildTime()
{
    return QString("%1 %2").arg(__DATE__).arg(__TIME__);
}

void ChessVersion::checkForNew()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl("http://huiwx.github.io/chess.xml"));
    request.setRawHeader("User-Agent",
                         "Mozilla/5.0 (Windows NT 6.1; rv:26.0) Gecko/20100101 Firefox/26.0");
    QNetworkReply *replay = manager->get(request);
    connect(replay, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(replay, SIGNAL(error(QNetworkReply::NetworkError)), this,
            SLOT(readError(QNetworkReply::NetworkError)));
}

void ChessVersion::readError(QNetworkReply::NetworkError error)
{
    QNetworkReply *replay = qobject_cast<QNetworkReply *>(sender());
    if(!replay) return;

    if(error == QNetworkReply::NoError) return;
    else
    {
        Chess_Error("check for update error");
    }
    emit finished();
    replay->deleteLater();
}

void ChessVersion::readData()
{
    QNetworkReply *replay = qobject_cast<QNetworkReply *>(sender());
    if(!replay) return;

    QByteArray data = replay->readAll();
    replay->deleteLater();

    processData(data);
}

void ChessVersion::processData(QByteArray data)
{
    if(data.isEmpty()) return;
    quint32 version;
    QString version_str;
    QString url;
    QXmlStreamReader reader(data);
    while(!reader.atEnd())
    {
        reader.readNext();
        if(reader.isStartElement())
        {
            if(reader.name() == QLatin1String("chessversion"))
            {
                if(reader.attributes().value("version") == QLatin1String("1"))
                {
                    // version 1
                    while(!reader.atEnd())
                    {
                        reader.readNext();
                        if(reader.isStartElement())
                        {
                            if(reader.name() == QLatin1String("version"))
                            {
                                //version
                                version = reader.attributes().value("int").toString().toUInt();
                                version_str = reader.attributes().value("str").toString();
                            }
                            else if(reader.name() == QLatin1String("url"))
                            {
                                //download url
                                url = reader.attributes().value("href").toString();
                            }
                        }
                    }
                }
                else
                {
                    Chess_Error("not supported chessversion");
                }
            }
        }
    }
    if(reader.hasError())
    {
        Chess_Error(reader.errorString());
        versionState = Error;
    }
    else
    {
        if((version >= 0x10000) && (!version_str.isEmpty()) && (QUrl(url).isValid()))
        {
            if(version > CHESS_VERSION_INT)
            {
                Chess_Info(QString("update %1 %2 %3").arg(version).arg(version_str).arg(url));
                newVersionStr = version_str;
                newDownloadUrl = url;
                versionState = Old;
            }
            else
            {
                Chess_Info(version_str + " is new, no update");
                versionState = Updated;
            }
        }
        else
        {
            Chess_Error(QString("update %1 %2 %3").arg(version).arg(version_str).arg(url));
            versionState = Error;
        }
    }
    emit finished();
}
