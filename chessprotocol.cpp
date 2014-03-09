#include "chessprotocol.h"
#include "chesslog.h"
#include "chessdata.h"
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

const QString ChessProtocol::KEY[6] =
{
    "TIME", "TYPE", "BODY", "ELEEYE", "TURN", "COUNT"
};

ChessProtocol::ChessProtocol(QObject *parent): QObject(parent)
{
    for(int i=0; i<6; ++i)
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

QHash<QString, QString> ChessProtocol::analyse(const QString &msg)
{
    QHash<QString, QString> hash;
    if(msg.isEmpty()) return hash;
    QStringList sl = msg.split(QChar('-'), QString::SkipEmptyParts);
    //qDebug() << sl;
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
    return hash;
}

void ChessProtocol::receiveMessage(const QString &msg)
{
    QHash<QString, QString> hash = analyse(msg);
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
        int fid = -1;
        int fx = -1;
        int fy = -1;
        int tid = -1;
        int tx = -1;
        int ty = -1;
        if(body.size() == 8)
        {
        fid = body.mid(0, 2).toInt();
        fx = body.mid(2, 1).toInt();
        fy = body.mid(3, 1).toInt();
        tid = body.mid(4, 2).toInt();
        tx = body.mid(6, 1).toInt();
        ty = body.mid(7, 1).toInt();

        }
        else if(body.size() == 4)
        {
            body = body.toLower();

//            fx = body.at(0).toAscii() - 'a';
//            fy = 9 - (body.at(1).toAscii() - '0');
//            fid = ChessData::instance()->isWho(QPoint(fx, fy));
//            tx = body.at(2).toAscii() - 'a';
//            ty = 9 - (body.at(3).toAscii() - '0');

            fx = body.at(0).toLatin1() - 'a';
            fy = 9 - (body.at(1).toLatin1() - '0');
            fid = ChessData::instance()->isWho(QPoint(fx, fy));
            tx = body.at(2).toLatin1() - 'a';
            ty = 9 - (body.at(3).toLatin1() - '0');

            tid = ChessData::instance()->isWho(QPoint(tx, ty));
        }
        emit receiveChessMessage(fid, tid, QPoint(fx, fy), QPoint(tx, ty));
    }
    else if(type == "START")
    {
        emit receiveStartMessage();
    }
    else
    {
        Chess_Error("unknown message type: "+type);
    }
}

void ChessProtocol::sendChessMessgae(int fid, int tid, const QPoint &from, const QPoint &to, const QString &boardMap, bool isBlackTurn, int count)
{
    QString msg = makeChessMessage(fid, tid, from, to);
    QString data = makeMessage(QLatin1String("CHESS"), msg);
    char turn = isBlackTurn ? 'b' : 'w';
    QString engine = QString(" -ELEEYE %1 -TURN %2 -COUNT %3").arg(boardMap).arg(turn).arg(count);
    data.append(engine);
    ChessDispatch::instance()->send(data);
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

void ChessProtocol::sendStartMessage()
{
    ChessDispatch::instance()->send(makeMessage("START", "HELLO"));
}

void ChessProtocol::sendExitMessage()
{
    ChessDispatch::instance()->send(makeMessage("EXIT", "BYE"));
}













