#ifndef CHESSPROTOCOL_H
#define CHESSPROTOCOL_H

#include <QString>
#include <QObject>
#include <QSet>
#include <QPoint>

class ChessProtocol: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessProtocol)
public:
    static ChessProtocol *instance();
    ~ChessProtocol();
    void sendChatMessage(const QString &msg);
    void sendChessMessgae(int fid, int tid, const QPoint &from,
                          const QPoint &to, const QString &boardMap,
                          bool isBlackTurn, int count);
    void receiveMessage(const QString &msg);
    void sendStartMessage();
    void sendExitMessage();
    QString makeMessage(const QString &type, const QString &msg) const;
    QHash<QString, QString> analyse(const QString &msg);

signals:
    void receiveChatMessage(const QString &msg);
    void receiveChessMessage(int fid, int tid, const QPoint &from, const QPoint &to);
    void receiveStartMessage();

private:
    static ChessProtocol *INSTANCE;
    explicit ChessProtocol(QObject *parent=0);



    QString makeChessMessage(int fid, int tid, const QPoint &from, const QPoint &to) const;

    QString chessTime() const;
    QString chessType(const QString &type) const;
    QString chessMessage(const QString &msg) const;

    static const QString KEY[6];

    QSet<QString> keySet;
};

#endif // CHESSPROTOCOL_H
