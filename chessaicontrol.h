#ifndef CHESSAICONTROL_H
#define CHESSAICONTROL_H

#include "chessopposition.h"

class ChessEngine;

class ChessAIControl : public ChessOpposition
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessAIControl)
public:
    static ChessAIControl *instance();
    ~ChessAIControl();
    inline bool isValid() {return true;}
    void send(const QString &message);


signals:

public slots:

private:
    static ChessAIControl *INSTANCE;
    explicit ChessAIControl(QObject *parent = 0);

    ChessEngine *engine;
};

#endif // CHESSAICONTROL_H
