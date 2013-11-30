#include "chessfunctionwidget.h"
#include "chesslog.h"

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

    Chess_Trace(tr("new ChessFunctionWidget"));
}

ChessFunctionWidget::~ChessFunctionWidget()
{
    Chess_Trace(tr("delete ChessFunctionWidget"));
}
