#ifndef CHESSCENTERWIDGET_H
#define CHESSCENTERWIDGET_H

#include <QWidget>

class ChessManualWidget;
class ChessFunctionWidget;
class ChessBoardWidget;
class ChessTipsWidget;
class ChessChatWidget;

class ChessCenterWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessCenterWidget)
public:
    static ChessCenterWidget *instance();
    ~ChessCenterWidget();

signals:

public slots:

private:
    static ChessCenterWidget *INSTANCE;
    explicit ChessCenterWidget(QWidget *parent = 0);

    ChessManualWidget *chessManualWidget;
    ChessFunctionWidget *chessFunctionWidget;
    ChessBoardWidget *chessBoardWidget;
    ChessTipsWidget *chessTipsWidget;
    ChessChatWidget *chessChatWidget;
};

#endif // CHESSCENTERWIDGET_H
