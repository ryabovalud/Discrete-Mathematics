#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString readFile();
    void push(struct stack * , int );
    void del(struct stack * );
    int show_top(struct stack * );
    void print(struct stack *);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_pushButton_INFO_clicked();

    void on_clear_clicked();

    void on_pushButton_PTY_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
