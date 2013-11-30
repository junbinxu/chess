#include "chesstipswidget.h"
#include "chesslog.h"

ChessTipsWidget * ChessTipsWidget::INSTANCE = 0;
ChessTipsWidget * ChessTipsWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessTipsWidget;
    }
    return INSTANCE;
}

ChessTipsWidget::ChessTipsWidget(QWidget *parent) :
    QWidget(parent)
{

    Chess_Trace(tr("new ChessTipsWidget"));
}

ChessTipsWidget::~ChessTipsWidget()
{
    Chess_Trace(tr("delete ChessTipsWidget"));
}
