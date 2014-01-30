#include "chessdata.h"
#include "chesslog.h"
#include "chessinformation.h"
#include <QObject>

ChessData * ChessData::INSTANCE = 0;

ChessData * ChessData::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessData;
    }
    return INSTANCE;
}

const int ChessData::chessInitPos[32][2] =
{
    //x0-8 y0-9
    {4, 9}, {0, 9}, {8, 9}, {1, 9}, {7, 9}, {1, 7}, {7, 7}, {3, 9},
    {5, 9}, {2, 9}, {6, 9}, {0, 6}, {2, 6}, {4, 6}, {6, 6}, {8, 6},
    {4, 0}, {0, 0}, {8, 0}, {1, 0}, {7, 0}, {1, 2}, {7, 2}, {3, 0},
    {5, 0}, {2, 0}, {6, 0}, {0, 3}, {2, 3}, {4, 3}, {6, 3}, {8, 3}
};

const char ChessData::chessName[32] =
{
    'K', 'R', 'R', 'N', 'N', 'C', 'C', 'A', 'A', 'B', 'B', 'P', 'P', 'P', 'P', 'P',
    'k', 'r', 'r', 'n', 'n', 'c', 'c', 'a', 'a', 'b', 'b', 'p', 'p', 'p', 'p', 'p',
};

ChessData::ChessData()
{
    init();
    Chess_Trace(QObject::tr("new ChessData"));
}

ChessData::~ChessData()
{
    Chess_Trace(QObject::tr("delete ChessData"));
}

void ChessData::init()
{
    data.clear();
    for(int i=0; i<32; ++i)
    {
        data.append(QPoint(chessInitPos[i][0], chessInitPos[i][1]));
    }
    Q_ASSERT(data.size() == 32);

    selectedChessPos = QPoint(-100, -100);
    goLine = QLine(-100, -100, -100, -100);
    choicePoints.clear();

    //choicePoints << QPoint(0, 0) << QPoint(5, 5);
}

bool ChessData::isMine(int id) const
{
    if(ChessInformation::instance()->isRed())
    {
        return (id>=0) && (id<=15);
    }
    else
    {
        return (id>=16) && (id<=31);
    }
}

bool ChessData::isMine(const QPoint &p) const
{
    return isMine(isWho(p));
}

void ChessData::moveChess(int fid, QPoint to)
{
    if((fid>=0)&&(fid<=31))
    {
        goLine.setPoints(getPos(fid), to);
        deleteChess(fid);
        putChess(fid, to);
        clearSelectChess();
    }
}

void ChessData::eatChess(int fid, int tid, QPoint to)
{
    if((fid>=0)&&(fid<=31)&&(tid>=0)&&(tid<=31))
    {
        goLine.setPoints(getPos(fid), to);
        deleteChess(fid);
        deleteChess(tid);
        putChess(fid, to);
        clearSelectChess();
    }
}

int ChessData::chessNumberFromTo(const QPoint &f, const QPoint &t)
{
    int x1 = f.x();
    int y1 = f.y();
    int x2 = t.x();
    int y2 = t.y();
    if(x1 == x2)
    {
        int y_min = qMin(y1, y2)+1;
        int y_max = qMax(y1, y2)-1;
        int count = 0;
        for(int i=y_min; i<=y_max; ++i)
        {
            if(isNotEmpty(QPoint(x1, i))) ++count;
        }
        return count;
    }
    else if(y1 == y2)
    {
        int x_min = qMin(x1, x2)+1;
        int x_max = qMax(x1, x2)-1;
        int count = 0;
        for(int j=x_min; j<=x_max; ++j)
        {
            if(isNotEmpty(QPoint(j, y1))) ++count;
        }
        return count;
    }
    else return -1;
}

QString ChessData::boardMap() const
{
    QString board;

    for(int i=0; i<=9; ++i)
    {
        int t = 0;
        for(int j=0; j<=8; ++j)
        {
            int index = isWho(QPoint(j, i));
            if((index < 0) || (index > 31))
            {
                ++t;
                if((j == 8) && (t != 0))
                {
                    board.append(QString::number(t));
                }
            }
            else
            {
                if(0 == t)
                {
                    board.append(chessName[index]);
                }
                else
                {
                    board.append(QString::number(t));
                    board.append(chessName[index]);
                    t = 0;
                }
            }
        }
        if(i <= 8)
        {
            board.append('/');
        }
    }

    return board;
}
