#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>

class ChessBoardWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessBoardWidget)
public:
    static ChessBoardWidget *instance();
    ~ChessBoardWidget();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:

private:
    static ChessBoardWidget *INSTANCE;
    explicit ChessBoardWidget(QWidget *parent = 0);
};

#endif // CHESSBOARDWIDGET_H
