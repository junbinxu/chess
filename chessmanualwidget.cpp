#include "chessmanualwidget.h"

ChessManualWidget * ChessManualWidget::INSTANCE = 0;

ChessManualWidget * ChessManualWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessManualWidget;
    }
    return INSTANCE;
}

ChessManualWidget::ChessManualWidget(QWidget *parent) :
    QWidget(parent)
{
}
