#include "chessboardwidget.h"

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
}
