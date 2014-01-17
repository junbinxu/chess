#ifndef CHESSCHATWIDGET_H
#define CHESSCHATWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QTextEdit;
class QLabel;
QT_END_NAMESPACE

class ChessChatWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChessChatWidget)
public:
    static ChessChatWidget *instance();
    ~ChessChatWidget();

protected:
    void keyPressEvent(QKeyEvent *e);

signals:

public slots:
    void sendMessage();
    void receiveMessage(const QString &msg);

private:
    void showMessage(bool isMe, const QString &msg);

    QString toUtf8(const QString &msg) const;
    QString fromUtf8(const QString &utf8) const;

    const static int maxLength;

    QLabel *titleLabel;
    QLineEdit *inputLineEdit;
    QTextEdit *showTextEdit;
    QPushButton *sendPushButton;

    static ChessChatWidget *INSTANCE;

    explicit ChessChatWidget(QWidget *parent = 0);
};

#endif // ChessChatWidget_H
