#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <Core/CoffeDiary.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbBegin_clicked();

    void on_pbSendMail_clicked();

private:
    CoffeDiary _coffeDiary;
    Ui::MainWindow *ui;
    void SendStartBtnsVisibility(bool isVisible);
};

#endif // MAINWINDOW_H
