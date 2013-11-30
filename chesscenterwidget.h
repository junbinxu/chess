#ifndef CHESSCENTERWIDGET_H
#define CHESSCENTERWIDGET_H

#include <QWidget>

class ChessChatWidget;

class ChessCenterWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessCenterWidget)
public:
    static ChessCenterWidget *instance();

signals:

public slots:

private:
    static ChessCenterWidget *INSTANCE;
    explicit ChessCenterWidget(QWidget *parent = 0);

    ChessChatWidget *chessChatWidget;
};

#endif // CHESSCENTERWIDGET_H
