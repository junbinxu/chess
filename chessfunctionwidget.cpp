#include "chessfunctionwidget.h"

ChessFunctionWidget *ChessFunctionWidget::INSTANCE = 0;

ChessFunctionWidget * ChessFunctionWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessFunctionWidget;
    }
    return INSTANCE;
}

ChessFunctionWidget::ChessFunctionWidget(QWidget *parent) :
    QWidget(parent)
{
}
