#ifndef CHESSFUNCTIONWIDGET_H
#define CHESSFUNCTIONWIDGET_H

#include <QWidget>

class ChessFunctionWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessFunctionWidget)
public:
    static ChessFunctionWidget *instance();
    ~ChessFunctionWidget();

signals:

public slots:

private:
    static ChessFunctionWidget *INSTANCE;
    explicit ChessFunctionWidget(QWidget *parent = 0);
};

#endif // CHESSFUNCTIONWIDGET_H
