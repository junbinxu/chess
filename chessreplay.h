#ifndef CHESSREPLAY_H
#define CHESSREPLAY_H

#include "chessopposition.h"

class ChessReplay : public ChessOpposition
{
    Q_OBJECT
public:
    explicit ChessReplay(QObject *parent = 0);
    ~ChessReplay();
    inline bool isValid() {return true;}
    void send(const QString &message);

signals:

public slots:

};

#endif // CHESSREPLAY_H
