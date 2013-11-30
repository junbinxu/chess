#include "chesscenterwidget.h"
#include "chesschat.h"
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
    chessChat = ChessChat::instance();

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(chessChat);
    setLayout(rightLayout);
}
