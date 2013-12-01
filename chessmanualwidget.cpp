#include "chessmanualwidget.h"
#include "chessmanual.h"
#include "chesslog.h"

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

    Chess_Trace(tr("new ChessManualWidget"));
}

ChessManualWidget::~ChessManualWidget()
{
    Chess_Trace(tr("delete ChessManualWidget"));
}
