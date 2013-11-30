#include "chesschat.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateTime>

ChessChat * ChessChat::INSTANCE = 0;

ChessChat * ChessChat::instance()
{
    if(!INSTANCE)
    {
        INSTANCE = new ChessChat;
    }
    return INSTANCE;
}

const int ChessChat::maxLength = 20;

ChessChat::ChessChat(QWidget *parent) :
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
}

void ChessChat::sendMessage()
{
    QString message = inputLineEdit->text().trimmed();
    if(message.isEmpty()) return;
    emit send(message);
    inputLineEdit->clear();
}

void ChessChat::receiveMessage(const QString &msg)
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString currentTime = dateTime.toString(QLatin1String("yyyy-MM-dd HH:mm:ss"));

    QString message = currentTime + msg;
    showTextEdit->append(message);
}
