#include "chessprotocol.h"
#include "chesslog.h"
#include "chessdispatch.h"
#include <QObject>
#include <QDateTime>
#include <QStringList>
#include <QHash>

ChessProtocol * ChessProtocol::INSTANCE = 0;

ChessProtocol * ChessProtocol::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessProtocol;
    }
    return INSTANCE;
}

const QString ChessProtocol::KEY[3] =
{
    "TIME", "TYPE", "BODY"
};

ChessProtocol::ChessProtocol(QObject *parent): QObject(parent)
{
    for(int i=0; i<3; ++i)
    {
        keySet.insert(KEY[i]);
    }
    Chess_Trace(QObject::tr("new ChessProtocol"));
}

ChessProtocol::~ChessProtocol()
{
    Chess_Trace(QObject::tr("delete ChessProtocol"));
}

void ChessProtocol::sendChatMessage(const QString &msg)
{
    ChessDispatch::instance()->send(makeMessage(QLatin1String("CHAT"), msg));
}

QString ChessProtocol::makeMessage(const QString &type, const QString &msg) const
{
    return QString("%1 %2 %3")
            .arg(chessTime())
            .arg(chessType(type))
            .arg(chessMessage(msg));
}

QString ChessProtocol::chessTime() const
{
    return ("-TIME " +
            QDateTime::currentDateTimeUtc().toString("yyyyMMddhhmmss"));
}

QString ChessProtocol::chessType(const QString &type) const
{
    return ("-TYPE " + type);
}

QString ChessProtocol::chessMessage(const QString &msg) const
{
    return ("-BODY " + msg);
}

void ChessProtocol::receiveMessage(const QString &msg)
{
    if(msg.isEmpty()) return;
    QStringList sl = msg.split(QChar('-'), QString::SkipEmptyParts);
    QHash<QString, QString> hash;
    int size = sl.size();
    for(int i=0; i<size; ++i)
    {
        QStringList temp = sl.at(i).split(QChar(' '), QString::SkipEmptyParts);
        if(!temp.isEmpty())
        {
            QString key = temp.at(0).trimmed();
            if(keySet.contains(key))
            {
                temp.removeAt(0);
                QString value = temp.join(QChar(' ')).trimmed();
                hash.insert(key, value);
            }
        }
    }
    qDebug() << hash;
    if(!hash.contains("TYPE"))
    {
        Chess_Error("has no message type: "+msg);
        return;
    }
    QString type = hash.value("TYPE");
    QString body = hash.value("BODY");
    if(type == "CHAT")
    {
        emit receiveChatMessage(body);
    }
    else if(type == "CHESS")
    {
        int fid = body.mid(0, 2).toInt();
        int fx = body.mid(2, 1).toInt();
        int fy = body.mid(3, 1).toInt();
        int tid = body.mid(4, 2).toInt();
        int tx = body.mid(6, 1).toInt();
        int ty = body.mid(7, 1).toInt();
        emit receiveChessMessage(fid, tid, QPoint(fx, fy), QPoint(tx, ty));
    }
    else
    {
        Chess_Error("unknown message type: "+type);
    }
}

void ChessProtocol::sendChessMessgae(int fid, int tid, const QPoint &from, const QPoint &to)
{
    QString msg = makeChessMessage(fid, tid, from, to);
    ChessDispatch::instance()->send(makeMessage(QLatin1String("CHESS"), msg));
}

QString ChessProtocol::makeChessMessage(int fid, int tid, const QPoint &from, const QPoint &to) const
{
    QString sfid = QString::number(fid);
    if(sfid.size() == 1) sfid.prepend('0');
    QString stid = QString::number(tid);
    if(stid.size() == 1) stid.prepend('0');

    return QString("%1%2%3%4%5%6")
            .arg(sfid)
            .arg(from.x())
            .arg(from.y())
            .arg(stid)
            .arg(to.x())
            .arg(to.y());
}
