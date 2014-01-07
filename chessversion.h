#ifndef CHESSVERSION_H
#define CHESSVERSION_H

#include <QObject>
#include <QNetworkReply>

class ChessVersion : public QObject
{
    Q_OBJECT
public:
    static ChessVersion * instance();
    ~ChessVersion();
    QString buildTime() const;

signals:

public slots:
    void checkForNew();

    void readData();
    void readError(QNetworkReply::NetworkError error);

private:
    static ChessVersion * INSTANCE;
    explicit ChessVersion(QObject *parent = 0);

    void processData(QByteArray data);
};

#endif // CHESSVERSION_H
