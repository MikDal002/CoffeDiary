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
	void DisplayAllCoffeeParams(ICoffeeMethod * method);
	void DisplayCurrentCoffeeParams(void);
private slots:
    void on_pbBegin_clicked();

    void on_pbSendMail_clicked();

    void on_cbCoffeMethods_currentIndexChanged(int index);

    void on_rbPlanNewCoffe_clicked();

    void on_rbRecordnewCoffe_clicked();
	void CoffeeRegisteringEnd();

private:
    CoffeDiary _coffeDiary;
    Ui::MainWindow *ui;
    void SendStartBtnsVisibility(bool isVisible);
    void setDescriptionString(void);
};

#endif // MAINWINDOW_H
