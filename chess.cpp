#include "chess.h"
#include "chesscenterwidget.h"

Chess::Chess(QWidget *parent) :
    QMainWindow(parent)
{

    setCentralWidget(ChessCenterWidget::instance());

}
