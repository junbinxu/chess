#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>
#include <QPainter>

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
    void makeImageCache();
    void paintBoard(QPainter &painter);
    void paintChesses(QPainter &painter);
    void paintSelectedChess(QPainter &painter);
    void paintLastLines(QPainter &painter);
    void paintSetupChoice(QPainter &painter);
    static ChessBoardWidget *INSTANCE;
    explicit ChessBoardWidget(QWidget *parent = 0);

    int fixWidth;
    int fixHeight;
};

#endif // CHESSBOARDWIDGET_H
