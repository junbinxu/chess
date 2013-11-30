#ifndef CHESSTIPSWIDGET_H
#define CHESSTIPSWIDGET_H

#include <QWidget>

class ChessTipsWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessTipsWidget)
public:
    static ChessTipsWidget *instance();
    ~ChessTipsWidget();

signals:

public slots:

private:
    static ChessTipsWidget *INSTANCE;
    explicit ChessTipsWidget(QWidget *parent = 0);
};

#endif // CHESSTIPSWIDGET_H
