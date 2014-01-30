#ifndef CHESSENGINE_H
#define CHESSENGINE_H

#include <QObject>
#include <QString>

class ChessEngine : public QObject
{
    Q_OBJECT
public:
    explicit ChessEngine(QObject *parent = 0);
    virtual ~ChessEngine();
    virtual void read(const QString &message) = 0;

signals:
    void write(const QString &message);
public slots:

private:


};

#endif // CHESSENGINE_H
