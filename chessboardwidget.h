#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>

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
    void big();
    void small();

private:
    void makeImageCache();
    void makePens();
    void paintBoard(QPainter &painter);
    void paintChesses(QPainter &painter);
    void paintSelectedChess(QPainter &painter);
    void paintLastLines(QPainter &painter);
    void paintSetupChoice(QPainter &painter);
    static ChessBoardWidget *INSTANCE;
    explicit ChessBoardWidget(QWidget *parent = 0);
    void doMouseEvent(QMouseEvent *event, int type);

    QPen selectedPen;

    bool isBlack() const;

    double xLogToPhy(int x) const;
    double yLogToPhy(int y) const;
    int xPhyToLog(double x) const;
    int yPhyToLog(double y) const;

    double factor;
    double halfFactor;
};

#endif // CHESSBOARDWIDGET_H
