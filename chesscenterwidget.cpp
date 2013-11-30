#include "chesscenterwidget.h"
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
    chessChatWidget = ChessChatWidget::instance();

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(chessChatWidget);
    setLayout(rightLayout);
}
