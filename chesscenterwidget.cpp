#include "chesscenterwidget.h"
#include "chessmanualwidget.h"
#include "chessfunctionwidget.h"
#include "chessboardwidget.h"
#include "chesstipswidget.h"
#include "chesschatwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

ChessCenterWidget * ChessCenterWidget::INSTANCE = 0;
ChessCenterWidget * ChessCenterWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessCenterWidget;
    }
    return INSTANCE;
}

ChessCenterWidget::ChessCenterWidget(QWidget *parent) :
    QWidget(parent)
{
    chessManualWidget = ChessManualWidget::instance();
    chessFunctionWidget = ChessFunctionWidget::instance();
    chessBoardWidget = ChessBoardWidget::instance();
    chessTipsWidget = ChessTipsWidget::instance();
    chessChatWidget = ChessChatWidget::instance();

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addWidget(chessManualWidget);
    leftLayout->addWidget(chessFunctionWidget);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(chessTipsWidget);
    rightLayout->addWidget(chessChatWidget);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addWidget(chessBoardWidget);
    layout->addLayout(rightLayout);

    setLayout(layout);
}
