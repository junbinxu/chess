#ifndef CHESSMANUALWIDGET_H
#define CHESSMANUALWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QTextEdit;
QT_END_NAMESPACE

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

private:
    QLabel *titleLabel;
    QTextEdit *manualTextEdit;
};

#endif // CHESSMANUALWIDGET_H
