#ifndef CHESSSOUND_H
#define CHESSSOUND_H

class ChessSound
{
public:
    static ChessSound *instance();
    ~ChessSound();

private:
    static ChessSound *INSTANCE;
    explicit ChessSound();
};

#endif // CHESSSOUND_H
