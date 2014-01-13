#ifndef CHESSVERSION_H
#define CHESSVERSION_H

#include <QObject>
#include <QNetworkReply>

class ChessVersion : public QObject
{
    Q_OBJECT
public:
    enum State{UnKnown, Updated, Old, Error};
    static ChessVersion * instance();
    ~ChessVersion();
    static QString buildTime();
    State state() const {return versionState;}
    inline QString newVersion() const {return newVersionStr;}
    inline QString downloadUrl() const {return newDownloadUrl;}

signals:
    void finished();

public slots:
    void checkForNew();

    void readData();
    void readError(QNetworkReply::NetworkError error);

private:
    static ChessVersion * INSTANCE;
    explicit ChessVersion(QObject *parent = 0);

    void processData(QByteArray data);

    State versionState;
    QString newVersionStr;
    QString newDownloadUrl;
};

#endif // CHESSVERSION_H
