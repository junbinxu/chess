#ifndef CHESSTIPSWIDGET_H
#define CHESSTIPSWIDGET_H

#include "chessdefine.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QTextEdit;
QT_END_NAMESPACE

class ChessTipsWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessTipsWidget)
public:
    static ChessTipsWidget *instance();
    ~ChessTipsWidget();
    void addTips(const QString &message, TipsLevel level = NormalLevel);

signals:

public slots:

private:
    static ChessTipsWidget *INSTANCE;
    explicit ChessTipsWidget(QWidget *parent = 0);

    QLabel *titleLabel;
    QTextEdit *tipsTextEdit;
};

#endif // CHESSTIPSWIDGET_H
