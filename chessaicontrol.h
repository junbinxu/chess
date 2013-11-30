#ifndef CHESSAICONTROL_H
#define CHESSAICONTROL_H

#include "chessopposition.h"

class ChessAIControl : public ChessOpposition
{
    Q_OBJECT
public:
    explicit ChessAIControl(QObject *parent = 0);
    ~ChessAIControl();
    inline bool isValid() {return true;}
    void send(const QString &message);

signals:

public slots:

};

#endif // CHESSAICONTROL_H
