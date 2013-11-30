#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>

class Chess : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(Chess)
public:
    static Chess *instance();
    ~Chess();

signals:

public slots:

private:
    static Chess *INSTANCE;
    explicit Chess(QWidget *parent = 0);
};

#endif // CHESS_H
