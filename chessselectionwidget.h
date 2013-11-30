#ifndef CHESSSELECTIONWIDGET_H
#define CHESSSELECTIONWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QRadioButton;
class QSpinBox;
class QPushButton;
QT_END_NAMESPACE

class Chess;

class ChessSelectionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChessSelectionWidget(QWidget *parent = 0);
    ~ChessSelectionWidget();

signals:

public slots:
    void okPushButtonClicked();
    void serverSelected();
    void clientSelected();
    void replaySelected();
    void AISelected();

private:
    bool isOK();
    bool isIPOK();
    bool isPortOK();

    Chess *chineseChess;         //主界面
    QRadioButton *serverRadioButton;    //服务器选项
    QRadioButton *clientRadioButton;    //客户端选项
    QRadioButton *replayRadioButton;    //复盘选项
    QRadioButton *AIRadioButton;        //人机对战选项
    QLineEdit *ipLineEdit;              //IP地址输入框
    QSpinBox *portSpinBox;              //端口号输入框
    QLabel *ipLabel;                    //IP地址标签
    QLabel *portLabel;                  //端口号标签
    QPushButton *okPushButton;          //确定按钮
};

#endif // CHESSSELECTIONWIDGET_H
