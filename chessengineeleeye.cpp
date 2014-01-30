#include "chessengineeleeye.h"
#include "chesslog.h"
#include "chessprotocol.h"

ChessEngineEleeye * ChessEngineEleeye::INSTANCE = 0;
ChessEngineEleeye * ChessEngineEleeye::instance()
{
    if(!INSTANCE) INSTANCE = new ChessEngineEleeye;
    return INSTANCE;
}

ChessEngineEleeye::ChessEngineEleeye(QObject *parent) :
    ChessEngine(parent), isEngineInit(false)
{
    init();
    Chess_Trace("new ChessEngineEleeye");
}

ChessEngineEleeye::~ChessEngineEleeye()
{
    Chess_Trace("delete ChessEngineEleeye");
}

void ChessEngineEleeye::read(const QString &msg)
{
    QHash<QString, QString> hash = ChessProtocol::instance()->analyse(msg);
    qDebug() << hash;
    if(!hash.contains("TYPE"))
    {
        Chess_Error("has no message type: "+msg);
        return;
    }
    ChessProtocol *chessProtocol = ChessProtocol::instance();
    QString body = hash.value("BODY");
    QString type = hash.value("TYPE");
    if(type == "CHESS")
    {
        QString data = QString("position fen %1 %2 - - 0 %3\n")
                .arg(hash.value("ELEEYE"))
                .arg(hash.value("TURN"))
                .arg(hash.value("COUNT"));
        writeToEngine(data.toLocal8Bit().data());
        writeToEngine("go time 300000 increment 0\n");
    }
    else if(type == "START")
    {
        emit write(chessProtocol->makeMessage("START", "HELLO"));
    }
    else if(type == "EXIT")
    {
        writeToEngine("quit\n");
    }
    else if(type == "NEW")
    {
        writeToEngine("setoption newgame\n");
    }
}

void ChessEngineEleeye::init()
{
    process.start(QString("/usr/games/eleeye_engine"));

    connect(&process, SIGNAL(stateChanged(QProcess::ProcessState)),
            this, SLOT(processChangeState(QProcess::ProcessState)));
    connect(&process, SIGNAL(readyReadStandardOutput()), this, SLOT(readFromEngine()));
    connect(&process, SIGNAL(readyReadStandardError()), this, SLOT(readFromEngine()));
}

void ChessEngineEleeye::writeToEngine(const char *ic)
{
    Chess_Info(QString("write to eleeye engine:\n%1").arg(ic));
    process.write(ic);
}

void ChessEngineEleeye::readFromEngine()
{
    QString data = QString(process.readAllStandardOutput());
    Chess_Info(QString("eleeye engine output:\n%1").arg(data));
    if(!data.contains("bestmove", Qt::CaseInsensitive)) return;
    QStringList sl = data.split('\n', QString::SkipEmptyParts);
    int size = sl.size();
    for(int i=0; i<size; ++i)
    {
        QString tmp = sl.at(i).trimmed();
        if(tmp.startsWith("bestmove", Qt::CaseInsensitive))
        {
            QStringList ll = tmp.split(' ', QString::SkipEmptyParts);
            if(ll.size()>=2)
            {
                QString bestmove = ll.at(1);
                QString msg = ChessProtocol::instance()->makeMessage("CHESS",bestmove);
                emit write(msg);
            }
        }
    }
    //emit write(QString(data));
}

void ChessEngineEleeye::processChangeState(QProcess::ProcessState s)
{
    if(s == QProcess::Running)
    {
        if(!isEngineInit)
        {
            writeToEngine("ucci\n");
            isEngineInit = true;
        }
    }
}

