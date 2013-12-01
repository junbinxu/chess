#include "chessopposition.h"
#include "chesslog.h"
#include "chessdispatch.h"

ChessOpposition::ChessOpposition(QObject *parent) :
    QObject(parent)
{


    //Chess_Trace(tr("new ChessOpposition"));
}

ChessOpposition::~ChessOpposition()
{
    //Chess_Trace(tr("delete ChessOpposition"));
}

bool ChessOpposition::isValid()
{
    return false;
}

void ChessOpposition::receive(const QString &message)
{
    ChessDispatch::instance()->receive(message);
}
