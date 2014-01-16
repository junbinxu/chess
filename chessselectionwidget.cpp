#include "chessselectionwidget.h"
#include "chessdefine.h"
#include "chessinformation.h"
#include "chesslog.h"
#include "chess.h"
#include <QStringList>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QLatin1String>
#include <QLineEdit>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRegExp>
#include <QRegExpValidator>

ChessSelectionWidget::ChessSelectionWidget(QWidget *parent) :
    QWidget(parent)
{
    //创建三个选项：服务器、客户端、复盘
    // 服务器
    serverRadioButton = new QRadioButton(QString::fromUtf8("\xe6\x9c\x8d\xe5\x8a\xa1\xe5\x99\xa8"));
    // 客户端
    clientRadioButton = new QRadioButton(QString::fromUtf8("\xe5\xae\xa2\xe6\x88\xb7\xe7\xab\xaf"));
    // 复盘
    replayRadioButton = new QRadioButton(QString::fromUtf8("\xe5\xa4\x8d\xe7\x9b\x98"));
    // 人机对战
    AIRadioButton = new QRadioButton(QString::fromUtf8("\xe4\xba\xba\xe6\x9c\xba\xe5\xaf\xb9\xe6\x88\x98"));
    AIRadioButton->setChecked(true);

    //创建IP地址输入框，默认值为127.0.0.1
    QLatin1String reg("^((?:(?:25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(?:25[0-4]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d))))$");
    ipLineEdit = new QLineEdit;
    QRegExpValidator *validator = new QRegExpValidator(QRegExp(reg), this);
    ipLineEdit->setValidator(validator);
    ipLineEdit->setDisabled(true);
    ipLineEdit->setText(QLatin1String("127.0.0.1"));
    // IP：
    ipLabel = new QLabel(QString::fromUtf8("\x49\x50\xef\xbc\x9a"));
    ipLabel->setBuddy(ipLineEdit);

    //创建端口号输入框，默认值为12345
    portSpinBox = new QSpinBox;
    portSpinBox->setToolTip(QLatin1String("10000~65535"));
    portSpinBox->setRange(10000, 65535);
    portSpinBox->setValue(12345);
    portSpinBox->setDisabled(true);
    // 端口：
    portLabel = new QLabel(QString::fromUtf8("\xe7\xab\xaf\xe5\x8f\xa3\xef\xbc\x9a"));
    portLabel->setBuddy(portSpinBox);

    //创建“确定”按钮
    okPushButton = new QPushButton(QString::fromUtf8("\xe7\xa1\xae\xe5\xae\x9a"));

    //界面布局：选项竖排在左边，输入框在右边，“确定”按钮在右下角
    QHBoxLayout *hBoxLayout1 = new QHBoxLayout;
    hBoxLayout1->addWidget(serverRadioButton);
    hBoxLayout1->addWidget(clientRadioButton);
    hBoxLayout1->addWidget(replayRadioButton);
    hBoxLayout1->addWidget(AIRadioButton);

    QHBoxLayout *hBoxLayout2 = new QHBoxLayout;
    hBoxLayout2->addWidget(ipLabel);
    hBoxLayout2->addWidget(ipLineEdit);
    hBoxLayout2->addWidget(portLabel);
    hBoxLayout2->addWidget(portSpinBox);

    QHBoxLayout *hBoxLayout3 = new QHBoxLayout;
    hBoxLayout3->addStretch();
    hBoxLayout3->addWidget(okPushButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addSpacing(15);
    layout->addLayout(hBoxLayout1);
    layout->addSpacing(15);
    layout->addLayout(hBoxLayout2);
    layout->addSpacing(15);
    layout->addLayout(hBoxLayout3);

    setLayout(layout);

    //创建信号和槽联系
    connect(serverRadioButton, SIGNAL(clicked()), this, SLOT(serverSelected()));
    connect(clientRadioButton, SIGNAL(clicked()), this, SLOT(clientSelected()));
    connect(replayRadioButton, SIGNAL(clicked()), this, SLOT(replaySelected()));
    connect(AIRadioButton, SIGNAL(clicked()), this, SLOT(AISelected()));
    connect(okPushButton, SIGNAL(clicked()), this, SLOT(okPushButtonClicked()));

    //固定界面大小
    setFixedSize(sizeHint());

    //设置界面标题“中国象棋”
    setWindowTitle(QString::fromUtf8("\xe4\xb8\xad\xe5\x9b\xbd\xe8\xb1\xa1\xe6\xa3\x8b"));

    Chess_Trace(tr("build ChessSelectionWidget"));
    Chess_Info(tr("please select chess type and input ip or port"));
}

ChessSelectionWidget::~ChessSelectionWidget()
{
    Chess_Trace(tr("drop ChessSelectionWidget"));
}

void ChessSelectionWidget::serverSelected()
{
    ipLineEdit->setDisabled(true);
    portSpinBox->setEnabled(true);
}

void ChessSelectionWidget::clientSelected()
{
    ipLineEdit->setEnabled(true);
    portSpinBox->setEnabled(true);
}

void ChessSelectionWidget::replaySelected()
{
    ipLineEdit->setDisabled(true);
    portSpinBox->setDisabled(true);
}

void ChessSelectionWidget::AISelected()
{
    ipLineEdit->setDisabled(true);
    portSpinBox->setDisabled(true);
}

void ChessSelectionWidget::okPushButtonClicked()
{
    if(isOK())
    {
        ChessType type = AIType;
        QString stype(tr("ai"));
        if(serverRadioButton->isChecked())
        {
            type = ServerType;
            stype = tr("server");
        }
        else if(clientRadioButton->isChecked())
        {
            type = ClientType;
            stype = tr("client");
        }
        else if(replayRadioButton->isChecked())
        {
            type = ReplayType;
            stype = tr("replay");
        }
        ChessColor color = RedColor;
        QString scolor("red");
        if(ClientType == type)
        {
            color = BlackColor;
            scolor = tr("black");
        }
        Chess_Info(tr("your selection: type=%1 color=%2 ip=%3 port=%4")
                   .arg(stype)
                   .arg(scolor)
                   .arg(ipLineEdit->text())
                   .arg(portSpinBox->value()));
        ChessInformation *ci = ChessInformation::instance();
        ci->init(type, color, ipLineEdit->text(), portSpinBox->value());
        Chess *chess = Chess::instance();
        chess->setAttribute(Qt::WA_DeleteOnClose);  //窗口关闭时自动删除
        this->hide();
        chess->show();
    }
    else
    {
        Chess_Warning(tr("error input, please check!"));
        QMessageBox::warning(this, tr("ERROR INPUT"), tr("ERROR INPUT, PLEASE CHECK!"));
    }
}

bool ChessSelectionWidget::isOK()
{
    if(AIRadioButton->isChecked() || replayRadioButton->isChecked())
    {
        return true;
    }
    else if(clientRadioButton->isChecked())
    {
        return (isIPOK() && isPortOK());
    }
    else if(serverRadioButton->isChecked())
    {
        return isPortOK();
    }
    return false;
}

bool ChessSelectionWidget::isIPOK()
{

    return true;
}

bool ChessSelectionWidget::isPortOK()
{
    int port = portSpinBox->value();
    if((port >= 10000) && (port <= 65535)) return true;
    return false;
}






