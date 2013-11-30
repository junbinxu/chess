#ifndef CHESSDISPATCH_H
#define CHESSDISPATCH_H

#include <QObject>

class ChessDispatch : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessDispatch)
public:
    explicit ChessDispatch(QObject *parent = 0);

signals:

public slots:

};

#endif // CHESSDISPATCH_H
