#include "chessboardwidget.h"
#include "chesslog.h"

ChessBoardWidget * ChessBoardWidget::INSTANCE = 0;

ChessBoardWidget * ChessBoardWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessBoardWidget;
    }
    return INSTANCE;
}

ChessBoardWidget::ChessBoardWidget(QWidget *parent) :
    QWidget(parent)
{

    Chess_Trace(tr("new ChessBoardWidget"));
}

ChessBoardWidget::~ChessBoardWidget()
{
    Chess_Trace(tr("delete ChessBoardWidget"));
}
