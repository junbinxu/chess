#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>

class ChessBoardWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessBoardWidget)
public:
    static ChessBoardWidget *instance();

signals:

public slots:

private:
    static ChessBoardWidget *INSTANCE;
    explicit ChessBoardWidget(QWidget *parent = 0);
};

#endif // CHESSBOARDWIDGET_H
