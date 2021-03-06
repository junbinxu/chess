#ifndef CHESSDISPATCH_H
#define CHESSDISPATCH_H

#include <QObject>
#include <QString>

class ChessOpposition;

class ChessDispatch : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessDispatch)
public:
    static ChessDispatch *instance();
    ~ChessDispatch();
    bool isValid();
    void send(const QString &message);
    void receive(const QString &message);

signals:

public slots:

private:
    static ChessDispatch *INSTANCE;
    explicit ChessDispatch(QObject *parent = 0);

    ChessOpposition *chessOpposition;
};

#endif // CHESSDISPATCH_H
