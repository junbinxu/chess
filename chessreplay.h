#ifndef CHESSREPLAY_H
#define CHESSREPLAY_H

#include "chessopposition.h"

class ChessReplay : public ChessOpposition
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessReplay)
public:
    static ChessReplay *instance();
    ~ChessReplay();
    inline bool isValid() {return true;}
    void send(const QString &message);

signals:

public slots:

private:
    static ChessReplay *INSTANCE;
    explicit ChessReplay(QObject *parent = 0);
};

#endif // CHESSREPLAY_H
