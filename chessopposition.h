#ifndef CHESSOPPOSITION_H
#define CHESSOPPOSITION_H

#include <QObject>

class ChessOpposition : public QObject
{
    Q_OBJECT
public:
    explicit ChessOpposition(QObject *parent = 0);
    virtual ~ChessOpposition();
    virtual bool isValid();
    virtual void send(const QString &) = 0;
    void receive(const QString &message);

signals:

public slots:

};

#endif // CHESSOPPOSITION_H
