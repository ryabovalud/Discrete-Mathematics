#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_PTY_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
