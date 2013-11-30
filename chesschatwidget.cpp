#include "chesschatwidget.h"
#include "chesslog.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateTime>

ChessChatWidget * ChessChatWidget::INSTANCE = 0;

ChessChatWidget * ChessChatWidget::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessChatWidget;
    }
    return INSTANCE;
}

const int ChessChatWidget::maxLength = 20;

ChessChatWidget::ChessChatWidget(QWidget *parent) :
    QWidget(parent)
{
    inputLineEdit = new QLineEdit;
    inputLineEdit->setMaxLength(maxLength);
    showTextEdit = new QTextEdit;
    showTextEdit->setReadOnly(true);
    sendPushButton = new QPushButton(tr("send"));

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(inputLineEdit);
    lay1->addWidget(sendPushButton);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(showTextEdit);
    layout->addLayout(lay1);
    setLayout(layout);

    connect(sendPushButton, SIGNAL(clicked()), this, SLOT(sendMessage()));

    Chess_Trace(tr("new ChessChatWidget"));
}

ChessChatWidget::~ChessChatWidget()
{
    Chess_Trace(tr("delete ChessChatWidget"));
}

void ChessChatWidget::sendMessage()
{
    QString message = inputLineEdit->text().trimmed();
    if(message.isEmpty()) return;
    emit send(message);
    inputLineEdit->clear();
    showMessage(true, message);
}

void ChessChatWidget::receiveMessage(const QString &msg)
{
    showMessage(false, msg);
}

void ChessChatWidget::showMessage(bool isMe, const QString &msg)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString currentTime = dateTime.toString(QLatin1String("yyyy-MM-dd HH:mm:ss"));
    QString speaker = isMe ? tr("myself") : tr("other");
    QString message = QString("%1 [%2]\n%3").arg(currentTime).arg(speaker).arg(msg);
    showTextEdit->append(message);
}
