#ifndef CHESSMANUALWIDGET_H
#define CHESSMANUALWIDGET_H

#include <QWidget>

class ChessManualWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessManualWidget)
public:
    static ChessManualWidget *instance();
    ~ChessManualWidget();

signals:

public slots:

private:
    static ChessManualWidget *INSTANCE;
    explicit ChessManualWidget(QWidget *parent = 0);
};

#endif // CHESSMANUALWIDGET_H
