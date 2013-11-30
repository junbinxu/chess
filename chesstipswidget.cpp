#include "chesstipswidget.h"

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
}
