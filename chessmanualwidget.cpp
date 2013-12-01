#include "chessmanualwidget.h"
#include "chessmanual.h"
#include "chesslog.h"
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>

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
    titleLabel = new QLabel(tr("chess manual"));
    manualTextEdit = new QTextEdit;
    manualTextEdit->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(manualTextEdit);
    setLayout(layout);

    Chess_Trace(tr("new ChessManualWidget"));
}

ChessManualWidget::~ChessManualWidget()
{
    Chess_Trace(tr("delete ChessManualWidget"));
}
